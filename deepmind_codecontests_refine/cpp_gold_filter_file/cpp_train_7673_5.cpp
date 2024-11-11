#include <bits/stdc++.h>
using namespace std;
struct Node {
  int pow, num;
};
const double INF = 1e12;
double dp[55][55][55];
Node a[55];
double val[55];
int n;
bool check(double x) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  for (int i = 1; i <= n; i++) val[i] = 1.0 * a[i].pow - x * a[i].num;
  dp[1][0][1] = val[1];
  for (int i = 2; i <= n; i++) {
    if (a[i].pow < a[i - 1].pow) {
      for (int j = 0; j <= i - 1; j++) {
        for (int k = 1; k <= i - j - 1; k++) {
          dp[i - 1][j + k][0] = min(dp[i - 1][j + k][0], dp[i - 1][j][k]);
          dp[i - 1][j][k] = INF;
        }
      }
    }
    for (int j = 0; j <= i - 1; j++) {
      for (int k = 0; k <= i - j - 1; k++) {
        if (dp[i - 1][j][k] < INF)
          dp[i][j][k + 1] = min(dp[i][j][k + 1], dp[i - 1][j][k] + val[i]);
      }
    }
    for (int j = 1; j <= i - 1; j++) {
      for (int k = 0; k <= i - j - 1; k++) {
        dp[i][j - 1][k] = min(dp[i][j - 1][k], dp[i - 1][j][k]);
      }
    }
  }
  double ret = INF;
  for (int j = 0; j <= n; j++) {
    for (int k = 0; k <= n; k++) {
      ret = min(ret, dp[n][j][k]);
    }
  }
  return ret <= 0;
}
bool cmp(const Node& p, const Node& q) { return p.pow > q.pow; }
int main() {
  int flag;
  double l, r, mid;
  long long ans;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].pow);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].num);
  sort(a + 1, a + n + 1, cmp);
  l = 0;
  r = 1e9;
  for (int i = 1; i <= 100; i++) {
    mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  ans = (ceil)(l * 1000);
  printf("%I64d\n", ans);
  return 0;
}
