#include <bits/stdc++.h>
using namespace std;
int read() {
  int nm = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) nm = nm * 10 + c - '0';
  return nm * f;
}
int fa[100010], sz[100010], son[100010], dfn[100010], dft, top[100010],
    deep[100010], n, q;
vector<int> to[100010];
void dfs(int now, int f) {
  deep[now] = deep[f] + 1;
  sz[now] = 1;
  for (int i = 0; i < to[now].size(); i++) {
    int vj = to[now][i];
    dfs(vj, now);
    if (sz[son[now]] < sz[vj]) son[now] = vj;
    sz[now] += sz[vj];
  }
}
void dfs(int now) {
  dfn[now] = ++dft;
  if (son[now]) {
    top[son[now]] = top[now];
    dfs(son[now]);
  }
  for (int i = 0; i < to[now].size(); i++) {
    int vj = to[now][i];
    if (vj == son[now]) continue;
    top[vj] = vj;
    dfs(vj);
  }
}
int len[100010 << 2], mx[100010 << 2], s[100010 << 2], laz[100010 << 2];
void pushup(int now) {
  mx[now] = max(mx[now << 1 | 1], mx[now << 1] + s[now << 1 | 1]);
  s[now] = s[now << 1] + s[now << 1 | 1];
}
void add(int now) {
  laz[now] = 1;
  mx[now] = -1, s[now] = -len[now];
}
void pushdown(int now) {
  if (!laz[now]) return;
  add(now << 1);
  add(now << 1 | 1);
  laz[now] = 0;
}
void build(int l, int r, int now) {
  len[now] = r - l + 1;
  if (l == r) {
    mx[now] = s[now] = -1;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, now << 1), build(mid + 1, r, now << 1 | 1);
  pushup(now);
}
void modify(int l, int r, int now, int pl, int v) {
  if (l > pl || r < pl) return;
  if (l == r) {
    mx[now] += v, s[now] += v;
    return;
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  modify(l, mid, now << 1, pl, v), modify(mid + 1, r, now << 1 | 1, pl, v);
  pushup(now);
}
void cover(int l, int r, int now, int ln, int rn) {
  if (l > rn || r < ln) return;
  if (l >= ln && r <= rn) {
    add(now);
    return;
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  cover(l, mid, now << 1, ln, rn), cover(mid + 1, r, now << 1 | 1, ln, rn);
  pushup(now);
}
pair<int, int> biao, tmp;
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return make_pair(max(b.first, a.first + b.second), a.second + b.second);
}
pair<int, int> que(int l, int r, int now, int ln, int rn) {
  if (l >= ln && r <= rn) return make_pair(mx[now], s[now]);
  int mid = (l + r) >> 1;
  pushdown(now);
  if (rn <= mid) return que(l, mid, now << 1, ln, rn);
  if (ln > mid) return que(mid + 1, r, now << 1 | 1, ln, rn);
  return que(l, mid, now << 1, ln, rn) + que(mid + 1, r, now << 1 | 1, ln, rn);
}
int query(int x) {
  tmp = biao;
  for (; x; x = fa[top[x]]) {
    tmp = que(1, n, 1, dfn[top[x]], dfn[x]) + tmp;
  }
  return tmp.first;
}
int main() {
  biao = make_pair(-0x3e3e3e3e, 0);
  n = read(), q = read();
  for (int i = 2; i <= n; i++) fa[i] = read(), to[fa[i]].push_back(i);
  dfs(1, 1);
  top[1] = 1;
  dfs(1);
  build(1, n, 1);
  while (q--) {
    int op = read(), x = read();
    if (op == 1) {
      modify(1, n, 1, dfn[x], 1);
    }
    if (op == 2) {
      int t = query(x);
      modify(1, n, 1, dfn[x], -(t + 1));
      if (sz[x] > 1) cover(1, n, 1, dfn[x] + 1, dfn[x] + sz[x]);
    }
    if (op == 3) {
      puts(query(x) >= 0 ? "black" : "white");
    }
  }
  return 0;
}
