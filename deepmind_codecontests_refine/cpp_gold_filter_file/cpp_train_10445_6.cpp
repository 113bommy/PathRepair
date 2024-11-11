#include <bits/stdc++.h>
using namespace std;
inline int next_int() {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  int r = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') r = r * 10 + c - '0';
  return r;
}
struct node {
  double p;
  int a;
} tour[205];
int n, l, k;
double dp[205][205][205];
bool cmp(node a, node b) { return a.a > b.a; }
int main() {
  scanf("%d%d%d", &n, &l, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &tour[i].p);
    tour[i].p /= 100;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &tour[i].a);
  }
  sort(tour + 1, tour + n + 1, cmp);
  dp[0][0][min(k, n)] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int m = 0; m <= n; ++m) {
        dp[i][j][m] += (1.0 - tour[i].p) * dp[i - 1][j][m];
        if (m + tour[i].a < 0) continue;
        dp[i][j + 1][min(m + tour[i].a, n)] += tour[i].p * dp[i - 1][j][m];
      }
    }
  }
  double ans = 0;
  for (int j = l; j <= n; ++j) {
    for (int m = 0; m <= n; ++m) {
      ans += dp[n][j][m];
    }
  }
  printf("%.12lf", ans);
  return 0;
}
