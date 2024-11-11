#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, k, cnt;
int head[N], fa[N], size[N];
long long p[N][6], tot[N][6], f[N][5], ftot[N][5], ans;
struct xint {
  int to, next;
} e[N * 2];
void add(int x, int y) {
  e[++cnt] = (xint){y, head[x]};
  head[x] = cnt;
  e[++cnt] = (xint){x, head[y]};
  head[y] = cnt;
}
void dfs1(int x, int d) {
  p[1][d % k] += d;
  tot[1][d % k]++;
  size[x] = 1;
  f[x][0] = 0;
  ftot[x][0] = 1;
  for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
    if (y != fa[x]) {
      fa[y] = x;
      dfs1(y, d + 1);
      size[x] += size[y];
      for (int j = 0; j <= k - 1; ++j) {
        ftot[x][(j + 1) % k] += ftot[y][j];
        f[x][(j + 1) % k] += f[y][j] + ftot[y][j];
      }
    }
}
void dfs2(int x) {
  for (int i = 0; i <= k - 1; ++i) {
    ans += (p[x][i] - tot[x][i] * i) / k;
    if (i > 0) ans += tot[x][i];
  }
  for (int i = head[x], y = e[i].to; i; i = e[i].next, y = e[i].to)
    if (y != fa[x]) {
      for (int j = 0; j <= k - 1; ++j) {
        p[y][(j + 1) % k] = p[x][(j + 1) % k] - f[y][j] - ftot[y][j];
        tot[y][(j + 1) % k] = tot[x][(j + 1) % k] - ftot[y][j];
      }
      for (int j = k - 1; j >= 0; --j) {
        p[y][j + 1] = p[y][j] + (tot[x][j] - ftot[y][(j + k - 1) % k]);
        tot[y][j + 1] = tot[y][j];
      }
      p[y][0] = p[y][k];
      tot[y][0] = tot[y][k];
      for (int j = 0; j <= k - 1; ++j) {
        p[y][j] += f[y][j];
        tot[y][j] += ftot[y][j];
      }
      dfs2(y);
    }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 2; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
  }
  dfs1(1, 0);
  dfs2(1);
  cout << ans / 2 << endl;
}
