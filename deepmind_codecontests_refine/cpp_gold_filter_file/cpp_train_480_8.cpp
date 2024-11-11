#include <bits/stdc++.h>
using namespace std;
const int S = 450;
int n, m, ans, a[100005], cnt[100005 / S + 3][100005 * 2], tag[100005 / S + 3],
    bel[100005];
int dep[100005], fa[100005], top[100005], son[100005], siz[100005], dfn[100005],
    tim;
bool col[100005];
int fir[100005], nxt[100005];
void line(int x, int y) { nxt[y] = fir[x], fir[x] = y; }
void dfs1(int u) {
  dep[u] = dep[fa[u]] + 1, siz[u] = 1;
  for (int v = fir[u]; v; v = nxt[v])
    dfs1(v), siz[u] += siz[v], siz[v] > siz[son[u]] && (son[u] = v);
}
void dfs2(int u, int tp) {
  top[u] = tp, dfn[u] = ++tim;
  if (son[u]) dfs2(son[u], tp);
  for (int v = fir[u]; v; v = nxt[v])
    if (!top[v]) dfs2(v, v);
}
void Rev(int i, int v) {
  col[i] ^= 1, cnt[bel[i]][a[i]] -= v;
  if (a[i] + tag[bel[i]] > n) ans -= v;
}
void brute(int l, int r, int v) {
  for (int i = l, x = bel[l]; i <= r; i++) {
    if (!col[i]) {
      ans += (a[i] + v + tag[x] > n) - (a[i] + tag[x] > n);
      cnt[x][a[i]]--, cnt[x][a[i] + v]++;
    }
    a[i] += v;
  }
}
void mdf(int l, int r, int v) {
  if (bel[l] == bel[r]) return brute(l, r, v);
  brute(l, (bel[l] + 1) * S, v), brute(bel[r] * S + 1, r, v);
  for (int i = bel[l] + 1; i < bel[r]; i++) {
    tag[i] += v;
    if (v > 0)
      ans += cnt[i][n + 1 - tag[i]];
    else
      ans -= cnt[i][n - tag[i]];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++) scanf("%d", &fa[i]), line(fa[i], i);
  dfs1(1), dfs2(1, 1);
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), a[dfn[i]] = n - x;
  for (int i = 1; i <= n; i++) cnt[bel[i] = (i - 1) / S][a[i]]++;
  for (int x, y; m--;) {
    scanf("%d", &x), y = x > 0 ? 1 : -1, x = abs(x);
    Rev(dfn[x], y);
    for (; x; x = fa[top[x]]) mdf(dfn[top[x]], dfn[x], y);
    printf("%d%c", ans, !m ? 10 : 32);
  }
}
