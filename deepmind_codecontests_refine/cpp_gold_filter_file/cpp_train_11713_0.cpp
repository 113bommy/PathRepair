#include <bits/stdc++.h>
using namespace std;
int sum;
int a[105];
double dp[105 * 1005], dpnew[105 * 1005], ev[105 * 1005];
vector<int> v;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  for (int j = 1; j <= m; ++j)
    if (a[0] != j) v.push_back(j);
  for (int i = 0; i < m - 1; ++i) dp[v[i]] = double(1);
  for (int i = 1; i < n; ++i) {
    double tmp = double(0);
    for (int j = 0; j < sum; ++j) {
      tmp += ev[j];
      dpnew[j] = tmp;
      ev[j + 1] += dp[j];
      ev[j + a[i]] -= dp[j];
      ev[j + a[i] + 1] += dp[j];
      ev[j + m + 1] -= dp[j];
    }
    for (int j = 0; j < sum; ++j) {
      dp[j] = dpnew[j] / (m == 1 ? double(1) : double(m - 1));
    }
    memset(ev, double(0), sizeof ev);
    memset(dpnew, double(0), sizeof dpnew);
  }
  double sol = double(0);
  for (int i = 0; i < sum; ++i) sol += dp[i];
  printf("%.10lf\n", sol + double(1));
  return 0;
}
