#include <bits/stdc++.h>
using namespace std;
int d[100020], f[100020][17], p[100020], r[100020];
int n, m, x, y, w, cnt, q;
vector<pair<int, int> > a[100020];
long long z, g[100020];
set<int> s;
set<int>::iterator it, L, R;
char o;
int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  int w = d[x] - d[y];
  for (int i = 0; i < 17; i++)
    if (w >> i & 1) x = f[x][i];
  if (x == y) return x;
  for (int i = 17; i--;)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
void dfs(int x, int y, long long w) {
  d[x] = d[y] + 1;
  g[x] = w;
  f[x][0] = y;
  p[r[x] = ++cnt] = x;
  for (int i = 1; i < 17; i++) f[x][i] = f[f[x][i - 1]][i - 1];
  for (__typeof(a[x].begin()) i = a[x].begin(); i != a[x].end(); i++)
    if (i->first != y) dfs(i->first, x, w + i->second);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d", &x, &y, &w);
    a[x].push_back(pair<int, int>(y, w));
    a[y].push_back(pair<int, int>(x, w));
  }
  dfs(1, 0, 0);
  for (scanf("%d", &q); q--;) {
    scanf(" %c", &o);
    if (o == '?')
      cout << z << endl;
    else {
      scanf("%d", &x);
      it = s.insert(r[x]).first, L = it, R = it;
      if (L-- == s.begin()) L = --s.end();
      if (++R == s.end()) R = s.begin();
      long long l =
          g[x] + g[lca(p[*L], p[*R])] - g[lca(x, p[*L])] - g[lca(x, p[*R])];
      if (o == '+')
        z += l;
      else
        z -= l, s.erase(r[x]);
    }
  }
}
