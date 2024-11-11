#include <bits/stdc++.h>
using namespace std;
typedef int mat[100010];
int n, m;
mat a, b;
mat f, g;
mat L;
void upd(int &x, int y) {
  if (y > x) x = y;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = 0; i < n; ++i) scanf("%d", b + i);
  sort(a, a + n);
  sort(b, b + m);
  for (int i = 0; i < n; ++i) {
    if (i && a[i - 1] + 1 == a[i])
      L[i] = L[i - 1];
    else
      L[i] = i;
    int k = upper_bound(b, b + m, a[i]) - b;
    for (int j = k - 1; j >= 0 && i - a[i] + b[j] >= 0; --j)
      upd(f[i], g[L[i - a[i] + b[j]]] + k - j);
    if (L[i] == i) upd(f[i], g[i]);
    upd(g[i + 1], f[i]), upd(g[i + 1], g[i]), upd(f[i + 1], f[i]);
    for (int j = k; j < m && i - a[i] + b[j] < n; ++j)
      upd(g[i - a[i] + b[j] + 1], f[i] + j - k + 1);
  }
  printf("%d\n", g[n]);
  return 0;
}
