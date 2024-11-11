#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int n, m, f[N], st[N], fa[N], ch[N][2];
bool fl[N], rev[N];
vector<int> v[N];
struct edge {
  int u, t;
} e[N];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline int find(int u) {
  if (f[u] == u) return u;
  return f[u] = find(f[u]);
}
inline bool isroot(int u) {
  return ((ch[fa[u]][0] != u) && (ch[fa[u]][1] != u));
}
inline bool get(int u) { return (ch[fa[u]][1] == u); }
inline void pushdown(int u) {
  if (rev[u])
    swap(ch[u][0], ch[u][1]), rev[u] ^= 1, rev[ch[u][0]] ^= 1,
        rev[ch[u][1]] ^= 1;
}
inline void rotate(int u) {
  int pa = fa[u], gr = fa[fa[u]], x = get(u);
  if (!isroot(pa)) ch[gr][get(pa)] = u;
  fa[u] = gr;
  ch[pa][x] = ch[u][x ^ 1], fa[ch[u][x ^ 1]] = pa, ch[u][x ^ 1] = pa,
  fa[pa] = u;
}
inline void splay(int u) {
  st[st[0] = 1] = u;
  for (int x = u; !isroot(x); x = fa[x]) st[++st[0]] = fa[x];
  for (int i = st[0]; i >= 1; i--) pushdown(st[i]);
  for (; !isroot(u); rotate(u))
    if (!isroot(fa[u])) rotate(get(fa[u]) == get(u) ? fa[u] : u);
}
inline void access(int u) {
  for (int x = 0; u > 0; x = u, u = fa[u]) splay(u), ch[u][1] = x;
}
inline void makeroot(int u) { access(u), splay(u), rev[u] ^= 1; }
inline void cutx(int u, int v) {
  makeroot(u), access(v), splay(v);
  if (ch[v][0] != u || ch[u][1]) return;
  ch[v][0] = 0, fa[u] = 0;
}
inline void link(int u, int v) { makeroot(u), fa[u] = v; }
inline void write(int u) {
  if (u > 9) write(u / 10);
  putchar(u % 10 + '0');
}
inline void getans(int u, int t) {
  makeroot(u), access(t), splay(t);
  int v = t, f1 = v, f2 = v, f3 = v;
  while (v > 0) {
    pushdown(v);
    if (find(v) != find(u))
      f1 = v, v = ch[v][0];
    else
      f2 = v, v = ch[v][1];
  }
  cutx(f1, f2), link(u, t);
  write(u), putchar(' ');
  write(t), putchar(' ');
  write(f1), putchar(' ');
  write(f2), putchar('\n');
}
inline void dfs(int u, int fa) {
  fl[u] = 1;
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (fl[x]) continue;
    dfs(x, u);
  }
  if (fa > 0) {
    getans(u, fa), f[find(u)] = find(fa);
  }
}
int main() {
  n = read();
  int u, t;
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i < n; i++)
    u = read(), t = read(), v[u].push_back(t), v[t].push_back(u);
  for (int i = 1; i < n; i++)
    u = read(), t = read(), link(u, t), e[i].u = u, e[i].t = t;
  cout << n - 1 << endl, dfs(1, 0);
}
