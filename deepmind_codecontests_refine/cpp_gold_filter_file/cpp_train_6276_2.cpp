#include <bits/stdc++.h>
using namespace std;
struct circle {
  long long x;
  long long y;
  long long r;
};
bool check(long long x, long long y, circle *c, long long n) {
  for (long long i = 0; i < n; ++i) {
    long long distance =
        (((c[i].x - x) * (c[i].x - x)) + ((c[i].y - y) * (c[i].y - y)));
    if (distance <= (c[i].r * c[i].r)) {
      return true;
    }
  }
  return false;
}
int32_t main() {
  long long xa, xb, ya, yb;
  cin >> xa >> ya >> xb >> yb;
  long long n;
  cin >> n;
  circle c[n];
  for (long long i = 0; i < n; ++i) {
    cin >> c[i].x >> c[i].y >> c[i].r;
  }
  long long sx = min(xa, xb);
  long long sy = min(ya, yb);
  long long h = max(ya, yb) - sy;
  long long l = max(xa, xb) - sx;
  long long cnt = 0;
  for (long long i = sx; i <= sx + l; ++i) {
    long long x = i;
    long long y = sy;
    if (check(x, y, c, n) == false) {
      cnt++;
    }
  }
  for (long long i = sy + 1; i <= sy + h; ++i) {
    long long x = sx + l;
    long long y = i;
    if (check(x, y, c, n) == false) {
      cnt++;
    }
  }
  for (long long i = sx + l - 1; i >= sx; --i) {
    long long x = i;
    long long y = sy + h;
    if (check(x, y, c, n) == false) {
      cnt++;
    }
  }
  for (long long i = sy + h - 1; i >= sy + 1; --i) {
    long long x = sx;
    long long y = i;
    if (check(x, y, c, n) == false) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
