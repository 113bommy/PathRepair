#include <bits/stdc++.h>
using namespace std;
const int z = 311;
map<int, int> mp;
map<int, int>::iterator it;
pair<int, pair<int, int> > bg[z * z], *ed, *ti;
pair<int, int> que[z * z], *l, *r;
int a[z][z], b[z][z], ans[z << 1][z << 1];
int fa[2 * z * z], co[2 * z * z], cnt[2 * z * z];
struct lst {
  lst *nxt;
  pair<int, int> pp;
  void maker(lst *&a, int b, int c) {
    nxt = a, pp = make_pair(b, c);
    a = this;
  }
} * sta[2 * z * z], v[z * z], *tot;
int findfa(int a) { return fa[a] == a ? a : fa[a] = findfa(fa[a]); }
int main() {
  int n, m, i, j, x, y, res, now, pre;
  long long ret;
  x = 305, y = 305, res = ret = 0;
  for (i = 1; i <= 303; i++) {
    for (j = 0; j < i * 2 - 1; j++) ans[x--][y] = res++;
    for (j = 0; j < i * 2 - 1; j++) ans[x][y++] = res++;
    for (j = 0; j < i * 2; j++) ans[x++][y] = res++;
    for (j = 0; j < i * 2; j++) ans[x][y--] = res++;
  }
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j]) mp[a[i][j]] = 1;
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      scanf("%d", &b[i][j]);
      if (b[i][j] > 0) mp[b[i][j]] = 1;
    }
  scanf("%d%d", &x, &y);
  x--, y--;
  fa[0] = co[0] = 0, sta[0] = NULL, tot = v;
  for (i = 1, it = mp.begin(); it != mp.end(); i++, it++)
    fa[i] = co[i] = i, cnt[i] = 0, it->second = i, sta[i] = NULL;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (a[i][j]) cnt[mp[a[i][j]]]++;
      if (b[i][j] >= 0 && (i != x || j != y))
        (tot++)->maker(sta[mp[a[i][j]]], i, j);
    }
  *(l = r = que) = make_pair(x, y);
  while (l <= r) {
    x = l->first, y = l->second;
    l++, now = mp[b[x][y]], pre = findfa(mp[a[x][y]]);
    if (!co[pre] || co[pre] == now) continue;
    ret += cnt[pre];
    if (pre != findfa(now)) cnt[fa[pre] = findfa(now)] += cnt[pre];
    ed = bg;
    for (lst *&e = sta[co[pre]]; e; e = e->nxt)
      *(ed++) =
          make_pair(ans[e->pp.first - x + 305][e->pp.second - y + 305], e->pp);
    sort(bg, ed);
    for (ti = bg; ti < ed; ti++) *(++r) = ti->second;
    co[findfa(now)] = now;
  }
  printf("%I64d\n", ret);
  return 0;
}
