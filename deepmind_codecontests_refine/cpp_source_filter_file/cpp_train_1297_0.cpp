#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 333;
const long long linf = 1e18 + 333;
const int N = 50;
const int M = 21;
int n, m, cnt[1 << M];
long long w[1 << M];
double dp[1 << M];
char s[N][M];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  m = strlen(s[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      long long mask = 0;
      for (int k = 0; k < m; k++) mask |= (s[i][k] == s[j][k]) << k;
      w[mask] |= 1LL << i | 1LL << j;
    }
  }
  for (int i = (1 << m) - 1; i >= 0; i--)
    for (int j = 0; j < m; j++)
      if (i & 1 << j) w[i ^ 1 << j] |= w[i];
  for (int i = 0; i < (1 << m); i++) cnt[i] = __builtin_popcount(w[i]);
  for (int i = (1 << m) - 1; i >= 0; i--) {
    if (!cnt[i]) continue;
    double sum = 0;
    for (int j = 0; j < m; j++)
      if (~i & 1 << j) sum += dp[i | 1 << j] * cnt[i | 1 << j];
    dp[i] = 1 + sum / (m - __builtin_popcount(i)) / cnt[i];
  }
  printf("%.18lf\n", dp[0]);
  return 0;
}
