#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int rd() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
int n, m, ans, it, sq[10], a[10][2], b[N][2], kl[N], ti;
bool vs[N];
vector<int> sh[10][N];
bool ck(int x) {
  if (it > n) return 0;
  int np = sq[it++], nn = sh[np][x].size();
  for (int i = 0; i < nn; ++i) {
    int y = sh[np][x][i];
    if (kl[y] < ti && !ck(y)) return 0;
  }
  kl[x] = ++ti;
  return 1;
}
int main() {
  n = rd(), m = rd();
  for (int i = 1; i <= n; ++i) sq[i] = i, a[i][0] = rd(), a[i][1] = rd();
  for (int i = 1; i <= m; ++i) b[i][0] = rd(), b[i][1] = rd();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int k = 1; k <= m; ++k) {
        if (j == k) continue;
        int xl = min(a[i][0], b[j][0]), xr = max(a[i][0], b[j][0]),
            yl = min(a[i][1], b[j][1]), yr = max(a[i][1], b[j][1]);
        if (b[k][0] >= xl && b[k][0] <= xr && b[k][1] >= yl && b[k][1] <= yr &&
            1ll * (b[k][0] - b[j][0]) * (a[i][1] - b[j][1]) ==
                1ll * (a[i][0] - b[j][0]) * (b[k][1] - b[j][1]))
          sh[i][j].push_back(k);
      }
  do {
    for (int i = 1; i <= m; ++i) {
      if (vs[i]) continue;
      it = 1, ++ti;
      if (ck(i)) vs[i] = 1, ++ans;
    }
  } while (next_permutation(sq + 1, sq + n + 1));
  printf("%d\n", ans);
  return 0;
}
