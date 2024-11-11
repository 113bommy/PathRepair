#include <bits/stdc++.h>
long long q_pow(long long x, long long n, long long mod) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = x * ret % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
long long __gcd(long long x, long long y) {
  if (!y) return x;
  return __gcd(y, x % y);
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
using namespace std;
const long long INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 100 + 5;
long long num[maxn];
long long n, a, r, m;
long long check(long long x) {
  long long up = 0, down = 0;
  for (int i = 1; i <= n; i++)
    if (num[i] > x)
      down += num[i] - x;
    else
      up += x - num[i];
  if (a + r > m) {
    long long tmp = min(up, down);
    return tmp * m + (up - tmp) * a + (down - tmp) * r;
  }
  return a * up + r * down;
}
signed main(int argc, char *argv[]) {
  if (argc == 2 && strcmp("-debug", argv[1]) == 0) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }
  cin >> n >> a >> r >> m;
  for (int i = 1; i <= n; i++) scanf("%lld", &num[i]);
  long long le = 0, ri = 1e9;
  while (le + 1 < ri) {
    long long mid = (le + ri) / 2;
    long long lmid = le + (ri - le) / 3;
    long long rmid = ri - (ri - le) / 3;
    if (check(mid - 1) <= check(mid + 1))
      ri = mid;
    else
      le = mid;
  }
  cout << min(check(ri), check(ri)) << endl;
  return 0;
}
