#include <bits/stdc++.h>
using namespace std;
const unsigned _mod = 998244353;
const unsigned mod = 1e9 + 7;
const long long infi = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long ksm(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x % mod;
    y >>= 1ll;
    x = x * x % mod;
  }
  return ret;
}
long long qpow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x;
    y >>= 1ll;
    x = x * x;
  }
  return ret;
}
long long _gcd(long long x, long long y) { return y ? _gcd(y, x % y) : x; }
long long dx[5] = {0, 1, 0, -1, 0}, dy[5] = {0, 0, 1, 0, -1}, n, b, q,
          a[1010][1010], x[5100010][2], ans[1200010], t[1200010], x1,
          suibiandefineyixiajiuhaole, x2, y2, d, h;
char ch;
long long hash1(long long x, long long y, long long d) {
  if (a[x][y]) d = a[x][y];
  return d * 1001 * 1001 + x * 1001 + y;
}
int main() {
  cin >> n >> b;
  for (int i = 1; i <= n; ++i) {
    x1 = read(), suibiandefineyixiajiuhaole = read(), x2 = read(), y2 = read();
    if (x1 == x2)
      d = 2 + (suibiandefineyixiajiuhaole > y2) * 2;
    else
      d = 1 + (x1 > x2) * 2;
    while (x1 != x2 || suibiandefineyixiajiuhaole != y2)
      a[x1][suibiandefineyixiajiuhaole] = d, x1 += dx[d],
      suibiandefineyixiajiuhaole += dy[d];
    a[x2][y2] = d;
  }
  for (register int i = 0; i <= b; ++i)
    for (register int j = 0; j <= b; ++j)
      for (register int k = 1; k <= 4; ++k)
        if (!a[i][j] || a[i][j] == k) {
          h = hash1(i, j, k);
          x1 = i + dx[k];
          suibiandefineyixiajiuhaole = j + dy[k];
          if (x1 < 0 || x1 > b || suibiandefineyixiajiuhaole < 0 ||
              suibiandefineyixiajiuhaole > b)
            x[h][0] = h;
          else
            x[h][0] = hash1(x1, suibiandefineyixiajiuhaole, k);
        }
  cin >> q;
  for (register int i = 1; i <= q; ++i) {
    x1 = read(), x2 = read();
    cin >> ch;
    t[i] = read();
    if (ch == 'R') d = 1;
    if (ch == 'U') d = 2;
    if (ch == 'L') d = 3;
    if (ch == 'D') d = 4;
    ans[i] = hash1(x1, x2, d);
  }
  for (register int i = 0; i <= 60; ++i) {
    h = i & 1;
    for (register int j = 1; j <= q; ++j)
      if (t[j] & (1 << i)) ans[j] = x[ans[j]][h];
    for (register int j = 1; j <= 5100000; ++j) x[j][h ^ 1] = x[x[j][h]][h];
  }
  for (register int i = 1; i <= q; ++i) {
    suibiandefineyixiajiuhaole = ans[i] % 1001;
    x1 = (ans[i] / 1001) % 1001;
    cout << x1 << ' ' << suibiandefineyixiajiuhaole << '\n';
  }
  return 0;
}
