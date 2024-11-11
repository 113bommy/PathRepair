#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> F[10015];
pair<int, int> Q[1 << 20];
int dp[5][1 << 20];
int d[1 << 20];
int bfs(int n) {
  d[0] = 0;
  for (int i = 1; i <= n; ++i) d[i] = -1;
  queue<int> q;
  q.push(0);
  while (!q.empty() && d[n] == -1) {
    int node = q.front();
    q.pop();
    for (auto it : F[node])
      if (it.second > 0 && d[it.first] == -1)
        d[it.first] = node, q.push(it.first);
  }
  if (d[n] == -1) return 0;
  int flow = 1e9;
  for (int vertex = n; vertex; vertex = d[vertex])
    flow = min(flow, F[d[vertex]][vertex]);
  for (int vertex = n; vertex; vertex = d[vertex])
    F[d[vertex]][vertex] -= flow, F[vertex][d[vertex]] += flow;
  return flow;
}
int main(void) {
  int n, b, q;
  cin >> n >> b >> q;
  Q[++q] = {b, n};
  for (int i = 1; i < q; ++i) cin >> Q[i].first >> Q[i].second;
  sort(Q + 1, Q + 1 + q);
  for (int i = 1; i < q; ++i)
    if (Q[i + 1].second < Q[i].second) return puts("unfair") * 0;
  for (int i = 1; i <= 5; ++i) F[0][i] = n / 5;
  dp[0][0] = 0;
  for (int i = 1; i <= 1e4 + 55; ++i)
    for (int k = 0; k < 5; ++k) dp[k][i] = dp[k][i - 1] + ((i % 5) == k);
  for (int i = 1; i <= 5; ++i)
    for (int j = 1; j <= q; ++j)
      F[i][j + 5] = dp[i % 5][Q[j].first] - dp[i % 5][Q[j - 1].first];
  for (int i = 1; i <= q; ++i) F[i + 5][q + 6] = Q[i].second - Q[i - 1].second;
  int flow = 0, cnt = 0;
  while ((cnt = bfs(q + 6)) != 0) flow += cnt;
  return 0 * puts(flow == n ? "fair" : "unfair");
}
