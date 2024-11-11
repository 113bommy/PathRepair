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
  }
  for (i = 0; i < n; i++) {
    addx += 4 * point[i].x * point[i].x - sumx * point[i].x;
    addy += 4 * point[i].y * point[i].y - sumy * point[i].y;
  }
  addx += addy;
  cout << addx << endl;
  return 0;
}
