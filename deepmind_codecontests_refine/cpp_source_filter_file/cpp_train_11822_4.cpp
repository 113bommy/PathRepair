#include <bits/stdc++.h>
using namespace std;
char s[400009];
int n, tot = 1, cnt = 0, ls[400009 * 20], rs[400009 * 20], pos[400009],
       rt[400009], maxl[400009], slink[400009], ch[400009][26], f[400009],
       g[400009];
vector<int> vec[400009];
inline int newnode(int mx, int nex) {
  maxl[++tot] = mx, slink[tot] = nex;
  return tot;
}
inline int add_char(int v, int c) {
  int z = newnode(maxl[v] + 1, 1);
  while (v && !ch[v][c]) ch[v][c] = z, v = slink[v];
  if (!v) return z;
  int x = ch[v][c];
  if (maxl[x] == maxl[v] + 1) {
    slink[z] = x;
    return z;
  }
  int y = newnode(maxl[v] + 1, slink[x]);
  slink[x] = slink[z] = y;
  memcpy(ch[y], ch[x], sizeof(ch[y]));
  while (v && ch[v][c] == x) ch[v][c] = y, v = slink[v];
  return z;
}
void mdf(int &x, int l, int r, int p) {
  x = ++cnt;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (p <= mid)
    mdf(ls[x], l, mid, p);
  else
    mdf(rs[x], mid + 1, r, p);
}
int merge(int x, int y) {
  if (!x || !y) return x + y;
  int c = ++cnt;
  ls[c] = merge(ls[x], ls[y]);
  rs[c] = merge(rs[x], rs[y]);
  return c;
}
void dfs(int x) {
  for (int i = 0; i < vec[x].size(); i++) {
    int v = vec[x][i];
    dfs(v), rt[x] = merge(rt[x], rt[v]);
    if (!pos[x] || pos[v] < pos[x]) pos[x] = pos[v];
  }
}
int query(int x, int l, int r, int u, int v) {
  if (!x) return 0;
  if (l >= u && r <= v) return 1;
  int mid = (l + r) >> 1;
  if (v <= mid)
    return query(ls[x], l, mid, u, v);
  else if (u > mid)
    return query(rs[x], mid + 1, r, u, v);
  else
    return query(ls[x], l, mid, u, mid) | query(rs[x], mid + 1, r, mid + 1, v);
}
void calc(int x) {
  for (int i = 0; i < vec[x].size(); i++) {
    int v = vec[x][i];
    if (query(rt[g[x]], 1, n, pos[v] - maxl[v] + maxl[x], pos[v] - 1))
      f[v] = f[x] + 1, g[v] = v;
    else
      f[v] = f[x], g[v] = g[x];
    calc(v);
  }
}
int main() {
  scanf("%d%s", &n, s + 1);
  int las = 1, ans = 0;
  for (int i = 1; i <= n; i++)
    las = add_char(las, s[i] - 'a'), pos[las] = i, mdf(rt[las], 1, n, i);
  for (int i = 2; i <= tot; i++) vec[slink[i]].push_back(i);
  dfs(1);
  for (int i = 0; i < vec[1].size(); i++)
    f[vec[1][i]] = 1, g[vec[1][i]] = vec[1][i], calc(vec[1][i]);
  for (int i = 2; i <= tot; i++) ans = max(ans, f[i]);
  printf("%d", ans);
  return 0;
}
