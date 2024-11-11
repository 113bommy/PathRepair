#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 28;
const long long LINF = 1ll << 61;
inline long long getnum() {
  register long long r = 0;
  register bool ng = 0;
  register char c;
  c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') ng = 1, c = getchar();
  while (c != ' ' && c != '\n') r = r * 10 + c - '0', c = getchar();
  if (ng) r = -r;
  return r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline void putsp() { putchar(' '); }
inline void putendl() { putchar('\n'); }
inline char mygetchar() {
  register char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
int n, ans[2011];
inline int rev(int x) { return 2 * n - x + 1; }
struct twoSAT {
  vector<pair<int, int> > v;
  bool adj[2011][2011];
  bitset<2048> to[2011], tor[2011], tab[2011];
  bool ok;
  void construct() {
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < v.size(); i++) {
      if (v[i].first < 0) v[i].first = rev(-v[i].first);
      if (v[i].second < 0) v[i].second = rev(-v[i].second);
      adj[rev(v[i].first)][v[i].second] = 1;
      adj[rev(v[i].second)][v[i].first] = 1;
    }
    for (int i = 1; i <= 2 * n; i++)
      for (int j = 1; j <= 2 * n; j++) to[i][j] = adj[i][j];
    for (int i = 1; i <= 2 * n; i++) to[i][i] = 1;
    for (int k = 1; k <= 2 * n; k++)
      for (int i = 1; i <= 2 * n; i++)
        if (adj[k][i]) to[k] |= to[i];
    for (int i = 1; i <= 2 * n; i++)
      for (int j = 1; j <= 2 * n; j++) tor[i][j] = to[j][i];
    ok = 1;
    for (int i = 1; i <= n; i++)
      if (to[i][rev(i)] && to[rev(i)][i]) {
        ok = 0;
        return;
      }
    for (int i = 1; i <= 2 * n; i++) {
      for (int j = 1; j <= 2 * n; j++) {
        if (to[i][j]) {
          tab[i] |= tor[rev(j)];
        }
      }
    }
  }
  bool vis[2011];
  void select(int i) {
    for (int j = 1; j <= 2 * n; j++)
      if (to[i][j]) vis[rev(j)] = 1;
  }
  void check(int x, int y) {
    if (!ok) return;
    if (!tab[x][y]) {
      memset(vis, 0, sizeof(vis));
      select(x);
      select(y);
      for (int i = 1; i <= n; i++) {
        bool ok = 1;
        for (int j = 1; j <= 2 * n && ok; j++) {
          if (to[i][j]) {
            ok &= !to[j][rev(j)] && !vis[j];
          }
        }
        if (ok) {
          select(i);
        }
        putnum(ok), putsp();
      }
      exit(0);
    }
  }
} g1, g2;
int main() {
  int m1, m2;
  n = getnum(), m1 = getnum(), m2 = getnum();
  for (int i = 1; i <= m1; i++) {
    int x, y;
    x = getnum(), y = getnum();
    g1.v.push_back(make_pair(x, y));
  }
  for (int i = 1; i <= m1; i++) {
    int x, y;
    x = getnum(), y = getnum();
    g2.v.push_back(make_pair(x, y));
  }
  g1.construct();
  g2.construct();
  for (int i = 0; i < g1.v.size(); i++) {
    pair<int, int> p = g1.v[i];
    g2.check(rev(p.first), rev(p.second));
  }
  for (int i = 0; i < g2.v.size(); i++) {
    pair<int, int> p = g2.v[i];
    g1.check(rev(p.first), rev(p.second));
  }
  puts("SIMILAR");
  return 0;
}
