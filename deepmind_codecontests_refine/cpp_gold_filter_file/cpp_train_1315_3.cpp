#include <bits/stdc++.h>
using namespace std;
int now[5 * 100010], after[5 * 100010], mx[5 * 100010];
int lft[5 * 100010], rgt[5 * 100010], vi[5 * 100010], timer = 0, comp = 0;
long long Add[5 * 100010];
vector<int> g[5 * 100010];
stack<int> stk;
inline void dfs(int c, int p) {
  vi[c] = 1;
  now[c] = after[c] = ++timer;
  stk.push(c);
  for (auto x : g[c]) {
    if (x != p) {
      if (!vi[x]) {
        dfs(x, c);
        now[c] = min(now[c], now[x]);
      } else
        now[c] = min(now[c], now[x]);
    }
  }
  if (now[c] == after[c]) {
    comp++;
    lft[comp] = rgt[comp] = c;
    while (1) {
      int node = stk.top();
      stk.pop();
      lft[comp] = min(lft[comp], node);
      rgt[comp] = max(rgt[comp], node);
      if (node == c) break;
    }
  }
}
int main() {
  int n, m;
  scanf("%d", &n);
  ;
  scanf("%d", &m);
  ;
  memset(vi, 0, sizeof(vi));
  ;
  for (int x = 1; x <= m; x++) {
    int u, v;
    scanf("%d", &u);
    ;
    scanf("%d", &v);
    ;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int x = 1; x <= n; x++)
    if (!vi[x]) dfs(x, 0);
  for (int x = 1; x <= n; x++) mx[x] = n;
  for (int x = 1; x <= comp; x++)
    if (lft[x] != rgt[x]) mx[lft[x]] = rgt[x] - 1;
  for (int x = n - 1; x >= 1; x--) mx[x] = min(mx[x + 1], mx[x]);
  for (int x = 1; x <= n; x++) Add[x] = Add[x - 1] + mx[x] - x + 1;
  int q;
  scanf("%d", &q);
  ;
  while (q--) {
    int from, to;
    scanf("%d", &from);
    ;
    scanf("%d", &to);
    ;
    int l = from - 1, r = to + 1, chk = from;
    while (l + 1 < r) {
      int m = l + r >> 1;
      if (mx[m] > to)
        r = m;
      else
        chk = max(chk, m), l = m;
    }
    chk = l;
    printf("%lld\n",
           Add[chk] - Add[from - 1] + 1LL * (to - chk) * (to - chk + 1LL) / 2);
  }
}
