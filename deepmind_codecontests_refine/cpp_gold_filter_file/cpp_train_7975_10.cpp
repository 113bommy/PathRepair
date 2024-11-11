#include <bits/stdc++.h>
using namespace std;
struct item {
  int t, d, p, pos;
};
item ti[109];
int dp[109][2009];
pair<int, int> pop[109][2009];
bool comp(item a, item b) { return a.d < b.d; }
int main() {
  int n;
  pair<int, int> ak, p;
  vector<int> wyn;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &ti[i].t, &ti[i].d, &ti[i].p);
    ti[i].pos = i + 1;
  }
  sort(ti, ti + n, comp);
  for (int i = 0; i < 2009; ++i) dp[0][i] = 0;
  for (int i = 0; i < 109; ++i) dp[i][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 2000; ++j) {
      dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      if (dp[i][j - 1] > dp[i - 1][j])
        pop[i][j] = make_pair(i, j - 1);
      else
        pop[i][j] = make_pair(i - 1, j);
      if (j >= ti[i - 1].t && j < ti[i - 1].d) {
        if (dp[i - 1][j - ti[i - 1].t] + ti[i - 1].p > dp[i][j])
          pop[i][j] = make_pair(i - 1, j - ti[i - 1].t);
        dp[i][j] = max(dp[i][j], dp[i - 1][j - ti[i - 1].t] + ti[i - 1].p);
      }
    }
  }
  wyn.clear();
  ak = make_pair(n, 2000);
  while (ak.first > 0 && ak.second > 0) {
    p = pop[ak.first][ak.second];
    if (dp[ak.first][ak.second] > dp[p.first][p.second])
      wyn.push_back(ti[ak.first - 1].pos);
    ak = p;
  }
  printf("%d\n", dp[n][2000]);
  printf("%d\n", wyn.size());
  for (auto it = wyn.rbegin(); it != wyn.rend(); ++it) printf("%d ", *it);
  return 0;
}
