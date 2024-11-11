#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, fu = 0;
  char ch = getchar();
  for (; ch < 48 || ch > 57; ch = getchar()) fu |= (ch == '-');
  for (; ch > 47 && ch < 58; ch = getchar()) x = x * 10 + ch - '0';
  return fu ? -x : x;
}
int n, m, Q, ans[400005];
vector<int> t[3005];
struct query {
  int u, v, k, id;
  inline bool operator<(const query &B) const { return u < B.u; }
} q[400005];
vector<int> _q[3005];
int dfn[3005], low[3005], idx, stk[3005], top;
bool instk[3005];
void tarjan(int x, bool nocircle) {
  dfn[x] = ++idx, low[x] = 5000;
  stk[++top] = x, instk[x] = 1;
  if (nocircle) {
    for (vector<int>::iterator it = _q[x].begin(); it != _q[x].end(); it++)
      if (q[*it].k <= top) ans[q[*it].id] = stk[q[*it].k];
  }
  for (vector<int>::iterator it = t[x].begin(); it != t[x].end(); it++) {
    if (!dfn[*it]) {
      tarjan(*it, nocircle && dfn[x] < low[x]);
      low[x] = min(low[x], low[*it]);
    } else if (instk[*it])
      low[x] = min(low[x], dfn[*it]);
  }
  top--, instk[x] = 0;
}
int main() {
  n = read(), m = read(), Q = read();
  for (int i = 1, u, v; i <= m; i++) u = read(), v = read(), t[u].push_back(v);
  for (int i = 1; i <= n; i++) sort(t[i].begin(), t[i].end());
  for (int i = 1; i <= Q; i++) {
    q[i].u = read(), q[i].v = read();
    q[i].k = read(), q[i].id = i, ans[i] = -1;
  }
  sort(q + 1, q + 1 + Q);
  for (int i = 1, j = 1; i <= Q; i = j) {
    for (; j <= Q && q[j].u == q[i].u; j++) _q[q[j].v].push_back(j);
    for (int k = 1; k <= n; k++) dfn[k] = low[k] = 0;
    tarjan(q[i].u, 1);
    for (int k = 1; k <= n; k++) _q[k].clear();
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
  return 0;
}
