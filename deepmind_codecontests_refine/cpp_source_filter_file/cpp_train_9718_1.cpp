#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
struct EDGE {
  int to, next;
} e[N];
int laste[N], eid;
void add_edge(int u, int v) {
  e[eid].to = v;
  e[eid].next = laste[u];
  laste[u] = eid++;
}
int n, m, bd, lastbd;
int used[N], lst[N], dep[N];
int dp1[N], dp2[N];
void dfs(int u, int D) {
  used[u] = 1;
  dep[u] = D;
  dp1[u] = dp2[u] = 0;
  for (int i = laste[u]; i; i = e[i].next) {
    if (lst[u] == (i ^ 1)) continue;
    int v = e[i].to;
    if (!used[v]) {
      lst[v] = i;
      dfs(v, 1 - D);
      dp1[u] += dp1[v];
      dp2[u] += dp2[v];
    } else if (used[v] == 1) {
      if (dep[u] == dep[v]) {
        bd++;
        lastbd = (i >> 1) + 1;
        dp1[u]++;
      } else
        dp2[u]++;
    } else {
      if (dep[u] == dep[v])
        dp1[u]--;
      else
        dp2[u]--;
    }
  }
  used[u] = 2;
}
int main() {
  scanf("%d%d", &n, &m);
  eid = 0;
  memset(laste, 0, sizeof(laste));
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }
  memset(lst, -1, sizeof(lst));
  memset(used, 0, sizeof(used));
  bd = 0;
  for (int i = 1; i <= n; i++)
    if (!used[i]) dfs(i, 0);
  vector<int> ans;
  if (!bd)
    for (int i = 1; i <= m; i++) ans.push_back(i);
  else {
    if (bd == 1) ans.push_back(lastbd);
    for (int i = 1; i <= n; i++)
      if (lst[i] != -1 && dp1[i] == bd && !dp2[i])
        ans.push_back((lst[i] >> 1) + 1);
    sort(ans.begin(), ans.end());
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0, _ = ans.size(); i < _; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
