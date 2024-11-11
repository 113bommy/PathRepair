#include <bits/stdc++.h>
using namespace std;
int n, m;
int r;
int graph[100][100];
int f[85][85][85][85];
int lb[85][85][85], rb[85][85][85];
int main() {
  int i, j, k, l;
  cin >> n >> m;
  if (m == 1) {
    printf("0\n");
    return 0;
  }
  cin >> r;
  for (i = 0; i < r; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (graph[a][b] == 0)
      graph[a][b] = c;
    else if (c < graph[a][b])
      graph[a][b] = c;
  }
  for (i = 0; i <= n + 1; i++) {
    for (j = 0; j <= n + 1; j++) {
      for (k = 0; k <= n + 1; k++) {
        for (l = 0; l <= m; l++) {
          f[i][j][k][l] = -1;
        }
      }
      for (l = 0; l <= m; l++) {
        lb[i][j][l] = -1;
        rb[i][j][l] = -1;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    f[i][0][n + 1][1] = 0;
    lb[i][0][1] = 0;
    rb[i][n + 1][1] = 0;
  }
  for (l = 2; l <= m; l++) {
    for (i = 1; i <= n; i++) {
      for (k = i + 1; k <= n; k++) {
        if ((lb[k][0][l - 1] >= 0) && (graph[k][i] >= 1)) {
          if (f[i][0][k][l] == -1)
            f[i][0][k][l] = lb[k][0][l - 1] + graph[k][i];
          else if (lb[k][0][l - 1] + graph[k][i] < f[i][0][k][l])
            f[i][0][k][l] = lb[k][0][l - 1] + graph[k][i];
        }
      }
      for (j = 1; j <= i - 1; j++) {
        if ((rb[j][n + 1][l - 1] >= 0) && (graph[j][i] >= 1)) {
          if (f[i][j][n + 1][l] == -1)
            f[i][j][n + 1][l] = rb[j][n + 1][l - 1] + graph[j][i];
          else if (rb[j][n + 1][l - 1] + graph[j][i] < f[i][j][n + 1][l])
            f[i][j][n + 1][l] = rb[j][n + 1][l - 1] + graph[j][i];
        }
      }
      for (j = 1; j <= i - 1; j++) {
        for (k = i + 1; k <= n; k++) {
          if ((rb[j][k][l - 1] >= 0) && (graph[j][i] >= 1)) {
            if (f[i][j][k][l] == -1)
              f[i][j][k][l] = rb[j][k][l - 1] + graph[j][i];
            else if (f[i][j][k][l] > rb[j][k][l - 1] + graph[j][i])
              f[i][j][k][l] = rb[j][k][l - 1] + graph[j][i];
          }
          if ((lb[k][j][l - 1] >= 0) && (graph[k][i] >= 1)) {
            if (f[i][j][k][l] == -1)
              f[i][j][k][l] = lb[k][j][l - 1] + graph[k][i];
            else if (f[i][j][k][l] > lb[k][j][l - 1] + graph[k][i])
              f[i][j][k][l] = lb[k][j][l - 1] + graph[k][i];
          }
        }
      }
      for (j = 0; j <= i - 1; j++) {
        for (k = i + 1; k <= n + 1; k++) {
          if (f[i][j][k][l] == -1) continue;
          if (lb[i][j][l] == -1)
            lb[i][j][l] = f[i][j][k][l];
          else if (lb[i][j][l] > f[i][j][k][l])
            lb[i][j][l] = f[i][j][k][l];
        }
      }
      for (k = i + 1; k <= n + 1; k++) {
        for (j = 0; j <= i - 1; j++) {
          if (f[i][j][k][l] == -1) continue;
          if (rb[i][k][l] == -1)
            rb[i][k][l] = f[i][j][k][l];
          else if (rb[i][k][l] > f[i][j][k][l])
            rb[i][k][l] = f[i][j][k][l];
        }
      }
    }
    if (l == m) {
      int ans = -1;
      for (i = 1; i <= n; i++) {
        for (j = 0; j <= i - 1; j++) {
          for (k = i + 1; k <= n + 1; k++) {
            if (f[i][j][k][l] == -1) continue;
            if (ans == -1) {
              ans = f[i][j][k][l];
            } else if (ans > f[i][j][k][l]) {
              ans = f[i][j][k][l];
            }
          }
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
