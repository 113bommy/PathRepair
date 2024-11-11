#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, a, b;
inline long long gcd(long long x, long long y) {
  long long t;
  while (y) t = x, x = y, y = t % y;
  return x;
}
inline bool check(long long T) {
  return a * T <= n && b * T <= m;
  long long xx = x - a * T;
  long long yy = y - b * T;
  if (xx < 0) xx = 0;
  if (yy < 0) yy = 0;
  if (xx + T * a <= n && yy + T * b <= m) return true;
  xx = x + a * T;
  yy = y + b * T;
  if (xx > n) xx = n;
  if (yy > m) yy = m;
  if (xx - T * a >= 0 && yy - T * b >= 0) return true;
  return false;
}
inline void print(long long ans) {
  long long xx = x - (a * ans + 1) / 2;
  long long yy = y - (b * ans + 1) / 2;
  if (xx < 0) xx = 0;
  if (yy < 0) yy = 0;
  if (xx + ans * a > n) xx = n - a * ans;
  if (yy + ans * b > m) yy = m - b * ans;
  cout << xx << ' ' << yy << ' ' << xx + ans * a << ' ' << yy + ans * b << endl;
}
int main() {
  cin >> n >> m >> x >> y >> a >> b;
  long long c = gcd(a, b);
  a /= c;
  b /= c;
  long long l = 0, r = 1000000000LL;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  print(r);
  return 0;
}
