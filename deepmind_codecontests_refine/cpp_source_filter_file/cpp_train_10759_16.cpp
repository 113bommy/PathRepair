#include <bits/stdc++.h>
using namespace std;
const int MX = 15;
const int INF = 1111111111;
int N, M, ans;
int tab[MX][MX], deg[MX];
vector<int> con[1 << MX], w[1 << MX];
struct data {
  int u, val;
  data(int u = 0, int val = 0) : u(u), val(val) {}
  bool operator<(const data &D) const { return val > D.val; }
};
priority_queue<data> que;
int val[1 << MX];
void solve() {
  int now;
  for (int stat = 0; stat < (1 << N); stat++) {
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++)
        if (tab[i][j] < INF) {
          now = stat;
          now ^= (1 << i), now ^= (1 << j);
          con[stat].push_back(now);
          w[stat].push_back(tab[i][j]);
        }
  }
  now = 0;
  for (int i = 0; i < N; i++) {
    now |= ((deg[i] % 2) << i);
  }
  for (int i = 0; i < (1 << N); i++) val[i] = INF;
  que.push(data(now, 0));
  val[now] = 0;
  while (!que.empty()) {
    data tmp = que.top();
    que.pop();
    if (tmp.u == 0) {
      ans += tmp.val;
      printf("%d\n", ans);
      return;
    }
    for (int i = con[tmp.u].size() - 1; i >= 0; i--) {
      int v = con[tmp.u][i];
      if (val[v] > val[tmp.u] + w[tmp.u][i]) {
        val[v] = val[tmp.u] + w[tmp.u][i];
        que.push(data(v, val[v]));
      }
    }
  }
  puts("-1");
}
int vis[MX];
void dfs(int u) {
  vis[u] = true;
  for (int i = 0; i < N; i++)
    if (!vis[i] && tab[u][i] < INF) dfs(i);
}
bool connected() {
  dfs(1);
  for (int i = 0; i < N; i++)
    if (!vis[i] && deg[i]) return false;
  return true;
}
void init() {
  for (int i = 0; i < MX; i++)
    for (int j = 0; j < MX; j++) tab[i][j] = INF;
}
int main() {
  init();
  scanf("%d%d", &N, &M);
  while (M--) {
    int u, v, ww;
    scanf("%d%d%d", &u, &v, &ww);
    u--, v--;
    ans += ww;
    if (tab[u][v] > ww) tab[u][v] = tab[v][u] = ww;
    deg[u]++, deg[v]++;
  }
  if (!connected()) {
    puts("-1");
    return 0;
  }
  solve();
  return 0;
}
