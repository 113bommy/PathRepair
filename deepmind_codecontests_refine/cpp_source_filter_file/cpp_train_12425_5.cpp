#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, x, y, nr;
vector<int> a[5100];
bool r[5100], f[5100];
int dfs(int p, int x) {
  int c = 1;
  for (int i = 0; i < a[x].size(); ++i)
    if (a[x][i] != p) c += dfs(x, a[x][i]);
  return c;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    scanf("%d %d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
  memset(r, false, sizeof(r));
  for (i = 1; i <= n; ++i) {
    memset(f, false, sizeof(f));
    f[0] = true;
    for (j = 0; j < a[i].size(); ++j) {
      x = dfs(i, a[i][j]);
      for (k = n; k >= x; --k)
        if (f[k - x]) f[k] = true;
    }
    for (k = 1; k <= n - 1; ++k)
      if (f[k]) r[k] = true;
  }
  for (k = 1; k <= n - 1; ++k) nr += r[k];
  printf("%d\n", nr);
  for (k = 1; k <= n - 1; ++k)
    if (r[k]) printf("%d %d", k, n - 1 - k);
}
