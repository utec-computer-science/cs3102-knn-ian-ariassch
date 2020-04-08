#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;



template <typename T>
class CartesianCoord{
 public:
    typedef T value_t;
    value_t x;
    value_t y;
    CartesianCoord(value_t _x = 0, value_t _y = 0)
    :x(_x),y(_y){
 }
   ~CartesianCoord(void)
   {

   }
  template<typename _T>
  friend ostream& operator<<(ostream &out, const CartesianCoord<_T> c){
  out << "(" << c.x << "," << c.y << ")";
  return out;
  }
};

typedef CartesianCoord<int> coord_t;

float distance(coord_t a, coord_t b)
{
  return abs((sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))));
}

bool secondsort(const pair<coord_t,float> &a,
              const pair<coord_t,float> &b)
{
    return (a.second < b.second);
}

vector<coord_t> knn ( int k, vector<coord_t> &points, const coord_t &q)
{
  vector<pair<coord_t, float>> distances;
  vector<coord_t> result;
  for (auto it = points.begin(); it != points.end(); it++) {
    distances.push_back(make_pair((*it), distance(q, *it)));
    sort(distances.begin(), distances.end(), secondsort);
  }
  for (int i = 0; i < k; i++) {
    result.push_back(distances[i].first);
  }
  return result;


 return vector<coord_t>();
}
int main() {
 srand(time(NULL));

 vector<coord_t> points;
 for(int i=0; i< 1000; i++)
 points.push_back(coord_t(rand()%1000,rand()%1000));

 vector<coord_t>::iterator it = points.begin();
 vector<coord_t> knns;
 auto start = std::chrono::high_resolution_clock::now();
 knns = knn(3, points, coord_t(100,200));
 auto stop = std::chrono::high_resolution_clock::now();
 auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
 cout << "Time: " << endl;
 cout << duration.count() << endl;
 cout << "knns" << endl;
 vector<coord_t>::iterator kit = knns.begin();
 for (; kit != knns.end(); kit++)
 cout << *kit << endl;
}
