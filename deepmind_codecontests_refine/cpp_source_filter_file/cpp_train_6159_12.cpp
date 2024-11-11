#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) {
  if (a == 0 || b == 0) return a + b;
  return a * (b / gcd(a, b));
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
char c[1002], s[52], t[52];
int spi[52], tpi[52];
int n, m, k;
int d[1000][50][50];
int go(int N, int M, int K) {
  if (N == n) return 0;
  int &ret = d[N][M][K];
  if (ret != -1987654321 - 5) return ret;
  ret = -1987654321;
  if (c[N] == '*') {
    for (int(i) = ('a'); (i) <= ('z'); (i) += (1)) {
      int tm = M, tk = K, cc = 0;
      while (tm > 0 && i != s[tm]) tm = spi[tm - 1];
      while (tk > 0 && i != t[tk]) tk = tpi[tk - 1];
      if (i == s[tm]) {
        if (tm == m - 1) {
          cc++;
          tm = spi[tm];
        } else
          tm++;
      }
      if (i == t[tk]) {
        if (tk == k - 1) {
          cc--;
          tk = tpi[tk];
        } else
          tk++;
      }
      ret = max(ret, cc + go(N + 1, tm, tk));
    }
  } else {
    int tm = M, tk = K, cc = 0;
    while (tm > 0 && c[N] != s[tm]) tm = spi[tm - 1];
    while (tk > 0 && c[N] != t[tk]) tk = tpi[tk - 1];
    if (s[N] == s[tm]) {
      if (tm == m - 1) {
        cc++;
        tm = spi[tm];
      } else
        tm++;
    }
    if (s[N] == t[tk]) {
      if (tk == k - 1) {
        cc--;
        tk = tpi[tk];
      } else
        tk++;
    }
    ret = max(ret, cc + go(N + 1, tm, tk));
  }
  return ret;
}
int main() {
  scanf("%s%s%s", c, s, t);
  n = strlen(c), m = strlen(s), k = strlen(t);
  for (int(i) = (0); (i) <= (n - 1); (i) += (1))
    for (int(j) = (0); (j) <= (m - 1); (j) += (1))
      for (int(kk) = (0); (kk) <= (k - 1); (kk) += (1))
        d[i][j][kk] = -1987654321 - 5;
  for (int i = 1, j = 0; i < m; i++) {
    while (j > 0 && s[i] != s[j]) j = spi[j - 1];
    if (s[i] == s[j]) spi[i] = ++j;
  }
  for (int i = 1, j = 0; i < k; i++) {
    while (j > 0 && t[i] != t[j]) j = tpi[j - 1];
    if (t[i] == t[j]) tpi[i] = ++j;
  }
  printf("%d", go(0, 0, 0));
}
