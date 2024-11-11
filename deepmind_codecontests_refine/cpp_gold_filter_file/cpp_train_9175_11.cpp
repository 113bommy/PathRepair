#include <bits/stdc++.h>
using namespace std;
int n, m, sa, sb;
int deg[25], encode[25][25], encode2[25][25];
bool connected[25][25];
long double stay[25], prob[25][25], mtx[260][260], oh[260][260];
long double augment[260][520];
long double ans[260][25];
void gaussian(int N, int M) {
  for (int i = (1); i <= (N); i++) {
    int piv = i;
    for (int j = (i + 1); j <= (N); j++) {
      if (abs(augment[j][i]) > abs(augment[piv][i])) piv = j;
    }
    for (int k = (i); k <= (M); k++) swap(augment[i][k], augment[piv][k]);
    for (int j = (i + 1); j <= (N); j++) {
      long double multiplier = augment[j][i] / augment[i][i];
      for (int k = (i); k <= (M); k++)
        augment[j][k] -= augment[i][k] * multiplier;
    }
    for (int k = (M); k >= (i); k--) augment[i][k] /= augment[i][i];
  }
  for (int i = (N); i >= (1); i--)
    for (int j = (1); j <= (i - 1); j++) {
      for (int k = (M); k >= (i); k--)
        augment[j][k] -= augment[i][k] * augment[j][i];
    }
  return;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &sa, &sb);
  if (sa == sb) {
    for (int i = (1); i <= (n); i++) {
      if (i == sa)
        printf("1");
      else
        printf("0");
      printf("%c", i == n ? '\n' : ' ');
    }
    return 0;
  }
  if (sa > sb) swap(sa, sb);
  for (int i = (1); i <= (m); i++) {
    int xx, yy;
    scanf("%d %d", &xx, &yy);
    deg[xx]++, deg[yy]++;
    connected[xx][yy] = 1;
    connected[yy][xx] = 1;
  }
  for (int i = (1); i <= (n); i++) {
    double temp;
    scanf("%lf", &temp);
    stay[i] = temp;
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (n); j++) {
      if (i == j)
        prob[i][j] = stay[i];
      else if (connected[i][j]) {
        prob[i][j] = (1 - stay[i]) / deg[i];
      }
    }
  }
  int p = 0, p2 = 0;
  for (int i = (1); i <= (n); i++)
    for (int j = (i); j <= (n); j++) encode[i][j] = ++p;
  for (int i = (1); i <= (n); i++)
    for (int j = (i + 1); j <= (n); j++) encode2[i][j] = ++p2;
  for (int i = (1); i <= (n); i++)
    for (int j = (i); j <= (n); j++) {
      if (i == j)
        mtx[encode[i][j]][encode[i][j]] = 1;
      else {
        for (int i2 = (1); i2 <= (n); i2++)
          for (int j2 = (1); j2 <= (n); j2++) {
            int i3 = min(i2, j2), j3 = max(i2, j2);
            mtx[encode[i][j]][encode[i3][j3]] += prob[i][i2] * prob[j][j2];
          }
      }
    }
  for (int i = (1); i <= (n); i++)
    for (int j = (i + 1); j <= (n); j++) {
      int e = encode[i][j], e2 = encode2[i][j];
      for (int i2 = (1); i2 <= (n); i2++)
        for (int j2 = (i2 + 1); j2 <= (n); j2++) {
          int f = encode[i2][j2], f2 = encode2[i2][j2];
          augment[e2][f2] = (e == f ? 1 : 0) - mtx[e][f];
        }
    }
  for (int i = (1); i <= (p2); i++) augment[i][p2 + i] = 1;
  gaussian(p2, p2 + p2);
  for (int i = (1); i <= (n); i++)
    for (int j = (i + 1); j <= (n); j++)
      for (int i2 = (1); i2 <= (n); i2++)
        for (int j2 = (i2 + 1); j2 <= (n); j2++)
          for (int k = (1); k <= (n); k++) {
            int e2 = encode2[i][j];
            int f2 = encode2[i2][j2];
            ans[e2][k] +=
                augment[e2][f2 + p2] * mtx[encode[i2][j2]][encode[k][k]];
          }
  for (int i = (1); i <= (n); i++)
    printf("%.10lf%c", (double)ans[encode2[sa][sb]][i], i == n ? '\n' : ' ');
  return 0;
}
