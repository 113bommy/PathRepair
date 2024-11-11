#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000, maxm = 30000;
int n, m, s, t, len, ID[maxn + 5], fa[maxn + 5], lst[maxn + 5], que[maxn + 5],
    ti, vis[maxn + 5], ans, A, B;
int fst, E, lnk[2][maxn + 5], son[(maxm << 2) + 5], nxt[(maxm << 2) + 5],
    w[(maxm << 2) + 5];
int ban, dfn[maxn + 5], low[maxn + 5], top, stk[maxn + 5], EBC[maxn + 5],
    MIN[maxn + 5];
bool instk[maxn + 5];
inline bool Bfs(int s, int t) {
  int Head = 0, Tail = 0;
  que[++Tail] = s;
  vis[s] = ++ti;
  while (Head != Tail)
    for (int x = que[++Head], j = lnk[0][x]; ~j; j = nxt[j])
      if (vis[son[j]] < ti)
        lst[son[j]] = j, fa[son[j]] = x, que[++Tail] = son[j], vis[son[j]] = ti;
  if (vis[t] < ti) return false;
  for (int x = t; x != s; x = fa[x]) ID[++len] = lst[x];
  return true;
}
void Tarjan(int x, int pre = -1) {
  dfn[x] = low[x] = ++ti;
  stk[++top] = x;
  instk[x] = true;
  for (int j = lnk[0][x]; ~j; j = nxt[j])
    if ((j ^ 1) != pre && (j >> 1) != ban)
      if (!dfn[son[j]])
        Tarjan(son[j], j), low[x] = min(low[x], low[son[j]]);
      else if (instk[son[j]])
        low[x] = min(low[x], dfn[son[j]]);
  if (dfn[x] == low[x])
    for (int y = (EBC[0]++, stk[top--]);; y = stk[top--]) {
      EBC[y] = EBC[0];
      instk[y] = false;
      if (y == x) break;
    }
}
inline int Miner(int x, int y) { return y < 0 || ~x && w[x] < w[y] ? x : y; }
inline int Min(int s, int t) {
  int Head = 0, Tail = 0;
  que[++Tail] = EBC[s];
  vis[EBC[s]] = ++ti;
  MIN[EBC[s]] = -1;
  while (Head != Tail)
    for (int x = que[++Head], j = lnk[1][x]; ~j; j = nxt[j])
      if (vis[son[j]] < ti)
        MIN[son[j]] = Miner(MIN[x], w[j]), que[++Tail] = son[j],
        vis[son[j]] = ti;
  return vis[EBC[t]] < ti ? -1 : MIN[EBC[t]];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  E = 0;
  memset(lnk[0], 255, sizeof(lnk[0]));
  for (int i = 1, x, y, z; i <= m; i++)
    scanf("%d%d%d", &x, &y, &z),
        (son[E] = (y), w[E] = (z), nxt[E] = lnk[0][x], lnk[0][x] = E++),
        (son[E] = (x), w[E] = (z), nxt[E] = lnk[0][y], lnk[0][y] = E++);
  fst = E;
  if (!Bfs(s, t)) return puts("0"), puts("0"), 0;
  ans = 2e9 + 1;
  for (int i = 1; i <= len; i++) {
    ban = ID[i] >> 1;
    int W = w[ID[i]];
    memset(dfn, 0, sizeof(dfn));
    EBC[0] = 0;
    for (int i = 1; i <= n; i++)
      if (!dfn[i]) Tarjan(i);
    if (EBC[s] == EBC[t]) continue;
    E = fst;
    memset(lnk[1], 255, sizeof(lnk[1]));
    for (int i = 1; i <= n; i++)
      for (int j = lnk[0][i]; ~j; j = nxt[j])
        if ((j >> 1) != ban && EBC[i] != EBC[son[j]])
          (son[E] = (EBC[son[j]]), w[E] = (j), nxt[E] = lnk[1][EBC[i]],
           lnk[1][EBC[i]] = E++);
    int MIN = Min(s, t);
    if (MIN < 0) {
      if (W < ans) ans = W, A = ban + 1, B = 0;
    } else if (W + w[MIN] < ans)
      ans = W + w[MIN], A = ban + 1, B = (MIN >> 1) + 1;
  }
  if (ans == 2e9 + 1) return puts("-1"), 0;
  printf("%d\n", ans);
  B ? (puts("2"), printf("%d %d\n", A, B)) : (puts("1"), printf("%d\n", A));
  return 0;
}
