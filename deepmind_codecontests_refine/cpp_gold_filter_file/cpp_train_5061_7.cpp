#include <bits/stdc++.h>
using namespace std;
const int N = 605;
int id[N], e[N][N], E[N][N], used[N], bl[N];
int v, en, n, m, ans = -1;
void Floyd() {
  for (int k = 1; k <= v; k++)
    for (int i = 1; i <= v; i++)
      for (int j = 1; j <= v; j++) e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
}
bool km(int x) {
  for (int i = 1; i <= v; i++) {
    if (E[x][i] && !used[i]) {
      used[i] = 1;
      if (!bl[i] || km(bl[i])) {
        bl[i] = x;
        return 1;
      }
    }
  }
  return 0;
}
bool check(int mid) {
  memset(E, 0, sizeof E);
  memset(bl, 0, sizeof bl);
  int res = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= v; j++) {
      if (e[id[i]][j] <= mid) E[i][j] = 1;
    }
  for (int i = 1; i <= v; i++) {
    memset(used, 0, sizeof used);
    if (km(i)) res++;
  }
  if (res < m) return 0;
  return 1;
}
int main() {
  scanf("%d%d%d%d", &v, &en, &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &id[i]);
  memset(e, 60, sizeof e);
  for (int i = 1; i <= v; i++) e[i][i] = 0;
  for (int i = 1, u, v, w; i <= en; i++) {
    scanf("%d%d%d", &u, &v, &w);
    if (w < e[u][v]) e[u][v] = e[v][u] = w;
  }
  Floyd();
  int l = 0, r = 1e9;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans);
}
