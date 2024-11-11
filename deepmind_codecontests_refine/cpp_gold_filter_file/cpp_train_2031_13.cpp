#include <bits/stdc++.h>
using namespace std;
const int N = 13;
const int M = 1 << N;
long long f[N][M];
bool edg[20][20];
int n, m, q;
pair<int, int> pa[M];
struct node {
  int a, b, c;
} lca[105];
int main() {
  auto ck = [&](int pos, int mask) { return (mask >> pos) & 1; };
  function<long long(int, int)> dfs = [&](int u, int mask) {
    long long &res = f[u][mask];
    if (res != -1) return res;
    res = 0;
    mask ^= 1 << u;
    int pos;
    for (pos = 0; pos < n; pos++)
      if (ck(pos, mask)) break;
    for (int i = mask; i; i = (i - 1) & mask) {
      if (ck(pos, i)) {
        bool ok = true;
        for (int j = 1; j <= q; j++) {
          if (lca[j].c == u && ck(lca[j].a, i) && ck(lca[j].b, i)) {
            ok = false;
            break;
          }
          if (ck(lca[j].c, i) && (!ck(lca[j].a, i) || !ck(lca[j].b, i))) {
            ok = false;
            break;
          }
        }
        if (ok == false) continue;
        for (int j = 1; j <= m; j++) {
          if (pa[j].first != u && pa[j].second != u &&
              ck(pa[j].first, i) + ck(pa[j].second, i) == 1) {
            ok = false;
            break;
          }
        }
        if (ok == false) continue;
        int cnt = 0, v;
        for (int j = 0; j < n; j++) {
          if (edg[u][j] && ck(j, i)) cnt++, v = j;
        }
        if (cnt > 1)
          continue;
        else if (cnt == 1)
          res += dfs(v, i) * dfs(u, i ^ mask ^ (1 << u));
        else {
          for (int j = 0; j < n; j++) {
            if (ck(j, i)) res += dfs(j, i) * dfs(u, i ^ mask ^ (1 << u));
          }
        }
      }
    }
    return res;
  };
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    pa[i] = make_pair(x, y);
    edg[x][y] = edg[y][x] = true;
  }
  for (int i = 1; i <= q; i++)
    scanf("%d %d %d", &lca[i].a, &lca[i].b, &lca[i].c), lca[i].a--, lca[i].b--,
        lca[i].c--;
  memset(f, -1, sizeof f);
  for (int i = 0; i < n; i++) f[i][1 << i] = 1;
  cout << dfs(0, (1 << n) - 1);
}
