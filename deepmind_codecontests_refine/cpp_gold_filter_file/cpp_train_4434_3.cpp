#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x;
  long long y;
} point[100000];
int main() {
  int i;
  long long n, sumx = 0, sumy = 0, addx = 0, addy = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> point[i].x >> point[i].y;
    sumx += point[i].x;
    sumy += point[i].y;
    addx += (point[i].x * point[i].x);
    addy += (point[i].y * point[i].y);
  }
  addx += addy;
  addx *= n;
  addx -= (sumx * sumx);
  addx -= (sumy * sumy);
  cout << addx << endl;
  return 0;
}
