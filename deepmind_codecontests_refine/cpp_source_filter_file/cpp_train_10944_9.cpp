#include <bits/stdc++.h>
using namespace std;
long long dp[100005][203];
long long INF = 0x3f3f3f3f3f;
int n, m, k;
struct node {
  long long l, r, d, w;
  int id;
  bool operator<(const node& a) const {
    if (a.w == w) return a.d > d;
    return w < a.w;
  }
};
priority_queue<node> q;
vector<node> g[100005];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  memset(dp, INF, sizeof(dp));
  dp[1][0] = 0;
  for (int i = 1; i <= k; i++) {
    long long l, r, d, w;
    scanf("%lld%lld%lld%lld", &l, &r, &d, &w);
    node temp;
    temp.l = l;
    temp.r = r;
    temp.d = d;
    temp.w = w;
    g[l].push_back(temp);
  }
  for (int i = 1; i <= n; i++) {
    int size = g[i].size();
    for (int j = 0; j < size; j++) q.push(g[i][j]);
    while (!q.empty() && q.top().r < i) {
      q.pop();
    }
    if (q.empty()) {
      for (int j = 0; j <= m; j++) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      }
    } else {
      node temp = q.top();
      long long d = temp.d;
      long long w = temp.w;
      for (int j = 0; j <= m; j++) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        dp[d + 1][j] = min(dp[d + 1][j], dp[i][j] + w);
      }
    }
  }
  long long ans = INF;
  for (int j = 0; j <= m; j++) ans = min(ans, dp[n + 1][j]);
  printf("%lld\n", ans);
  return 0;
}
