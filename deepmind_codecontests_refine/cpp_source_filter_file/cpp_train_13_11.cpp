#include <bits/stdc++.h>
using namespace std;
const int Q = 1 << 18;
struct gra {
  int las[Q], e[Q], nn[Q], inc;
  void ins(int x, int y) {
    e[++inc] = y;
    nn[inc] = las[x];
    las[x] = inc;
  }
} g, f;
int mex[Q];
int vis[Q];
int h[Q], sm[Q];
int q[Q];
int in[Q];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  for (int i = 1, x, y; i <= m; i++)
    scanf("%d%d", &x, &y), g.ins(x, y), f.ins(y, x), ++in[x];
  int hd = 1, tl = 0;
  for (int i = 1; i <= n; i++)
    if (!in[i]) q[++tl] = i;
  for (int t = 1; t <= n; t++) {
    int x = q[hd++];
    for (int t = g.las[x]; t; t = g.nn[t]) {
      int y = g.e[t];
      vis[mex[y]] = x;
    }
    for (mex[x] = 0; vis[mex[x]] == x; ++mex[x])
      ;
    for (int t = f.las[x]; t; t = f.nn[t]) {
      int y = f.e[t];
      --in[y];
      if (!in[y]) q[++tl] = y;
    }
  }
  int flag = 0;
  for (int i = 1; i <= n; i++) sm[mex[i]] ^= h[i];
  for (int p = n; p; --p)
    if (sm[p]) {
      puts("WIN");
      for (int i = 1; i <= n; i++)
        if (mex[i] == p && (h[i] ^ sm[p]) < h[i]) {
          h[i] ^= sm[p];
          for (int t = g.las[i]; t; t = g.nn[t]) {
            int y = g.e[t];
            if (vis[mex[y]] == n + 1) continue;
            vis[mex[y]] = n + 1;
            h[y] ^= sm[mex[y]];
          }
          for (int j = 1; j <= n; j++) printf("%d ", h[j]);
          return 0;
        }
    }
  puts("LOSE");
  return 0;
}
