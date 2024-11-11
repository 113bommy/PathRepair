#include <bits/stdc++.h>
using namespace std;
class JuRuo {
  bool sb;
  int neg_IQ;
} LHM;
int ey[1000000], enext[1000000], ec[1000000], g[1000000], col[1000000],
    dep[1000000], etot, n, m, ans, tot, fa[1000000];
pair<int, int> q[1000000];
int gcd(int x, int y) { return (y == 0) ? x : gcd(y, x % y); }
int get(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  return dep[x] - dep[y] + 1;
}
void builde(int e, int x, int y, int c) {
  ey[e] = y, enext[e] = g[x], ec[e] = c, g[x] = e;
}
int main() {
  scanf("%d%d", &n, &m);
  ans = -1;
  memset(g, 0xff, sizeof(g));
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    builde(2 * i, x, y, 1);
    builde(2 * i + 1, y, x, -1);
  }
  memset(col, 0, sizeof(col));
  for (int r = 1; r <= n; r++)
    if (col[r] == 0) {
      q[tot = 1] = make_pair(1, g[r]);
      fa[r] = 0;
      dep[r] = 0;
      while (tot) {
        int x = q[tot].first, &e = q[tot].second;
        if (e == g[x]) {
          col[x] = 1;
        }
        if (e == -1) {
          tot--;
          col[x] = 2;
          continue;
        }
        int y = ey[e], c = ec[e];
        e = enext[e];
        if (col[y] == 0) {
          q[++tot] = make_pair(y, g[y]);
          fa[y] = x;
          dep[y] = dep[x] + c;
          continue;
        }
        int d = abs(dep[x] + c - dep[y]) + 1;
        if (ans == -1)
          ans = d;
        else
          ans = gcd(ans, d);
      }
    }
  if (ans == -1)
    cout << n << endl;
  else
    cout << ans << endl;
  return 0;
}
