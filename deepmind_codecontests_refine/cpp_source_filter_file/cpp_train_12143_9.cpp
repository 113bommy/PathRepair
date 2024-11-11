#include <bits/stdc++.h>
using namespace std;
const int N = 48, M = (1 << 23) + 9;
char s[N][N];
unsigned long long n, f[M], g[M], ans, sign[M];
int G[N][N], fa[N], siz[N];
int bel[N], cnt, num[M];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return;
  siz[fy] += siz[fx];
  fa[fx] = fy;
}
inline void FWT(unsigned long long *f, int n) {
  for (int mid = 2, k = 1; k < n; k <<= 1, mid <<= 1)
    for (int i = 0; i < n; i += mid)
      for (int j = 0; j < mid; j++) f[i + j + k] += f[i + j];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) siz[i] = 1, fa[i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= n; j++)
      if (s[i][j] == 'A') merge(i, j);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (find(i) == find(j) && s[i][j] == 'X') return puts("-1"), 0;
  for (int i = 1; i <= n; i++)
    if (find(i) == i && siz[i] > 1)
      ans += siz[i], bel[i] = ++cnt;
    else if (find(i) == i)
      ans++;
  if (!cnt) return printf("%d", ans - 1), 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (s[i][j] == 'X') {
        int x = find(i), y = find(j);
        if (siz[x] == 1 || siz[y] == 1) continue;
        G[bel[x]][bel[y]] = G[bel[y]][bel[x]] = true;
      }
  int all = (1 << cnt);
  for (int i = 0; i < all; i++) num[i] = num[i >> 1] + (i & 1);
  for (int i = 1; i <= cnt; i++) f[1 << i - 1] = true;
  for (int S = 0; S < all; S++)
    if (f[S]) {
      for (int j = 1; j <= cnt; j++)
        if (!(S & (1 << j - 1))) {
          bool flag = true;
          for (int i = 1; i <= cnt; i++)
            if ((S & (1 << i - 1)) && G[i][j]) {
              flag = false;
              break;
            }
          if (flag) f[S | (1 << j - 1)] = true;
        }
    }
  for (int i = 0; i < all; i++) sign[i] = ((cnt - num[i]) & 1 ? -1 : 1);
  FWT(f, all);
  memset(g, 1, sizeof g);
  for (int i = 0; i <= 10000; i++) {
    unsigned long long res = 0;
    for (int S = 0; S < all; S++) g[S] *= f[S], res += g[S] * sign[S];
    if (res) return printf("%d\n", ans + i), 0;
  }
  return 0;
}
