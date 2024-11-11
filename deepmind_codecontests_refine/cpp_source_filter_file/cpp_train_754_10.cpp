#include <bits/stdc++.h>
using namespace std;
char _buf[100000], *_op(_buf), *_ed(_buf);
inline int getint() {
  int _s = 0, _f = 1;
  char _ch = (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin),
                             _op == _ed)
                  ? EOF
                  : *_op++);
  while (!('0' <= _ch && _ch <= '9'))
    (_ch == '-') && (_f = -1),
        _ch =
            (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin),
                            _op == _ed)
                 ? EOF
                 : *_op++);
  while (('0' <= _ch && _ch <= '9'))
    _s = _s * 10 + _ch - 48,
    _ch = (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin),
                          _op == _ed)
               ? EOF
               : *_op++);
  return _s * _f;
}
const int N = 5e5 + 2, INF = 0x3f3f3f3f;
set<int> mp[N];
int T, n, m, q, ans;
int w[N], a[N], b[N], id[N];
int fa[N], siz[N], tag[N];
int opt[N], val[N], dis[N][2];
vector<int> cha[N], now[N];
inline void input() {
  n = getint(), m = getint(), q = getint();
  for (int i = 1; i <= n; i++) w[i] = getint(), id[w[i]] = i;
  for (int i = 1; i <= m; i++) a[i] = getint(), b[i] = getint(), tag[i] = 1;
  for (int i = 1; i <= q; i++) opt[i] = getint(), val[i] = getint();
}
inline void merge(int x, int y) {
  if ((x = fa[x]) == (y = fa[y])) return;
  if (siz[x] < siz[y]) swap(x, y);
  for (int v : now[y]) now[x].push_back(v), fa[v] = x;
  siz[x] += siz[y];
}
inline void init(int x = 0, int y = 0) {
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1, now[i].push_back(i);
  for (int i = 1; i <= q; i++)
    if (opt[i] == 2) tag[val[i]] = 0;
  for (int i = 1; i <= m; i++)
    if (tag[i]) merge(a[i], b[i]);
  for (int i = q; i >= 1; i--)
    if (opt[i] == 2) {
      x = a[val[i]], y = b[val[i]];
      if ((x = fa[x]) == (y = fa[y])) continue;
      if (siz[x] < siz[y]) swap(x, y);
      for (int v : now[y]) now[x].push_back(y), fa[v] = x;
      fa[y] = x, siz[x] += siz[y], dis[i][0] = x, dis[i][1] = y;
    }
  for (int i = 1; i <= n; i++) mp[fa[i]].insert(w[i]);
}
inline void work() {
  int x, y, p;
  for (int i = 1; i <= q; i++)
    if (opt[i] == 1) {
      x = fa[val[i]];
      p = *--mp[x].end();
      cout << p << '\n';
      w[id[p]] = 0;
      mp[x].erase(p);
      mp[x].insert(0);
    } else if (dis[i][0]) {
      x = dis[i][0], y = dis[i][1];
      for (int j = 1; j <= siz[y]; j++) now[x].pop_back();
      siz[x] -= siz[y];
      for (int v : now[y]) {
        fa[v] = y, mp[y].insert(w[v]);
        if (mp[x].find(w[v]) != mp[x].end()) mp[x].erase(w[v]);
      }
      mp[x].insert(0);
    }
}
int main() {
  input();
  init();
  work();
  return 0;
}
