#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
vector<int> e[N], re[N], ccc;
int low[N], dfn[N], bID[N];
void tarjan(int x, int ax) {
  static int S[N], top = 0, tims = 0;
  S[++top] = x;
  low[x] = dfn[x] = ++tims;
  ccc.push_back(x);
  for (int y : e[x])
    if (y != ax)
      if (!low[y])
        tarjan(y, x), low[x] = min(low[x], low[y]);
      else
        low[x] = min(low[x], dfn[y]);
  if (low[x] == dfn[x]) {
    while (S[top] != x) bID[S[top--]] = x;
    bID[S[top--]] = x;
  }
}
int _gdis, _gp;
void getMaxDis(int x, int ax, int d) {
  if (d > _gdis) _gdis = d, _gp = x;
  for (int y : re[x])
    if (y != ax) getMaxDis(y, x, d + 1);
}
int solveC(int x) {
  ccc.clear();
  tarjan(x, 0);
  for (int x : ccc)
    for (int y : e[x])
      if (bID[x] != bID[y]) re[bID[x]].push_back(bID[y]);
  _gdis = -1;
  getMaxDis(bID[x], 0, 1);
  _gdis = -1;
  getMaxDis(_gp, 0, 1);
  if (_gdis == 1) return 1;
  int res = _gdis - 2;
  for (int x : ccc)
    if (bID[x] == x && re[x].size() <= 1) ++res;
  return res;
}
int n;
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1, a, b; i <= m; ++i) {
    scanf("%d%d", &a, &b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  int res = 0, cccnt = 0;
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) res += solveC(i), ++cccnt;
  printf("%d\n", n - res + cccnt - 1);
  return 0;
}
