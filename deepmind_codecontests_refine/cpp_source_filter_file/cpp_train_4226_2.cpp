#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
inline pair<pair<int, int>, pair<int, int> > make(int x, int y, int g, int s) {
  return pair<pair<int, int>, pair<int, int> >(pair<int, int>(g, s),
                                               pair<int, int>(x, y));
}
int n, m;
int G, S;
pair<pair<int, int>, pair<int, int> > r[1 << 17];
inline void init() {
  int x, y, g, s;
  scanf("%d%d", &n, &m);
  scanf("%d%d", &G, &S);
  int tm = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d%d", &x, &y, &g, &s);
    if (x == y) continue;
    --x;
    --y;
    r[tm++] = make(x, y, g, s);
  }
  m = tm;
  sort(r, r + m);
}
int CNT;
pair<int, int> p[201];
vector<vector<pair<int, int> > > a;
int was[201];
int MX;
void dfs(int x) {
  was[x] = 1;
  ++CNT;
  int k = (int)a[x].size();
  for (int i = 0; i < k; ++i) {
    int y = a[x][i].first;
    int w = a[x][i].second;
    if (was[y]) continue;
    MX = max(MX, w);
    p[y] = pair<int, int>(x, w);
    dfs(y);
  }
}
inline void remove(int x, int y) {
  int k = (int)a[x].size();
  for (int i = 0; i < k; ++i) {
    if (a[x][i].first != y) continue;
    swap(a[x][i], a[x][k - 1]);
    a[x].pop_back();
    break;
  }
}
int main() {
  init();
  long long res = -1;
  a.resize(n);
  for (int i = 0; i < m; ++i) {
    int x = r[i].second.first;
    int y = r[i].second.second;
    int g = r[i].first.first;
    int s = r[i].first.second;
    memset(was, 0, sizeof was);
    dfs(x);
    if (!was[y]) {
      a[x].push_back(pair<int, int>(y, s));
      a[y].push_back(pair<int, int>(x, s));
    } else {
      int from, to, w;
      int z = y;
      from = p[z].first;
      to = z;
      w = p[z].second;
      while (z != x) {
        if (p[z].second > w) {
          from = p[z].first;
          to = z;
          w = p[z].second;
        }
        z = p[z].first;
      }
      if (s > w) continue;
      a[x].push_back(pair<int, int>(x, s));
      a[y].push_back(pair<int, int>(y, s));
      remove(from, to);
      remove(to, from);
    }
    memset(was, 0, sizeof was);
    CNT = 0;
    MX = 0;
    dfs(x);
    if (CNT != n) continue;
    long long cur = (long long)MX * (long long)S + (long long)G * (long long)g;
    if (res == -1) res = cur;
    res = min(res, cur);
  }
  printf("%lld\n", res);
  return 0;
}
