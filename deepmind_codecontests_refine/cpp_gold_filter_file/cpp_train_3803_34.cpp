#include <bits/stdc++.h>
using namespace std;
int n, m, q, ans, ar[105][105], dx[105], dy[105];
struct node {
  int op;
  int x, y, z;
} a[10005];
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &a[i].op);
    if (a[i].op == 1 || a[i].op == 2) {
      scanf("%d", &a[i].x);
    }
    if (a[i].op == 3) {
      scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
    }
  }
  for (int i = q; i; i--) {
    if (a[i].op == 1) {
      for (int i0 = 1; i0 <= m; i0++) dx[i0] = ar[a[i].x][i0];
      for (int i0 = 1; i0 <= m; i0++) ar[a[i].x][i0 % m + 1] = dx[i0];
    }
    if (a[i].op == 2) {
      for (int i0 = 1; i0 <= n; i0++) dy[i0] = ar[i0][a[i].x];
      for (int i0 = 1; i0 <= n; i0++) ar[i0 % n + 1][a[i].x] = dy[i0];
    }
    if (a[i].op == 3) {
      ar[a[i].x][a[i].y] = a[i].z;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int i0 = 1; i0 <= m; i0++)
      printf("%d%c", ar[i][i0], i0 == m ? '\n' : ' ');
  return 0;
}
