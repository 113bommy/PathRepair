#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int N, K;
vector<pair<char, int>> adj[MAXN + 10];
int A[MAXN + 10], B[MAXN + 10];
int dfn[MAXN + 10], cnt, dp[MAXN + 10];
void dfs(int now) {
  if (B[now]) cnt++;
  dfn[now] = cnt;
  for (auto nxt : adj[now]) {
    dfs(nxt.second);
  }
}
void dfs2(int now, int bef, int val) {
  if (now) {
    dp[now] = dp[bef] + 1;
    if (B[now]) dp[now] = min(dp[now], val + dfn[now]);
  }
  for (auto nxt : adj[now]) {
    dfs2(nxt.second, now, min(val, dp[now] - dfn[now] + A[now]));
  }
}
int main() {
  int i, j;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    char c;
    int v;
    scanf("%d %c", &v, &c);
    adj[v].push_back({c, i});
  }
  for (i = 0; i <= N; i++) sort(adj[i].begin(), adj[i].end());
  scanf("%d", &K);
  for (i = 1; i <= K; i++) scanf("%d", &A[i]), B[A[i]] = 1;
  dfs(0);
  dfs2(0, 0, 1e9);
  for (i = 1; i <= K; i++) printf("%d ", dp[A[i]]);
  printf("\n");
}
