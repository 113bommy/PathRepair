#include <bits/stdc++.h>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
template <class T>
inline T IN(T& num) {
  num = 0;
  char c = getchar(), f = 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') f = 1, c = getchar();
  while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
  if (f) num = -num;
  return num;
}
const int NUM = 1000010;
long long mod = 1000000007;
long long n, m, l, k, rem, cnt;
int a[NUM], b[NUM];
long long dp[2][NUM];
int main() {
  IN(n), IN(l), IN(k);
  for (int i = 0; i < n; ++i) b[i] = IN(a[i]);
  sort(b, b + n);
  m = unique(b, b + n) - b;
  for (int i = 0; i < n; ++i) a[i] = lower_bound(b, b + m, a[i]) - b;
  int now = 0, last = 1;
  long long ans = l % mod;
  rem = l % n;
  cnt = l / n;
  for (int i = 0; i < n; ++i) ++dp[now][a[i]];
  for (int i = 0; i < m; ++i)
    if ((dp[now][i + 1] += (dp[now][i])) >= mod) dp[now][i + 1] -= mod;
  ;
  for (int i = 1; i < k; ++i) {
    swap(now, last);
    for (int j = 0; j <= m; ++j) dp[now][j] = 0;
    for (int j = 0; j < rem; ++j)
      if ((dp[now][a[j]] += (dp[last][a[j]])) >= mod) dp[now][a[j]] -= mod;
    ;
    if (cnt >= i)
      for (int j = 0; j < m; ++j)
        if ((ans += (dp[now][j])) >= mod) ans -= mod;
    ;
    for (int j = rem; j < n; ++j)
      if ((dp[now][a[j]] += (dp[last][a[j]])) >= mod) dp[now][a[j]] -= mod;
    ;
    for (int j = 0; j < m; ++j)
      if ((dp[now][j + 1] += (dp[now][j])) >= mod) dp[now][j + 1] -= mod;
    ;
    if (cnt > i)
      if ((ans += ((cnt - i) % mod * dp[now][m] % mod)) >= mod) ans -= mod;
    ;
  }
  printf("%I64d\n", ans);
  return 0;
}
