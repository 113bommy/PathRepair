#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
struct pt {
  long long x, y;
  friend bool operator<(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  }
} a[100005];
long long x[100005];
long long f[100005];
int main(void) {
  long long n;
  cin >> n;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    cin >> a[i].x >> a[i].y;
  }
  long long v;
  cin >> v;
  bool flag = 1;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    long long p = a[i].x;
    a[i].x = p + a[i].y * v;
    a[i].y = p - a[i].y * v;
    if (!a[i].x && !a[i].y) flag = 0;
  }
  sort(a, a + n);
  for (long long(i) = 0; (i) < (long long)(n); (i)++)
    x[i] = a[i].y, f[i + 1] = inf;
  f[0] = -inf;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    long long y = upper_bound(f, f + n, x[i]) - f;
    if (f[y - 1] <= x[i] && f[y] >= x[i]) f[y] = x[i];
  }
  long long ansx = 0, ansy = 0;
  for (long long(i) = 0; (i) < (long long)(n + 1); (i)++)
    if (f[i] != inf) ansy = i;
  if (flag) a[n].x = 0, a[n].y = 0, n++;
  sort(a, a + n);
  for (long long(i) = 0; (i) < (long long)(n); (i)++)
    x[i] = a[i].y, f[i + 1] = inf;
  f[0] = -inf;
  long long start = 0;
  for (long long(i) = 0; (i) < (long long)(n); (i)++)
    if (!a[i].x && !a[i].y) {
      start = i;
      break;
    }
  for (long long i = 0; i < n; i++) {
    if (a[i].x < 0 || a[i].y < 0) continue;
    long long y = upper_bound(f, f + n, x[i]) - f;
    if (f[y - 1] <= x[i] && f[y] >= x[i]) f[y] = x[i];
  }
  for (long long(i) = 0; (i) < (long long)(n + 1); (i)++)
    if (f[i] != inf) ansx = i;
  cout << ansx - flag << " " << ansy << endl;
  return 0;
}
