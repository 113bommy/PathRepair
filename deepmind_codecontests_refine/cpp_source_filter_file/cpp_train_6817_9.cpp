#include <bits/stdc++.h>
double dp[110][110][110];
double dfs(int r, int s, int p) {
  if (dp[r][s][p]) return dp[r][s][p];
  if (p == 0) return 1;
  if (s * r == 0) return 0;
  int sum = r * s + r * p + s * p;
  return dp[r][s][p] = 1.0 * r * s / sum * dfs(r, s - 1, p) +
                       1.0 * r * p / sum * dfs(r - 1, s, p) +
                       1.0 * s * p / sum * dfs(r, s, p - 1);
}
int main() {
  int r, s, p;
  scanf("%d%d%d", &r, &s, &p);
  printf("%.9f %.9f %.9f\n", dfs(r, s, p), dfs(s, p, r), dfs(r, p, s));
  return 0;
}
