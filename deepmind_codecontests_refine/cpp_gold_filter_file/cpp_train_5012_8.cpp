#include <bits/stdc++.h>
using namespace std;
struct no {
  int l, r, c;
};
int operator<(no x, no y) { return x.l < y.l; }
set<no> s[500010];
inline int rd() {
  int d = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    d = d * 10 + ch - '0';
    ch = getchar();
  }
  return d;
}
int h[500010], v[500010 * 2], nxt[500010 * 2], ec, dep[500010], p[500010],
    tp[500010], id[500010], ct, bt[500010], n, m, sz[500010], ss[500010], cc,
    fa[500010], pd[500010];
void mod(int x, int y) {
  for (; x < 500010; x += x & -x) bt[x] += y;
}
int q(int x) {
  int r = 0;
  for (; x; x -= x & -x) r += bt[x];
  return r;
}
void add(int x, int y) {
  v[++ec] = y;
  nxt[ec] = h[x];
  h[x] = ec;
}
void d1(int x) {
  sz[x] = 1;
  dep[x] = dep[fa[x]] + 1;
  for (int i = h[x]; i; i = nxt[i])
    if (v[i] != fa[x]) {
      fa[v[i]] = x;
      d1(v[i]);
      sz[x] += sz[v[i]];
      if (sz[v[i]] > sz[p[x]]) p[x] = v[i];
    }
}
set<no>::iterator sp(set<no>& s, int p) {
  set<no>::iterator it = s.lower_bound((no){p, 0, 0});
  if (it != s.end() && it->l == p) return it;
  it--;
  int l = it->l, r = it->r, c = it->c;
  s.erase(it);
  s.insert((no){l, p - 1, c});
  return s.insert((no){p, r, c}).first;
}
void ins(set<no>& s, int l, int r, int c) {
  set<no>::iterator ir = sp(s, r + 1), il = sp(s, l);
  for (set<no>::iterator it = il; it != ir; it++)
    mod(it->c, -(it->r - it->l + 1));
  mod(c, r - l + 1);
  s.erase(il, ir);
  s.insert((no){l, r, c});
}
void d2(int x, int t) {
  tp[x] = t;
  pd[x] = id[x] = ++ct;
  if (p[x]) {
    d2(p[x], t);
    pd[x] = max(pd[x], pd[p[x]]);
  }
  if (x == t) s[x].insert((no){id[x], pd[x], 500010});
  for (int i = h[x]; i; i = nxt[i])
    if (!tp[v[i]]) d2(v[i], v[i]);
}
int lca(int x, int y) {
  while (tp[x] != tp[y]) {
    if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
    x = fa[tp[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
int d(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)] + 1; }
void up(int x, int y) {
  ss[++cc] = x;
  while (tp[x] != tp[y]) {
    if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
    ins(s[tp[x]], id[tp[x]], id[x], cc);
    x = fa[tp[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ins(s[tp[x]], id[x], id[y], cc);
}
int qu(int x) {
  int c = sp(s[tp[x]], id[x])->c;
  return q(c - 1) + d(x, ss[c]);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int x, y;
    x = rd();
    y = rd();
    add(x, y);
    add(y, x);
  }
  int la = n;
  d1(1);
  d2(1, 1);
  for (int i = 1; i < n; i++) up(i, i + 1);
  while (m--) {
    char s[5];
    scanf("%s", s);
    int x, y;
    x = rd();
    if (s[0] == 'u') {
      up(la, x);
      la = x;
    } else if (s[0] == 'w')
      cout << qu(x) << '\n';
    else {
      y = rd();
      if (qu(x) < qu(y))
        cout << x << '\n';
      else
        cout << y << '\n';
    }
  }
}
