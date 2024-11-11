#include <bits/stdc++.h>
using namespace std;
int n, m;
char st[55][25];
int f[1100005], dx[1100005];
long long ms[1100005];
double dp[1100005], cf[1100005];
int main() {
  int i, j, k, sum, s;
  double ans = 0, t;
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%s", st[i]);
  m = strlen(st[1]);
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) {
      sum = 0;
      for (k = 0; k < m; k++)
        if (st[i][k] == st[j][k]) sum |= (1 << k);
      ms[sum] |= (1 << i - 1) | (1 << j - 1);
    }
  for (s = (1 << m) - 1; s >= 0; s--) {
    f[s] = n;
    for (k = 0; k < m; k++)
      if (s & (1 << k)) dx[s]++;
    for (i = 1; i <= n; i++)
      if (ms[s] & (1ll << i - 1)) f[s]--;
    for (k = 0; k < m; k++)
      if (s & (1 << k)) ms[s ^ (1 << k)] |= ms[s];
  }
  dp[0] = 1;
  for (s = 0; s < (1 << m); s++) {
    ans += cf[s] * dx[s];
    if (f[s] == n) continue;
    t = dp[s] / (m - dx[s]) / (n - f[s]);
    for (k = 0; k < m; k++)
      if (!(s & (1 << k))) {
        dp[s | (1 << k)] += t * (n - f[s | (1 << k)]);
        cf[s | (1 << k)] += t * (f[s | (1 << k)] - f[s]);
      }
  }
  printf("%.12f\n", ans);
  return 0;
}
