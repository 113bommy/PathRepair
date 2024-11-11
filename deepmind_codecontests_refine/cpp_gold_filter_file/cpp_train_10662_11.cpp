#include <bits/stdc++.h>
using namespace std;
int a[200001];
int n, m;
int cmd, x, val;
int fenwick[200001];
int rt[200001];
bool d[200001];
int pos[200001];
vector<int> g[200001];
int timer;
void update(int i, int val) {
  for (; i < n; i |= i + 1) fenwick[i] += val;
}
int sum(int r) {
  int res;
  for (res = 0; r > -1; r = (r & (r + 1)) - 1) res += fenwick[r];
  return res;
}
void dfs(int v, bool f = false, int p = -1) {
  d[v] = f;
  pos[v] = timer;
  update(timer, f ? -a[v] : a[v]);
  update(++timer, f ? a[v] : -a[v]);
  for (int i = 0; i < g[v].size(); ++i)
    if (g[v][i] != p) dfs(g[v][i], !f, v);
  rt[v] = timer;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  while (m--) {
    scanf("%d %d", &cmd, &x);
    --x;
    if (cmd == 1) {
      scanf("%d", &val);
      if (d[x]) val = -val;
      update(pos[x], val);
      update(rt[x], -val);
    } else
      printf("%d\n", d[x] ? -sum(pos[x]) : sum(pos[x]));
  }
  return 0;
}
