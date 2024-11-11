#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int N, M, dp[MAXN], res[MAXN];
vector<pair<int, int>> adj[MAXN];
int check(int v) {
  if (dp[v]) return dp[v];
  dp[v] = 1;
  for (auto p : adj[v]) {
    int n = p.first;
    if (check(n) + 1 > dp[v]) {
      dp[v] = dp[n] + 1;
      res[v] = max(res[n], p.second);
    }
  }
  return dp[v];
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a -= 1, b -= 1;
    adj[a].push_back({b, i + 1});
  }
  for (int i = 0; i < N; i++) {
    if (check(i) == N) {
      printf("%dn", res[i]);
      return 0;
    }
  }
  printf("-1n");
}
