#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, cases, k = 1;
  int x, y;
  cin >> x >> y;
  int t1 = 1;
  if ((x == 0 && y == 0) || (x == 1 && y == 0)) {
    cout << 0;
    return 0;
  }
  int limit;
  if (x == y)
    limit = abs(x);
  else {
    int ax = abs(x);
    int ay = abs(y);
    if (ax < ay)
      limit = ay;
    else
      limit = ax;
  }
  if (x > 0 && y < 0 && abs(y) < abs(x)) {
    limit--;
  }
  for (i = 1; i < limit; i++) {
    t1 += 4;
  }
  if (x > 0 && y >= 0) {
    if (y < x) t1--;
    if (x == y) t1--;
  }
  if (x < 0 && y >= 0) {
    if (abs(x) > abs(y)) t1++;
  }
  if (x <= 0 && y < 0) {
    t1++;
    if (abs(x) < abs(y)) t1++;
  }
  if (x > 0 && y < 0) {
    t1 += 2;
    if (abs(y) < abs(x)) t1++;
    if (abs(y) + 1 == x) t1--;
  }
  cout << t1 + 1;
  printf("\n");
  return 0;
}
