#include <bits/stdc++.h>
using namespace std;
const int _N = 100010;
const int _M = _N << 1;
const int INF = 1000000000;
int n, m, numE, Fir[_N];
int ed[_M], tp[_M], Next[_M];
void addE(int x, int y, int z) {
  ed[++numE] = y, tp[numE] = z, Next[numE] = Fir[x], Fir[x] = numE;
  ed[++numE] = x, tp[numE] = z, Next[numE] = Fir[y], Fir[y] = numE;
}
int fa[_N], sta[_N], save[_N], numZ;
int re[2][_N], now, res[2];
void dfs(int u) {
  save[++save[0]] = u, numZ += sta[u];
  for (int e = Fir[u]; e; e = Next[e]) {
    int v = ed[e];
    if (fa[v]) continue;
    fa[v] = u, sta[v] = sta[u] ^ tp[e], dfs(v);
  }
}
void solve() {
  for (int i = 1; i <= n; i++) fa[i] = 0;
  for (int i = 1; i <= n; i++)
    if (!fa[i]) {
      fa[i] = -1, sta[i] = 1, numZ = save[0] = 0, dfs(i);
      for (int j = 1; j <= save[0]; j++)
        for (int e = Fir[save[j]]; e; e = Next[e])
          if (tp[e] != sta[save[j]] ^ sta[ed[e]]) {
            res[now] = INF;
            return;
          }
      if (numZ > save[0] - numZ)
        for (int j = 1; j <= save[0]; j++) sta[save[j]] ^= 1;
    }
  for (int i = 1; i <= n; i++) re[now][i] = sta[i], res[now] += sta[i];
}
int main() {
  scanf("%d%d", &n, &m);
  static char s[5];
  static int x, y;
  for (int i = 1; i <= m; i++)
    scanf("%d%d%s", &x, &y, s), addE(x, y, s[0] == 'B');
  solve();
  for (int i = 1; i <= n; i++)
    for (int j = Fir[i]; j; j = Next[j]) tp[j] ^= 1;
  ++now, solve();
  if (res[0] < res[1]) now = 0;
  if (res[0] == INF) {
    puts("-1");
    return 0;
  }
  printf("%d\n", res[now]);
  for (int i = 1; i <= n; i++)
    if (re[now][i]) printf("%d ", i);
  puts("");
  return 0;
}
