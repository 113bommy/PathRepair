#include <bits/stdc++.h>
using namespace std;
int n, m, num, hd, Root, dep, mh[200010UL], sta[200010UL], siz[200010UL],
    ad[200010UL], mx[200010UL], tr[200010UL], w[200010UL], fa[200010UL],
    mn[200010UL], val[200010UL], st[200010UL], ed[200010UL], ch[200010UL][2];
vector<int> G[200010UL];
void Dfs(int x) {
  st[x] = ++num, val[num] = ++dep, tr[num] = x;
  for (int i = 0, r = G[x].size(); i < r; ++i) Dfs(G[x][i]);
  ed[x] = ++num, val[num] = dep--, tr[num] = x;
  mh[st[x]] = ed[x];
  return;
}
void Update(int x) {
  if (!x) return;
  siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
  mn[x] = mx[x] = w[x];
  if (ch[x][0])
    mn[x] = min(mn[x], mn[ch[x][0]]), mx[x] = max(mx[x], mx[ch[x][0]]);
  if (ch[x][1])
    mn[x] = min(mn[x], mn[ch[x][1]]), mx[x] = max(mx[x], mx[ch[x][1]]);
  return;
}
void Build(int l, int r, int &rt) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  w[rt = mid] = val[mid];
  Build(l, mid - 1, ch[rt][0]), Build(mid + 1, r, ch[rt][1]);
  if (ch[rt][0]) fa[ch[rt][0]] = rt;
  if (ch[rt][1]) fa[ch[rt][1]] = rt;
  Update(rt);
  return;
}
void Rotate(int x, int k) {
  int y = ch[x][k ^ 1];
  ch[x][k ^ 1] = ch[y][k];
  ch[y][k] = x;
  fa[ch[x][k ^ 1]] = x;
  if (ch[fa[x]][0] == x)
    ch[fa[x]][0] = y;
  else if (ch[fa[x]][1] == x)
    ch[fa[x]][1] = y;
  fa[y] = fa[x], fa[x] = y;
  Update(x);
  return;
}
void Mark(int x, int k) {
  if (!x) return;
  ad[x] += k;
  w[x] += k, mn[x] += k, mx[x] += k;
  return;
}
void Push_down(int x) {
  if (!x || ad[x] == 0) return;
  Mark(ch[x][0], ad[x]), Mark(ch[x][1], ad[x]);
  ad[x] = 0;
  return;
}
void Splay(int p, int gl) {
  sta[++hd] = p;
  for (int i = p; fa[i] != gl; i = fa[i]) sta[++hd] = fa[i];
  while (hd) Push_down(sta[hd--]);
  while (fa[p] != gl) {
    int x = fa[p], y = fa[x];
    if (fa[x] == gl)
      Rotate(x, ch[x][0] == p);
    else {
      if ((ch[x][0] == p) == (ch[y][0] == x))
        Rotate(y, ch[y][0] == x), Rotate(x, ch[x][0] == p);
      else
        Rotate(x, ch[x][0] == p), Rotate(y, ch[y][0] == p);
    }
  }
  Update(p);
  if (gl == 0) Root = p;
  return;
}
int Find(int x) {
  Splay(x, 0);
  return siz[ch[x][0]] + 1;
}
int Get_dis(int x, int y) {
  if (Find(st[x]) > Find(st[y])) swap(x, y);
  Splay(st[x], 0), Splay(st[y], Root);
  int t = ch[st[y]][0] ? w[ch[st[y]][0]] - 1 : 1e9;
  int Min = min(t, min(w[st[y]], w[st[x]]));
  int x1 = w[st[x]];
  Splay(st[y], 0);
  int x2 = w[st[y]];
  return x1 + x2 - 2 * Min;
}
int Get(int rt, int k) {
  int x = rt;
  while (true) {
    Push_down(x);
    if (ch[x][1] && mn[ch[x][1]] <= k && mx[ch[x][1]] >= k)
      x = ch[x][1];
    else if (w[x] == k)
      return x;
    else
      x = ch[x][0];
  }
}
int Get_pos(int k) {
  int nw = Root;
  while (true) {
    Push_down(nw);
    if (siz[ch[nw][0]] + 1 == k) return nw;
    if (siz[ch[nw][0]] + 1 > k)
      nw = ch[nw][0];
    else
      k -= siz[ch[nw][0]] + 1, nw = ch[nw][1];
  }
}
void Change(int x, int y) {
  Splay(st[x], 0);
  int pr = Get(ch[st[x]][0], w[st[x]] - y);
  pr = mh[pr];
  Splay(ed[x], Root);
  int nw = ch[Root][0];
  while (ch[nw][1]) nw = ch[nw][1];
  Splay(nw, Root);
  ch[nw][1] = ch[ed[x]][1], Update(nw);
  fa[ch[ed[x]][1]] = nw, fa[nw] = 0, Root = nw;
  ch[ed[x]][1] = 0, Update(ed[x]);
  ch[st[x]][0] = 0, Update(st[x]);
  Splay(Get_pos(Find(pr) - 1), 0), Splay(pr, Root);
  ch[pr][0] = st[x], fa[st[x]] = pr;
  Mark(st[x], 1 - y);
  Update(pr), Update(Root);
  return;
}
int main() {
  int x, y, typ;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    for (int j = 1; j <= x; ++j) scanf("%d", &y), G[i].push_back(y);
  }
  Dfs(1), Build(1, num, Root);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &typ);
    if (typ == 1)
      scanf("%d%d", &x, &y), printf("%d\n", Get_dis(x, y));
    else if (typ == 2)
      scanf("%d%d", &x, &y), Change(x, y);
    else if (typ == 3)
      scanf("%d", &x), printf("%d\n", tr[Get(Root, x + 1)]);
  }
  return 0;
}
