#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
long long int dp[2][N];
int M[N], w[N], from[N], to[N], l[N], r[N], n, m, k, s1, s2, f;
vector<int> adj[N];
void Dijk(int St, int id) {
  fill(dp[id], dp[id] + N, 1e18), fill(M, M + N, 0);
  priority_queue<pair<long long int, int>> pq;
  pq.push({dp[id][St] = 0, St});
  while ((int)pq.size()) {
    int v = pq.top().second;
    pq.pop();
    if (M[v]) continue;
    M[v] = 1;
    for (int x : adj[v]) {
      int u = to[x];
      if (dp[id][u] > dp[id][v] + w[x]) {
        dp[id][u] = dp[id][v] + w[x];
        pq.push({-dp[id][u], u});
      }
    }
  }
}
void relax(int id) {
  if (w[id] ^ r[id]) return;
  if (dp[0][from[id]] < dp[1][from[id]]) w[id] = l[id];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d%d", &s1, &s2, &f);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &from[i], &to[i], &w[i]);
    adj[from[i]].push_back(i);
  }
  for (int i = m + 1; i <= m + k; i++) {
    scanf("%d%d%d%d", &from[i], &to[i], &l[i], &r[i]);
    w[i] = r[i];
    adj[from[i]].push_back(i);
  }
  for (int i = 1; i <= k + 1; i++) {
    Dijk(s1, 0), Dijk(s2, 1);
    for (int j = m + 1; j <= m + k; j++) {
      relax(j);
    }
  }
  Dijk(s1, 0), Dijk(s2, 1);
  if (dp[0][f] > dp[1][f]) return !printf("LOSE\n");
  printf(dp[0][f] ^ dp[1][f] ? "WIN\n" : "DRAW\n");
  for (int i = m + 1; i <= m + k; i++) printf("%d ", w[i]);
  return 0;
}
