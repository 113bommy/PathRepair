#include <bits/stdc++.h>
using namespace std;
int n;
long long v[100100];
vector<int> g[100100];
long long pd[100100][3][3][3];
bool vis[100100][3][3][3];
long long f(int pai, int i, int a, int b, int c, int vo) {
  if (i == g[pai].size()) return 0;
  int x = g[pai][i];
  if (x == vo) return f(pai, i + 1, a, b, c, vo);
  long long &p = pd[x][a][b][c];
  if (!vis[x][a][b][c]) {
    vis[x][a][b][c] = 1;
    if (!c) {
      p = max(f(x, 0, a, b, c, pai), f(pai, i + 1, a, b, c, vo));
      if (!a) p = max(p, f(x, 0, 0, 2, c, pai) + f(pai, i + 1, 2, b, c, vo));
      if (!b) p = max(p, f(x, 0, 2, 0, c, pai) + f(pai, i + 1, a, 2, c, vo));
      if (!a)
        p = max(p, f(x, 0, 0, b, 1, pai) + v[x] + f(pai, i + 1, 2, 2, c, vo));
      if (!a)
        p = max(p, f(x, 0, 0, 2, 1, pai) + v[x] + f(pai, i + 1, 2, b, c, vo));
      if (!b)
        p = max(p, f(x, 0, a, 0, 2, pai) + v[x] + f(pai, i + 1, 2, 2, c, vo));
      if (!b)
        p = max(p, f(x, 0, 2, 0, 2, pai) + v[x] + f(pai, i + 1, a, 2, c, vo));
      if (!a && !b) p = max(p, f(x, 0, 1, 0, 1, pai) + v[x]);
    } else if (c == 1) {
      p = max(p, f(pai, i + 1, a, b, c, vo));
      if (a < 2) {
        p = max(p,
                f(x, 0, 1, 2, 1, pai) + v[x] + f(pai, i + 1, a + 1, b, 1, vo));
        p = max(p,
                f(x, 0, 1, b, 1, pai) + v[x] + f(pai, i + 1, a + 1, 2, 1, vo));
      }
      if (b < 2) {
        p = max(p, f(x, 0, 2, 0, 2, pai) + v[x] + f(pai, i + 1, a, 2, 1, vo));
        p = max(p, f(x, 0, 2, 0, 0, pai) + f(pai, i + 1, a, 2, 1, vo));
      }
    } else if (c == 2) {
      p = max(p, f(pai, i + 1, a, b, c, vo));
      if (b < 2) {
        p = max(p,
                f(x, 0, 2, 1, 2, pai) + v[x] + f(pai, i + 1, a, b + 1, 2, vo));
        p = max(p,
                f(x, 0, a, 1, 2, pai) + v[x] + f(pai, i + 1, 2, b + 1, 2, vo));
      }
      if (a < 2) {
        p = max(p, f(x, 0, 0, 2, 1, pai) + v[x] + f(pai, i + 1, 2, b, 2, vo));
        p = max(p, f(x, 0, 0, 2, 0, pai) + f(pai, i + 1, 2, b, 2, vo));
      }
    }
  }
  return p;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &v[i]);
  g[0].push_back(1);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  printf("%lld\n", f(0, 0, 0, 0, 0, 0));
  return 0;
}
