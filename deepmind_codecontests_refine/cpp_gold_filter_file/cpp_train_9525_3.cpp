#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int fa[100010], n, cnt;
bitset<1010> G[1010], S[1010], vis;
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int k, x;
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &x);
      G[i][x] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  bitset<1010> t;
  int u, v;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      t = (G[i] & G[j]);
      if (t.count() == 2) {
        u = 0, v = 0;
        for (int k = 1; k <= n; k++) {
          if (t[k]) {
            if (!u)
              u = k;
            else
              v = k;
          }
        }
        int fa_u = find(u), fa_v = find(v);
        if (fa_u != fa_v) {
          fa[fa_u] = fa_v, cnt++;
          printf("%d %d\n", u, v);
          vis[u] = vis[v] = 1;
          S[u][u] = S[v][v] = S[u][v] = S[v][u] = 1;
        }
      }
    }
  }
  if (cnt == 0) {
    for (int i = 2; i <= n; i++) {
      printf("1 %d\n", i);
    }
  } else if (cnt == 1) {
    for (int i = 1; i <= n; i++) {
      if (G[i].count() < n) {
        for (int j = 1; j <= n; j++) {
          if (!vis[j]) {
            if (G[i][j]) {
              printf("%d %d\n", u, j);
            } else {
              printf("%d %d\n", v, j);
            }
          }
        }
        break;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        int minn = INF;
        for (int j = 1; j <= n; j++) {
          if (G[j][i] && (G[j] & vis).count() < minn) {
            t = (G[j] & vis), minn = t.count();
          }
        }
        for (int j = 1; j <= n; j++) {
          if (t[j] && t == S[j]) {
            printf("%d %d\n", i, j);
            break;
          }
        }
      }
    }
  }
  return 0;
}
