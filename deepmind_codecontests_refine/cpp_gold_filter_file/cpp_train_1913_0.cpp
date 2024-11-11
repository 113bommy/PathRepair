#include <bits/stdc++.h>
using namespace std;
int INP, AM, REACHEOF;
char BUF[(1 << 12) + 1], *inp = BUF;
const long double PI = acos((long double)-1.0);
long long n, x, y, need;
long long tri(long long n) {
  if (n <= 0) return 0;
  return n * (n + 1LL) / 2;
}
long long get(long long t, long long x, long long y) {
  return tri(t - (t - x) - (t - y));
}
bool check(long long t) {
  long long low = x - t;
  long long high = x + t;
  long long left = y - t;
  long long right = y + t;
  if (low < 1) low = 1;
  if (high > n) high = n;
  if (left < 1) left = 1;
  if (right > n) right = n;
  long long can = (right - left + 1LL) * (high - low + 1LL);
  can -= get(t, x - low, y - left);
  can -= get(t, x - low, right - y);
  can -= get(t, high - x, y - left);
  can -= get(t, high - x, right - y);
  return can >= need;
}
int main() {
  while (cin >> n >> x >> y >> need) {
    long long l = 0, r = n + n, res = r;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (check(mid)) {
        res = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    cout << res << endl;
  }
  return 0;
}
