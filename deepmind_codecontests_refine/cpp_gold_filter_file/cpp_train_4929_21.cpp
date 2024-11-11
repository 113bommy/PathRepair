#include <bits/stdc++.h>
using namespace std;
int dist[60][60][60];
int mindist[61][60][60];
const int INF = 2000000000;
void gao(const int n, const int m) {
  for (int mi = 0; mi < m; ++mi) {
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dist[mi][i][k] + dist[mi][k][j] < dist[mi][i][j]) {
            dist[mi][i][j] = dist[mi][i][k] + dist[mi][k][j];
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      mindist[0][i][j] = INF;
      for (int mi = 0; mi < m; ++mi) {
        if (mindist[0][i][j] > dist[mi][i][j]) {
          mindist[0][i][j] = dist[mi][i][j];
        }
      }
      for (int k = 1; k <= n; ++k) {
        mindist[k][i][j] = mindist[0][i][j];
      }
    }
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mindist[k][i][j] = mindist[k - 1][i][j];
        for (int c = 0; c < n; ++c) {
          if (mindist[k][i][j] > mindist[k - 1][i][c] + mindist[0][c][j]) {
            mindist[k][i][j] = mindist[k - 1][i][c] + mindist[0][c][j];
          }
        }
      }
    }
  }
}
int main() {
  int n, m, r;
  scanf("%d%d%d", &n, &m, &r);
  for (int mi = 0; mi < m; ++mi) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &dist[mi][i][j]);
      }
    }
  }
  gao(n, m);
  for (int i = 0; i < r; ++i) {
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    if (k > n) k = n;
    printf("%d\n", mindist[k][s - 1][t - 1]);
  }
}
