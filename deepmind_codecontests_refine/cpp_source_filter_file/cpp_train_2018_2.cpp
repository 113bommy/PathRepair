#include <bits/stdc++.h>
int n, m;
int rooms[100];
double probs[60][60][60];
double dists[60][60][60];
double pascal(int n, int k) {
  double ans = 1.0;
  for (int i = 1; i <= n; i++) ans = ans * i;
  for (int j = 1; j <= k; j++) ans = ans / j;
  for (int j = 1; j <= (n - k); j++) ans = ans / j;
  return ans;
}
double probDist(int nr, int k, int mr) {
  if (dists[nr][k][mr] < 0.0) {
    double ans =
        pascal(nr, k) * pow((1.0 / mr), k) * pow((mr - 1.0) / mr, nr - k);
    dists[nr][k][mr] = ans;
  }
  return dists[nr][k][mr];
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d", &rooms[i + 1]);
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        probs[i][j][k] = 0.0;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        dists[i][j][k] = -1.0;
      }
    }
  }
  probs[0][0][0] = 1.0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      int nr = n - j;
      for (int max = 0; max <= n; max++) {
        double curProb = probs[i - 1][j][max];
        for (int k = 0; k <= nr; k++) {
          double mulProb = probDist(nr, k, m - i + 1);
          int curHeight = k / rooms[i];
          if (k % rooms[i] != 0) curHeight++;
          if (curHeight > max) {
            probs[i][j + k][curHeight] += curProb * mulProb;
          } else {
            probs[i][j + k][max] += curProb * mulProb;
          }
        }
      }
    }
  }
  double exp = 0.0;
  for (int i = 0; i <= n; i++) {
    exp += i * probs[m][n][i];
  }
  printf("%.12f\n", exp);
  return 0;
}
