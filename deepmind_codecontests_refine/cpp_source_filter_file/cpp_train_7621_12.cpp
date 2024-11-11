#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
const int maxn = 3e5 + 7;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
int n;
long long dp[51][101];
int l[51], r[51], a[101];
int qpow(long long a, int k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * a % mod;
    a = a * a % mod, k >>= 1;
  }
  return res;
}
long long cal(int n, int m) {
  long long res = 1;
  for (int i = 1; i <= n; ++i) {
    res = res * (n + m - i) % mod * qpow(i, mod - 2) % mod;
  }
  return res;
}
int main() {
  n = read();
  long long all = 1;
  int nn = 0;
  for (int i = 1; i <= n; ++i) {
    l[i] = read(), r[i] = read();
    a[++nn] = l[i], a[++nn] = ++r[i];
    all = all * (r[i] - l[i]) % mod;
  }
  sort(a + 1, a + 1 + nn);
  nn = unique(a + 1, a + 1 + nn) - a - 1;
  for (int i = 1; i <= n; ++i) {
    l[i] = lower_bound(a + 1, a + 1 + nn, l[i]) - a;
    r[i] = lower_bound(a + 1, a + 1 + nn, r[i]) - a;
  }
  for (int i = 1; i <= nn; ++i) dp[0][i] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = l[i]; j < r[i]; ++j) {
      for (int k = i - 1; i >= 0; --k) {
        dp[i][j] =
            (dp[i][j] + dp[k][j + 1] * cal(i - k, a[j + 1] - a[j])) % mod;
        if (l[k] > j || r[k] <= j) break;
      }
    }
    for (int j = nn; j; --j) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
  }
  printf("%lld\n", dp[n][1] * qpow(all, mod - 2) % mod);
}
