#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline void read(int &x) {
  x = 0;
  int p = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') p = -p;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();
  x = x * p;
}
int st[305], top, tt[305], n, c[1005][1005], dp[1005][1005], fact[1005],
    inv[1005];
void add(int &x, int y) { x + y >= mod ? x = x + y - mod : x += y; }
int qpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
    y >>= 1;
  }
  return res;
}
int main() {
  c[0][0] = 1;
  fact[0] = 1;
  for (int i = 1; i <= 1000; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      if (c[i][j] >= mod) c[i][j] -= mod;
    }
  }
  inv[1000] = qpow(fact[1000], mod - 2);
  for (int i = 999; i >= 0; --i) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
  read(n);
  for (int i = 1; i <= n; ++i) {
    int x;
    read(x);
    int y = 1;
    int q = sqrt(x);
    for (int j = 2; j <= q; ++j) {
      int now = 0;
      while (x % j == 0) {
        x /= j;
        now ^= 1;
      }
      if (now) y = y * now;
    }
    y = 1LL * y * x % mod;
    int flag = 0;
    for (int j = 1; j <= top; ++j) {
      if (st[j] == y) {
        tt[j]++;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      st[++top] = y;
      tt[top] = 1;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= top; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= min(tt[i], j); ++k) {
        add(dp[i][j], 1LL * dp[i - 1][j - k] * ((tt[i] - k) & 1 ? mod - 1 : 1) %
                          mod * fact[tt[i]] % mod * c[tt[i] - 1][k - 1] % mod *
                          inv[k] % mod);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) add(ans, 1LL * dp[top][i] * fact[i] % mod);
  cout << ans << endl;
}
