#include <bits/stdc++.h>
using namespace std;
int n, k, m, tot, INF;
int cdy[10086], len[10086], wzy[10086];
int sdc[10086], dis[210][210], mindis[10086];
int dp[(1 << 22) + 1];
bool vis[10086];
queue<int> que;
void SPFA(int now) {
  memset(mindis, 0x3f, sizeof mindis);
  que.push(sdc[now]);
  mindis[sdc[now]] = 0;
  vis[sdc[now]] = 1;
  for (; !que.empty();) {
    int u = que.front();
    que.pop();
    vis[u] = 0;
    for (int i = 1; i <= m; ++i) {
      if (u + len[i] <= n + 1 && mindis[u + len[i]] > mindis[u] + 1) {
        mindis[u + len[i]] = mindis[u] + 1;
        if (!vis[u + len[i]]) que.push(u + len[i]), vis[u + len[i]] = 1;
      }
      if (u - len[i] > 0 && mindis[u - len[i]] > mindis[u] + 1) {
        mindis[u - len[i]] = mindis[u] + 1;
        if (!vis[u - len[i]]) que.push(u - len[i]), vis[u - len[i]] = 1;
      }
    }
  }
  for (int i = 1; i <= tot; ++i) dis[now][i] = mindis[sdc[i]];
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1, x; i <= k; ++i) scanf("%d", &x), cdy[x] = 1;
  for (int i = 1; i <= m; ++i) scanf("%d", &len[i]);
  for (int i = 1; i <= n + 1; ++i) wzy[i] = cdy[i] ^ cdy[i - 1];
  for (int i = 1; i <= n + 1; ++i)
    if (wzy[i]) sdc[++tot] = i;
  if (tot == 0) {
    printf("0");
    return 0;
  }
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= tot; ++i) SPFA(i);
  memset(dp, 0x3f, sizeof dp);
  INF = dp[0];
  dp[0] = 0;
  for (int i = 0, tail; i < (1 << tot); ++i) {
    tail = 0;
    for (int p = 1; p <= tot; ++p)
      if ((1 << (p - 1)) & i) {
        tail = p;
        break;
      }
    for (int p = 1; p <= tot; ++p)
      if ((1 << (p - 1)) & i)
        dp[i] = min(dp[i],
                    dp[i ^ (1 << (p - 1)) ^ (1 << (tail - 1))] + dis[p][tail]);
  }
  printf("%d\n", (dp[(1 << tot) - 1] == INF ? -1 : dp[(1 << tot) - 1]));
  return 0;
}
