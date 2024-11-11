#include <bits/stdc++.h>
using namespace std;
const int SIZE = 202522;
int n, m, k, tot = 1, kmax, s;
int to[SIZE * 2], nxt[SIZE * 2], head[SIZE], cnt;
deque<int> rec[SIZE];
bool vis[SIZE];
void ins(int u, int v) {
  nxt[++cnt] = head[u];
  to[cnt] = v;
  head[u] = cnt;
  return;
}
void dfs(int u) {
  vis[u] = 1;
  rec[tot].push_back(u);
  for (int i = head[u]; i; i = nxt[i])
    if (!vis[to[i]]) {
      if (++s == kmax) {
        s = 0;
        tot++;
      }
      dfs(to[i]);
      if (++s == kmax) {
        s = 0;
        tot++;
      }
      rec[tot].push_back(u);
    }
  return;
}
int main(void) {
  int u, v;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    ins(u, v);
    ins(v, u);
  }
  kmax = 1.0 * (n + n) / k - 1e-10 + 1;
  dfs(1);
  for (int i = 1; i <= tot; i++) {
    printf("%d", rec[i].size());
    for (int j = 0; j < rec[i].size(); j++) printf(" %d", rec[i][j]);
    printf("\n");
  }
  for (int i = tot + 1; i <= k; i++) printf("1 1\n");
  return 0;
}
