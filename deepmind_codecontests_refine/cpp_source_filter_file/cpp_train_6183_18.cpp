#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int OO = INT_MAX;
int main() {
  double largeDisatance, smallDistance, speed, green, red;
  cin >> largeDisatance >> smallDistance >> speed >> green >> red;
  double t = smallDistance / speed;
  double tm = fmod(t, green + red);
  if (tm >= green) {
    t += green + red - t;
  }
  t += (largeDisatance - smallDistance) / speed;
  printf("%.9lf\n", t);
  return 0;
}
