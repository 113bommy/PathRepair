#include <bits/stdc++.h>
using namespace std;
int INF = 500000001;
int cost[2][1001], path[3][501][1001], r[2][501];
int main() {
  for (int n; ~scanf("%d", &n);) {
    int m = n / 2;
    vector<int> a(n + 2, INF);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (n == 1) {
      printf("%d\n1\n", a[0]);
      continue;
    } else if (n == 2) {
      printf("%d\n1 2\n", max(a[0], a[1]));
      continue;
    } else if (n == 3) {
      int x = max(a[0], a[1]) + a[2];
      int y = max(a[1], a[2]) + a[0];
      int z = max(a[0], a[2]) + a[1];
      if (x < y && x < z)
        printf("%d\n1 2\n3\n", x);
      else if (y < z)
        printf("%d\n2 3\n1\n", y);
      else
        printf("%d\n1 3\n2\n", z);
      continue;
    }
    for (int j = 0; j < 1001; ++j) {
      for (int i = 0; i < 501; ++i)
        path[0][i][j] = path[1][i][j] = path[2][i][j] = INF;
      for (int i = 0; i < 2; ++i) cost[i][j] = INF;
    }
    for (int i = 0; i < 3; ++i) {
      cost[0][i] = max(a[(i + 1) % 3], a[(i + 2) % 3]);
      path[0][0][i] = (i + 1) % 3;
      path[1][0][i] = (i + 2) % 3;
      path[2][0][i] = i;
    }
    for (int i = 1; i < m; ++i) {
      int now = i & 1;
      int p = 3 + 2 * (i - 1);
      for (int j = 0; j < n; ++j) {
        if (cost[!now][j] != INF) {
          int x = cost[!now][j] + max(a[p], a[p + 1]);
          int y = cost[!now][j] + max(a[j], a[p + 1]);
          int z = cost[!now][j] + max(a[j], a[p]);
          if (x < cost[now][j]) {
            cost[now][j] = x;
            path[0][i][j] = p;
            path[1][i][j] = p + 1;
            path[2][i][j] = j;
          }
          if (y < cost[now][p]) {
            cost[now][p] = y;
            path[0][i][p] = j;
            path[1][i][p] = p + 1;
            path[2][i][p] = j;
          }
          if (z < cost[now][p + 1]) {
            cost[now][p + 1] = z;
            path[0][i][p + 1] = j;
            path[1][i][p + 1] = p;
            path[2][i][p + 1] = j;
          }
        }
        cost[!now][j] = INF;
      }
    }
    int result = INF, index = 0;
    for (int i = 0; i < 1001; ++i)
      if (cost[!(m & 1)][i] != INF) {
        int c = cost[!(m & 1)][i] + a[i] * (n & 1);
        if (c < INF && c < result) {
          result = c;
          index = i;
        }
      }
    printf("%d\n", result);
    int pre = index;
    for (int i = 0; i < m; ++i) {
      r[0][m - i - 1] = path[0][m - i - 1][pre] + 1;
      r[1][m - i - 1] = path[1][m - i - 1][pre] + 1;
      pre = path[2][m - i - 1][pre];
    }
    for (int i = 0; i < m; ++i) printf("%d %d\n", r[0][i], r[1][i]);
    if (n & 1) printf("%d\n", index + 1);
  }
  return 0;
}
