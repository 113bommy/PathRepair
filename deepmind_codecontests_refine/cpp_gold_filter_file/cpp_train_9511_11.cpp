#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> tt;
vector<int> v[1005];
bool cmp(int x, int y) { return x > y; }
double dp[1005][1005], C[1005][1005];
int main() {
  scanf("%d%d", &n, &m);
  C[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    int ge = 0;
    scanf("%d", &ge);
    for (int j = 1; j <= ge; j++) {
      int x;
      scanf("%d", &x);
      tt.push_back(x);
      v[i].push_back(x);
    }
  }
  sort(tt.begin(), tt.end(), cmp);
  int val = tt[n - 1];
  int S = n, T = 0;
  for (int i = 0; i < tt.size(); i++) {
    if (tt[i] > val) S--;
    if (tt[i] == val) T++;
  }
  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    bool is = false;
    int ge = 0;
    for (int j = 0; j < (int)v[i + 1].size(); j++)
      if (v[i + 1][j] == val)
        is = true;
      else if (v[i + 1][j] > val)
        ge++;
    for (int j = 0; j <= S; j++) {
      if (dp[i][j] == 0) continue;
      if (!is) {
        dp[i + 1][j] += dp[i][j] / C[v[i + 1].size()][ge];
      } else {
        dp[i + 1][j] += dp[i][j] / C[v[i + 1].size()][ge];
        dp[i + 1][j + 1] += dp[i][j] / C[v[i + 1].size()][ge + 1];
      }
    }
  }
  double ans = dp[m][S] / C[T][S];
  printf("%.10lf\n", ans);
  return 0;
}
