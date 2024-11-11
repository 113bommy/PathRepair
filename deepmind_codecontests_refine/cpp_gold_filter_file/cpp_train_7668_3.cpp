#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> task[51];
double dp[51][51][51];
double mid;
double g(int cur, int pick, int sm) {
  if (pick < 0) return INFINITY;
  if (cur == n) return 0;
  double &res = dp[cur][pick][sm];
  if (res != -INFINITY) return res;
  if (cur > 0 && task[cur - 1].first > task[cur].first) pick += sm, sm = 0;
  res =
      min(g(cur + 1, pick, sm + 1) + (task[cur].first - mid * task[cur].second),
          g(cur + 1, pick - 1, sm));
  return res;
}
double first() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) dp[i][j][k] = -INFINITY;
  return g(0, 0, 0);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &task[i].first);
  for (int i = 0; i < n; i++) scanf("%d", &task[i].second);
  sort(task, task + n);
  reverse(task, task + n);
  double hi = 1e8, lo = 0;
  for (int i = 0; i < 100; i++) {
    mid = (hi + lo) / 2;
    if (first() <= 0)
      hi = mid;
    else
      lo = mid;
  }
  printf("%.0lf\n", ceil(lo * 1000));
}
