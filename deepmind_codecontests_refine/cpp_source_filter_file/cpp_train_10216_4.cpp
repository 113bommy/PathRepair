#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 7;
const int maxn = 1e6 + 700;
const int mod = 998244353;
const double eps = 1e-9;
const double PI = acos(-1);
template <typename T>
inline void read(T &a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
long long n, m, p;
int dp[100005][105];
int sp[100005];
int sum[100005][105];
int a[100005];
int main() {
  read(n);
  read(m);
  read(p);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= m + 1; k++) sum[i][k] = sum[i - 1][k];
    sum[i][(a[i] == -1 ? m + 1 : a[i])]++;
  }
  sp[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) {
      for (int k = 1; k <= m; k++) {
        dp[i][k] = sp[i - 1];
        if (i < p) continue;
        if (sum[i][k] - sum[i - p][k] + sum[i][m + 1] - sum[i - p][m + 1] == p)
          dp[i][k] = (dp[i][k] - sp[i - p] % mod + mod + dp[i - p][k]) % mod;
      }
    } else {
      for (int k = a[i]; k <= a[i]; k++) {
        dp[i][k] = sp[i - 1];
        if (i < p) continue;
        if (sum[i][k] - sum[i - p][k] + sum[i][m + 1] - sum[i - p][m + 1] == p)
          dp[i][k] = (dp[i][k] - sp[i - p] % mod + mod + dp[i - p][k]) % mod;
      }
    }
    for (int k = 1; k <= m; k++) sp[i] = (sp[i] + dp[i][k]) % mod;
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) ans = (ans + dp[n][i]) % mod;
  printf("%lld\n", ans);
  ;
  return 0;
}
