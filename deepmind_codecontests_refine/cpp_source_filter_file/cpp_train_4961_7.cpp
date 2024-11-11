#include <bits/stdc++.h>
using namespace std;
pair<int, int> q[400010];
vector<pair<pair<int, int>, int> > o[800010];
map<int, int> d[200010], h[200010];
int num[35];
int top, n, m, T;
int cas[200010], x[200010], y[200010], z[200010], ans[200010];
int fa[200010], siz[200010], g[200010];
inline int read() {
  int ans = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 1) + (ans << 3) + ch - '0', ch = getchar();
  return ans;
}
inline int find(int x) {
  if (fa[x] == x) return x;
  return find(fa[x]);
}
inline int findt(int x) {
  if (fa[x] == x) return 0;
  return g[x] ^ find(fa[x]);
}
void ins(int x, int y, int z, int k) {
  if (x > y) swap(x, y);
  d[x][y] = k;
  h[x][y] = z;
}
void ins(int rex, int l, int r, int x, int y, pair<pair<int, int>, int> z) {
  if (l == x && r == y) {
    o[rex].push_back(z);
    return;
  }
  int mid = (l + r) >> 1;
  if (y <= mid)
    ins(rex + rex, l, mid, x, y, z);
  else if (x > mid)
    ins(rex + rex + 1, mid + 1, r, x, y, z);
  else
    ins(rex + rex, l, mid, x, mid, z),
        ins(rex + rex + 1, mid + 1, r, mid + 1, y, z);
}
void del(int x, int y, int k) {
  if (x > y) swap(x, y);
  ins(1, 0, T, d[x][y], k, make_pair(make_pair(x, y), h[x][y]));
  d[x].erase(y);
}
void add(int k) {
  for (int i = 29; i >= 0; i--)
    if (k >> i & 1) {
      if (!num[i]) {
        num[i] = k;
        return;
      } else
        k ^= num[i];
    }
}
void calc(int rex) {
  for (pair<pair<int, int>, int> u : o[rex]) {
    int x = u.first.first, y = u.first.second, z = u.second;
    int dx = find(x), dy = find(y);
    if (dx == dy)
      add(findt(x) ^ findt(y) ^ z);
    else {
      if (siz[dx] > siz[dy]) swap(dx, dy);
      g[dx] = z ^ findt(x) ^ findt(y);
      siz[dy] += siz[dx];
      fa[dx] = dy;
      q[++top] = make_pair(dx, dy);
    }
  }
}
void del(pair<int, int> num) {
  int x = num.first, y = num.second;
  siz[y] -= siz[x];
  fa[x] = x;
  g[x] = 0;
}
void solve(int rex, int l, int r) {
  calc(rex);
  if (l == r) {
    if (cas[l] == 3) {
      ans[l] = findt(x[l]) ^ findt(y[l]);
      for (int i = 29; i >= 0; i--)
        if (ans[l] >> i & 1) ans[l] ^= num[i];
    }
    return;
  }
  int mid = (l + r) >> 1;
  int tmp[30];
  int pos = top;
  for (int i = 0; i < 30; i++) tmp[i] = num[i];
  solve(rex + rex, l, mid);
  while (top > pos) del(q[top--]);
  for (int i = 0; i < 30; i++) num[i] = tmp[i];
  solve(rex + rex + 1, mid + 1, r);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    ins(x, y, z, 0);
  }
  T = read();
  for (int i = 1; i <= T; i++) {
    cas[i] = read();
    if (cas[i] == 1)
      x[i] = read(), y[i] = read(), z[i] = read(), ins(x[i], y[i], z[i], i);
    else if (cas[i] == 2)
      x[i] = read(), y[i] = read(), del(x[i], y[i], i);
    else
      x[i] = read(), y[i] = read();
  }
  for (int i = 1; i <= n; i++) {
    vector<int> G;
    for (pair<int, int> t : d[i]) G.push_back(t.first);
    for (int v : G) del(i, v, T);
  }
  solve(1, 0, T);
  for (int i = 1; i <= T; i++)
    if (cas[i] == 3) printf("%d\n", ans[i]);
}
