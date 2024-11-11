#include <bits/stdc++.h>
using namespace std;
struct pi {
  int x, y, t;
  double p;
} pp[1005];
double dp[1005];
int cmp(pi a, pi b) { return a.t < b.t; }
double get(int a, int b) {
  return sqrt(pow(pp[a].x - pp[b].x, 2.0) + pow(pp[a].y - pp[b].y, 2.0));
}
int main() {
  int i, j, n;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d%lf", &pp[i].x, &pp[i].y, &pp[i].t, &pp[i].p);
  }
  sort(pp + 1, pp + 1 + n, cmp);
  dp[1] = pp[1].p;
  for (i = 2; i <= n; i++) {
    dp[i] = pp[i].p;
    for (j = 1; j < i; j++) {
      if (get(j, i) <= pp[i].t - pp[j].t) {
        dp[i] = max(dp[i], dp[j] + pp[i].p);
      }
    }
  }
  double s = 0;
  for (i = 1; i <= n; i++) s = max(s, dp[i]);
  printf("%.9lf\n", s);
}
