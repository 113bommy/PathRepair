#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long g[505][505];
int a[505], b[505], k[505];
int n;
int nx, ny;
long long linker[505], lx[505], ly[505];
long long slack[505];
bool visx[505], visy[505];
bool dfs(int x) {
  visx[x] = true;
  for (int y = 0; y < ny; y++) {
    if (visy[y]) continue;
    int tmp = lx[x] + ly[y] - g[x][y];
    if (tmp == 0) {
      visy[y] = true;
      if (linker[y] == -1 || dfs(linker[y])) {
        linker[y] = x;
        return true;
      }
    } else if (slack[y] > tmp)
      slack[y] = tmp;
  }
  return false;
}
long long KM() {
  memset(linker, -1, sizeof(linker));
  memset(ly, 0, sizeof(ly));
  for (int i = 0; i < nx; i++) {
    lx[i] = -INF;
    for (int j = 0; j < ny; j++)
      if (g[i][j] > lx[i]) lx[i] = g[i][j];
  }
  for (int x = 0; x < nx; x++) {
    for (int i = 0; i < ny; i++) slack[i] = INF;
    while (true) {
      memset(visx, false, sizeof(visx));
      memset(visy, false, sizeof(visy));
      if (dfs(x)) break;
      int d = INF;
      for (int i = 0; i < ny; i++) {
        if (!visy[i] && d > slack[i]) d = slack[i];
      }
      for (int i = 0; i < nx; i++)
        if (visx[i]) lx[i] -= d;
      for (int i = 0; i < ny; i++) {
        if (visy[i])
          ly[i] += d;
        else
          slack[i] -= d;
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < ny; i++) {
    if (linker[i] != -1) res += g[linker[i]][i];
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &k[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = max(a[i] - b[i] * (min(k[i], j)), 0);
    }
  }
  long long res = 0;
  nx = ny = n;
  res = KM();
  cout << res << endl;
}
