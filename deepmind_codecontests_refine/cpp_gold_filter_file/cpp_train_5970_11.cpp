#include <bits/stdc++.h>
using namespace std;
const int Maxn = 110;
const int Maxl = 510;
const int inf = 2147483647;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
int n, k, tot = 1, a[Maxn * Maxl], la = 0, w[Maxn * Maxl];
int son[Maxn * Maxl][26], sz[Maxn * Maxl];
char str[Maxl];
bool mark[Maxn * Maxl];
void build() {
  int x = 1, len = strlen(str + 1);
  for (int i = 1; i <= len; i++) {
    int p = str[i] - 'a';
    if (!son[x][p]) son[x][p] = ++tot;
    x = son[x][p];
    w[x] = p;
  }
  sz[x]++;
  mark[x] = true;
}
int fa[Maxn * Maxl][16], dep[Maxn * Maxl], dfn[Maxn * Maxl], id = 0;
void dfs(int x, int f) {
  dfn[x] = ++id;
  dep[x] = dep[f] + 1;
  fa[x][0] = f;
  for (int i = 1; (1 << i) <= dep[x]; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (int i = 0; i < 26; i++)
    if (son[x][i]) dfs(son[x][i], x);
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 15; i >= 0; i--)
    if ((1 << i) <= dep[x] - dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = 15; i >= 0; i--)
    if ((1 << i) <= dep[x] && fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
struct Edge {
  int y, next;
} e[Maxn * Maxl];
int len = 0, last[Maxn * Maxl];
void ins(int x, int y) {
  int t = ++len;
  e[t].y = y;
  e[t].next = last[x];
  last[x] = t;
}
bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
int sta[Maxn], top;
long long f[Maxn * Maxl][Maxn];
void DFS(int x) {
  for (int i = 1; i <= sz[x]; i++)
    f[x][i] = (long long)i * (i - 1) / 2LL * dep[x];
  for (int p = last[x]; p; p = e[p].next) {
    int y = e[p].y;
    DFS(y);
    for (int i = sz[x]; i >= 0; i--)
      for (int j = 0; j <= sz[y]; j++)
        f[x][i + j] =
            max(f[x][i + j],
                f[x][i] + f[y][j] + ((x == 1) ? 0 : (long long)dep[x] * i * j));
    sz[x] += sz[y];
  }
}
int main() {
  memset(f, 0, sizeof(f));
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    build();
  }
  dep[0] = -1;
  dfs(1, 0);
  for (int i = 1; i <= tot; i++)
    if (mark[i]) a[++la] = i;
  sort(a + 1, a + 1 + la, cmp);
  sta[top = 1] = 1;
  for (int i = 1; i <= la; i++) {
    int p = LCA(a[i], sta[top]);
    if (p == sta[top]) {
      if (a[i] != sta[top]) sta[++top] = a[i];
      continue;
    }
    while (top > 1 && dep[sta[top - 1]] >= dep[p])
      ins(sta[top - 1], sta[top]), top--;
    if (sta[top] != p) ins(p, sta[top]), sta[top] = p;
    sta[++top] = a[i];
  }
  while (top > 1) ins(sta[top - 1], sta[top]), top--;
  DFS(1);
  printf("%lld", f[1][k]);
}
