#include <bits/stdc++.h>
using namespace std;
const int M = 200101;
const int N = 510000;
int n, m, k, a[N], cnt, bz[21][N], l, r;
struct vv {
  int l, r;
} g[N];
bool cp1(vv a, vv b) { return a.l < b.l; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l, &r);
    a[l] = max(a[l], r);
    k = max(k, r);
  }
  for (int i = 1; i <= k; i++) {
    a[i] = max(a[i], a[i - 1]);
    if (a[i] >= i) bz[0][i] = a[i];
  }
  bz[0][0] = a[0];
  for (int i = 1; i <= 20; i++)
    for (int j = 0; j <= k; j++) bz[i][j] = bz[i - 1][bz[i - 1][j]];
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &l, &r);
    k = l;
    int res = 0;
    for (int j = 20; j >= 0; j--)
      if (bz[j][k] && bz[j][k] < r) {
        k = bz[j][k];
        res += 1 << j;
      }
    if (a[k] < r)
      printf("-1\n");
    else
      printf("%d\n", res + 1);
  }
}
