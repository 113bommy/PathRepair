#include <bits/stdc++.h>
using namespace std;
long long n, x, y, c;
inline long long get1(long long t) {
  if (t < 0) return 0;
  return (t + 1) * (t + 1);
}
inline long long get2(long long t) {
  if (t < 0) return 0;
  return (t + 1) * (t + 2) / 2;
}
inline bool check(long long t) {
  long long res = (2 * t + 1) + 2 * t * t;
  res -=
      get1(t - x) + get1(t - y) + get1(t - (n + 1 - x)) + get1(t - (n + 1 - y));
  res += get2(t - x - y) + get2(t - x - (n + 1 - y)) +
         get2(t - (n + 1 - x) - y) + get2(t - (n + 1 - x) - (n + 1 - y));
  if (res >= c) return true;
  return false;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x >> y >> c;
  long long l = -1, r = 2 * n;
  while (l < r - 1) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r << '\n';
}
