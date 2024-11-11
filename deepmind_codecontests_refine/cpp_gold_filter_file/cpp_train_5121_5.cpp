#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long w[maxn];
int du[maxn];
long long dp[maxn];
vector<int> E[maxn];
int main() {
  int n, m, st;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
    du[u]++;
    du[v]++;
  }
  cin >> st;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (du[i] == 1 && i != st) q.push(i);
  }
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    du[now] = -1;
    for (auto nxt : E[now]) {
      if (du[nxt] < 0) continue;
      du[nxt]--;
      dp[nxt] = max(dp[nxt], w[now] + dp[now]);
      if (du[nxt] == 1 && nxt != st) q.push(nxt);
    }
  }
  long long sum = 0, maxx = 0;
  for (int i = 1; i <= n; i++) {
    if (du[i] == -1) continue;
    sum += w[i];
    maxx = max(maxx, dp[i]);
  }
  long long ans = sum + maxx;
  printf("%lld\n", ans);
}
