#include <bits/stdc++.h>
const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const long long linf = (long long)1e18 + 7;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
using namespace std;
long long n, k, a, b;
long long z;
long long md(long long x) {
  x %= z;
  if (x < 0) x += z;
  return x;
}
long long dist(long long x, long long y) {
  if (x > y) swap(x, y);
  return min(y - x, z - y + x);
}
long long cl(long long x) {
  long long res = linf;
  long long first = (x / k) * k;
  res = min(res, dist(first, x));
  long long second = (first + k) % z;
  res = min(res, dist(second, x));
  return res;
}
long long x = inf, y = -inf;
bool check(long long second, long long l) {
  second %= z;
  if (cl(second) != a) return 0;
  if (cl(md(second + l)) == b || cl(md(second - l)) == b) return 1;
  return 0;
}
long long gcd(long long x, long long y) {
  while (y) {
    x %= y;
    swap(x, y);
  }
  return x + y;
}
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
int main() {
  cin >> n >> k >> a >> b;
  z = n * k;
  for (int i = (0); i <= (n - 1); i++) {
    {
      long long v = k * i;
      long long p2 = md(v - b);
      long long len = 0;
      if (a <= p2)
        len = p2 - a;
      else
        len = z - a + p2;
      if (!len) len = z;
      if (cl(a) == a && cl(p2) == b) {
        long long cnt = z / (gcd(len, z));
        x = min(x, cnt);
        y = max(y, cnt);
      }
    }
    {
      long long v = k * i;
      long long p2 = md(v + b);
      long long len = 0;
      if (a <= p2)
        len = p2 - a;
      else
        len = z - a + p2;
      if (!len) len = z;
      if (cl(a) == a && cl(p2) == b) {
        long long cnt = z / (gcd(len, z));
        x = min(x, cnt);
        y = max(y, cnt);
      }
    }
  }
  cout << x << ' ' << y;
  exit(0);
}
