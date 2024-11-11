#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
struct re {
  int x, y;
};
re a[4];
int main() {
  for (auto i = 1; i <= 3; i++) cin >> a[i].x >> a[i].y;
  if (((a[1].x == a[2].x) && (a[2].x == a[3].x)) ||
      ((a[1].y == a[2].y) && (a[2].y == a[3].y))) {
    cout << 1;
    return 0;
  }
  if (((a[1].x == a[2].x) && (a[1].y == a[3].y)) ||
      ((a[1].x == a[3].x) && (a[1].y == a[2].y)) ||
      ((a[2].x == a[1].x) && (a[2].y == a[3].y)) ||
      ((a[2].x == a[3].x) && (a[2].y == a[1].y)) ||
      ((a[3].x == a[1].x) && (a[3].y == a[2].y)) ||
      ((a[3].x == a[2].x) && (a[3].y == a[1].y))) {
    cout << 2;
    return 0;
  }
  if (((a[1].x == a[2].x) &&
       ((a[3].y < min(a[1].y, a[2].y) || (a[3].y > max(a[1].y, a[2].y))))) ||
      ((a[1].y == a[2].y) &&
       ((a[3].x < min(a[1].x, a[2].x) || (a[3].x > max(a[1].x, a[2].x))))) ||
      ((a[1].x == a[3].x) &&
       ((a[2].y < min(a[1].y, a[3].y) || (a[2].y > max(a[1].y, a[3].y))))) ||
      ((a[1].y == a[3].y) &&
       ((a[3].x < min(a[1].x, a[3].x) || (a[2].x > max(a[1].x, a[3].x))))) ||
      ((a[3].x == a[2].x) &&
       ((a[1].y < min(a[3].y, a[2].y) || (a[1].y > max(a[3].y, a[2].y))))) ||
      ((a[3].y == a[2].y) &&
       ((a[1].x < min(a[3].x, a[2].x) || (a[1].x > max(a[3].x, a[2].x)))))) {
    cout << 2;
    return 0;
  }
  cout << 3;
  return 0;
}
