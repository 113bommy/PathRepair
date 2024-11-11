#include <bits/stdc++.h>
const int mm = 0x3f3f3f3f;
using namespace std;
int n, m;
int a[20][20], d[20], f[1 << 18 + 5];
void floyd() {
  for (int k = 0; k < n; k++) {
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if (a[i][k] < mm && a[k][j] < mm)
          a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
}
int main() {
  cin >> n >> m;
  memset(a, 0x3f, sizeof(a));
  int p, q, w;
  int ans = 0;
  if (!m) {
    printf("0");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &p, &q, &w);
    ans += w;
    p--;
    q--;
    d[p]++;
    d[q]++;
    if (a[p][q] > w) {
      a[p][q] = a[q][p] = w;
    }
  }
  floyd();
  for (int i = 1; i < n; i++) {
    if (d[i] && a[0][i] >= mm) {
      printf("-1");
      return 0;
    }
  }
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  int maxx = (1 << n) - 1;
  for (int i = 0; i <= maxx; i++) {
    int flag = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        if (d[j] % 2 != 0) {
          flag = 1;
          break;
        }
      }
    }
    if (!flag) {
      f[i] = 0;
    }
  }
  for (int i = 0; i <= maxx - 1; i++) {
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j))) continue;
      for (int k = 0; k < n; k++) {
        if ((i & (1 << k))) continue;
        if (j == k) continue;
        if ((d[j] % 2 == 1) && (d[k] % 2 == 1)) {
          f[i | (1 << j) | (1 << k)] =
              min(f[i] + a[j][k], f[i | (1 << j) | (1 << k)]);
        }
      }
    }
  }
  printf("%d\n", ans + f[maxx]);
}
