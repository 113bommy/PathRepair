#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
pair<int, int> f[maxn][2][2];
bool u[maxn][2][2];
vector<int> root;
int col[maxn], p[maxn];
vector<int> g[maxn];
int n;
vector<pair<int, int> > ans;
int par[maxn];
int croot;
inline pair<int, int> operator+(const pair<int, int>& a,
                                const pair<int, int>& b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
inline pair<int, int> operator-(const pair<int, int>& a,
                                const pair<int, int>& b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
int parent(int x) {
  if (par[x] != x) par[x] = parent(par[x]);
  return par[x];
}
void merge(int x, int y) {
  x = parent(x), y = parent(y);
  par[x] = y;
}
pair<int, int> func(int x, int lst, int cyc) {
  if (u[x][lst][cyc]) return f[x][lst][cyc];
  pair<int, int>& res = f[x][lst][cyc];
  u[x][lst][cyc] = true;
  res = make_pair(0, 0);
  if (lst) {
    for (__typeof((g[x]).begin()) it = (g[x]).begin(); it != (g[x]).end(); ++it)
      res = res + func(*it, cyc && *it == p[croot], cyc);
  } else {
    pair<int, int> tot(0, 0);
    for (__typeof((g[x]).begin()) it = (g[x]).begin(); it != (g[x]).end(); ++it)
      tot = tot + func(*it, cyc && *it == p[croot], cyc);
    res = max(res, tot);
    for (__typeof((g[x]).begin()) it = (g[x]).begin(); it != (g[x]).end(); ++it)
      if (!(cyc && *it == p[croot])) {
        pair<int, int> cur = tot - func(*it, 0, cyc);
        cur = cur + func(*it, 1, cyc) + pair<int, int>(1, col[x] != col[*it]);
        res = max(res, cur);
      }
  }
  return res;
}
void build(int x, int lst, int cyc) {
  if (lst) {
    for (__typeof((g[x]).begin()) it = (g[x]).begin(); it != (g[x]).end(); ++it)
      build(*it, cyc && *it == p[croot], cyc);
  } else {
    pair<int, int> tot(0, 0);
    for (__typeof((g[x]).begin()) it = (g[x]).begin(); it != (g[x]).end(); ++it)
      tot = tot + func(*it, cyc && *it == p[croot], cyc);
    if (tot == func(x, lst, cyc)) {
      for (__typeof((g[x]).begin()) it = (g[x]).begin(); it != (g[x]).end();
           ++it)
        build(*it, cyc && *it == p[croot], cyc);
      return;
    }
    for (__typeof((g[x]).begin()) it = (g[x]).begin(); it != (g[x]).end(); ++it)
      if (!(cyc && *it == p[croot])) {
        pair<int, int> cur = tot - func(*it, 0, cyc);
        cur = cur + func(*it, 1, cyc) + pair<int, int>(1, col[x] != col[*it]);
        if (cur == func(x, lst, cyc)) {
          ans.push_back(make_pair(x, *it));
          build(*it, 1, cyc);
          for (__typeof((g[x]).begin()) jt = (g[x]).begin(); jt != (g[x]).end();
               ++jt)
            if (*it != *jt) build(*jt, cyc && *jt == p[croot], cyc);
          break;
        }
      }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) scanf("%d %d", p + i, col + i), --p[i];
  for (int i = 0; i < (n); ++i) par[i] = i;
  for (int i = 0; i < (n); ++i) {
    if (parent(i) != parent(p[i]))
      merge(i, p[i]), g[p[i]].push_back(i);
    else
      root.push_back(i);
  }
  pair<int, int> res(0, 0);
  for (__typeof((root).begin()) it = (root).begin(); it != (root).end(); ++it) {
    croot = *it;
    pair<int, int> cur =
        max(func(*it, 0, 0),
            func(*it, 1, 1) + pair<int, int>(1, col[*it] != col[p[*it]]));
    res = res + cur;
    if (cur == func(*it, 0, 0))
      build(*it, 0, 0);
    else
      build(*it, 1, 1), ans.push_back(make_pair(*it, p[*it]));
  }
  printf("%d %d\n", res.first, res.second);
  for (__typeof((ans).begin()) it = (ans).begin(); it != (ans).end(); ++it)
    printf("%d %d\n", it->first + 1, it->second + 1);
  return 0;
}
