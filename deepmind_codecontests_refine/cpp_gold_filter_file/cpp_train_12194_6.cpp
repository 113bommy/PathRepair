#include <bits/stdc++.h>
const int N = 1e5 + 5, M = 7001;
std::bitset<7001> dp[N], f[M], g[M];
int u[M], prime[M], cnt;
bool vis[M];
void init() {
  cnt = 0;
  u[1] = 1;
  for (int i = 1; i < M; i++)
    for (int j = i; j < M; j += i) f[j][i] = 1;
  for (int i = 2; i < M; i++) {
    if (!vis[i]) prime[cnt++] = i, u[i] = -1;
    for (int j = 0; j < cnt && i * prime[j] < M; j++) {
      vis[i * prime[j]] = 1;
      u[i * prime[j]] = -u[i];
      if (i % prime[j] == 0) {
        u[i * prime[j]] = 0;
        break;
      }
    }
  }
  for (int i = 1; i < M; i++) {
    for (int j = i; j < M; j += i)
      if (u[j / i]) g[i][j] = 1;
  }
}
int main() {
  init();
  int n, q, v, x, y, z, op;
  scanf("%d%d", &n, &q);
  std::vector<int> ans;
  while (q--) {
    scanf("%d%d", &op, &x);
    if (op == 1) {
      scanf("%d", &v);
      dp[x] = f[v];
    } else if (op == 2) {
      scanf("%d%d", &y, &z);
      dp[x] = (dp[z] ^ dp[y]);
    } else if (op == 3) {
      scanf("%d%d", &y, &z);
      dp[x] = (dp[z] & dp[y]);
    } else {
      scanf("%d", &v);
      ans.push_back((dp[x] & g[v]).count() & 1);
    }
  }
  for (int v : ans) printf("%d", v);
  return 0;
}
