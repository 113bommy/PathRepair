#include <bits/stdc++.h>
using namespace std;
const int Q = (1 << 21) + 1;
int las[Q], e[Q << 1], nn[Q << 1], inc = 1;
void ins(int x, int y) {
  e[++inc] = y;
  nn[inc] = las[x];
  las[x] = inc;
}
int dfn[Q], low[Q], Time = 0, bel[Q];
int sta[Q], tp = 0, inst[Q];
int scc = 0;
void dfs(int x, int lt) {
  low[x] = dfn[x] = ++Time;
  sta[++tp] = x, inst[x] = 1;
  for (int t = las[x]; t; t = nn[t]) {
    int y = e[t];
    if (t == lt) continue;
    if (!dfn[y]) {
      dfs(y, t ^ 1);
      low[x] = min(low[x], low[y]);
    } else if (inst[y])
      low[x] = min(low[x], dfn[y]);
  }
  if (low[x] != dfn[x]) return;
  int u;
  ++scc;
  do {
    u = sta[tp--];
    inst[u] = 0;
    bel[u] = scc;
  } while (u != x);
}
int L[Q], R[Q];
vector<int> ans;
int main() {
  int n, lim, m1, m2;
  scanf("%d%d%d%d", &m1, &n, &lim, &m2);
  for (int i = 1, x, y; i <= m1; i++)
    scanf("%d%d", &x, &y), ins(x + n, y), ins(y + n, x);
  for (int i = 1; i <= n; i++) scanf("%d%d", &L[i], &R[i]);
  for (int i = 1, x, y; i <= m2; i++)
    scanf("%d%d", &x, &y), ins(x, y + n), ins(y, x + n);
  int b1 = 2 * n, b2 = 2 * n + lim;
  for (int i = 2; i <= lim; i++) ins(i + b1, b1 + i - 1);
  for (int i = lim - 1; i; --i) ins(b2 + i, b2 + i + 1);
  for (int i = 1; i <= n; i++) {
    if (L[i] != 1) ins(i, b1 + L[i] - 1);
    ins(b1 + R[i], i + n);
    if (R[i] != lim) ins(i, b2 + R[i] + 1);
    ins(b2 + L[i], i + n);
  }
  for (int i = 1; i <= (n + lim) * 2; i++)
    if (!dfn[i]) dfs(i, 0);
  for (int i = 1; i <= n; i++)
    if (bel[i] == bel[i + n]) return 0 & puts("-1");
  int mx = 0;
  for (int i = 1; i <= n; i++)
    if (bel[i] < bel[i + n]) ans.push_back(i), mx = max(mx, L[i]);
  printf("%d %d\n", (int)ans.size(), mx);
  for (int p : ans) printf("%d ", p);
  puts("");
  return 0;
}
