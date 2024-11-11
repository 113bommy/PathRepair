#include <bits/stdc++.h>
using namespace std;
const int N = 10010, M = 15010, inf = 1e9;
struct st1 {
  int to, next, c;
} e[M << 1];
struct st2 {
  int to, next, f, op;
} F[1000001];
int n, m, x, y, z, cnt, cnt2, ans, i, col, cyc, S, T, fi[N], c[N], l[N],
    op[M << 1], d[N + M], f2[N + M], dep[N + M], num[N + M];
bool vis[N], u[M << 1];
void addl(int x, int y, int z) {
  e[++cnt].to = y, e[cnt].next = fi[x], e[cnt].c = z, fi[x] = cnt;
}
void addf(int x, int y, int f) {
  F[++cnt2].to = y, F[cnt2].next = f2[x], F[cnt2].f = f, F[cnt2].op = cnt2 + 1,
  f2[x] = cnt2;
  F[++cnt2].to = x, F[cnt2].next = f2[y], F[cnt2].f = 0, F[cnt2].op = cnt2 - 1,
  f2[y] = cnt2;
}
void dfs(int x, int fa, int d) {
  vis[x] = 1;
  for (int i = fi[x]; i; i = e[i].next)
    if (!u[i] && e[i].to != fa) {
      int y = e[i].to;
      if (vis[y]) {
        cyc++, u[i] = u[op[i]] = 1;
        addf(S, cyc, dep[x] - dep[y]);
        for (int j = dep[y]; j <= dep[x]; j++)
          u[l[j]] = u[op[l[j]]] = 1, addf(cyc, c[j] + 1, 1);
        addf(cyc, e[i].c + 1, 1);
      } else {
        c[dep[y] = d + 1] = e[i].c, l[d] = i, dfs(y, x, d + 1);
        if (!u[i]) addf(S, ++cyc, 1), addf(cyc, e[i].c + 1, 1);
      }
    }
}
int sap(int x, int del) {
  if (x == T) return del;
  int sum = 0, md = cyc + 1;
  for (int i = f2[x]; i; i = F[i].next)
    if (F[i].f) {
      if (d[F[i].to] == d[x] - 1) {
        int save = sap(F[i].to, min(F[i].f, del - sum));
        sum += save, F[i].f -= save, F[F[i].op].f += save;
        if (d[S] >= cyc + 1 || sum == del) return sum;
      }
      md = min(md, d[F[i].to]);
    }
  if (!sum) {
    if (!(--num[d[x]]))
      d[S] = cyc + 1;
    else
      num[d[x] = md + 1]++;
  }
  return sum;
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d\n", &x, &y, &z);
    addl(x, y, z), addl(y, x, z);
    col = max(col, z);
  }
  for (i = 1; i <= cnt; i += 2) op[op[i] = i + 1] = i;
  S = 0, T = 1, cyc = 1 + col;
  for (i = 1; i <= col; i++) addf(i + 1, T, 1);
  dfs(1, 0, 0);
  num[0] = cyc + 1;
  for (; d[S] <= cyc;) ans += sap(S, inf);
  printf("%d", ans);
}
