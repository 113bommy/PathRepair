#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456,268435456")
using namespace std;
int a[5000], b[5000], rr[4][5000];
bool check[5000];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < 4; j++) scanf("%d", &rr[j][i]);
  memset(a, 0x3f, sizeof(a)), memset(b, 0x3f, sizeof(b));
  for (int i = m - 1; i >= 0; i--)
    if (rr[0][i] == 2)
      for (int j = rr[1][i] - 1; j <= rr[2][i] - 1; j++) {
        if (check[j] && a[j] < rr[3][i]) continue;
        a[j] = rr[3][i], check[j] = 1;
      }
    else
      for (int j = rr[1][i] - 1; j <= rr[2][i] - 1; j++)
        if (check[j]) a[j] -= rr[3][i];
  for (int i = 0; i < n; i++) b[i] = a[i];
  bool flag = 1;
  for (int i = 0; i < m && flag; i++)
    if (rr[0][i] == 2) {
      int m2 = -1e9;
      for (int j = rr[1][i] - 1; j <= rr[2][i] - 1; j++) m2 = max(m2, a[j]);
      if (m2 != rr[3][i]) {
        flag = 0;
        break;
      }
    } else
      for (int j = rr[1][i] - 1; j <= rr[2][i] - 1; j++) a[j] += rr[3][i];
  if (flag) {
    printf("YES\n");
    for (int i = 0; i < n; i++)
      if (check[i] == 0)
        printf("%d ", -1e9);
      else
        printf("%d ", b[i]);
  } else
    printf("NO\n");
  return 0;
}
