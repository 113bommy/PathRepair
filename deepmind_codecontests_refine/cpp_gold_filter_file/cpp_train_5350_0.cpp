#include <bits/stdc++.h>
using namespace std;
double g[85][85], ans[85][85], p[85][85 * 2], p1[85], p2[85], p3[85];
int n, m, l[85], r[85], b[85 * 2], lim1[85], lim2[85], low1[85], low2[85];
bool f1[85], f2[85], f3[85];
void solved(int id, int z) {
  for (int i = n; i <= n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k + j <= i; k++) g[j][k] = 0;
  lim1[0] = lim2[0] = 0;
  for (int i = 1; i <= n; i++) {
    p1[i] = p[i][z - 1];
    p2[i] = p[i][z] - p[i][z - 1];
    p3[i] = p[i][m] - p[i][z];
    f1[i] = p1[i] > 1e-9;
    f2[i] = p2[i] > 1e-9;
    f3[i] = p3[i] > 1e-9;
    low1[i] = low1[i - 1] + (int)((fabs(1 - p1[i]) < 1e-9) && (i != id));
    low2[i] = low2[i - 1] + (int)((fabs(1 - p2[i]) < 1e-9) && (i != id));
    lim1[i] = lim1[i - 1] + f1[i];
    lim2[i] = lim2[i - 1] + f2[i];
  }
  g[0][0] = p2[id];
  for (int i = 0; i <= n; i++)
    if (i + 1 != id) {
      double v1 = p1[i + 1], v2 = p2[i + 1], v3 = p3[i + 1];
      bool t1 = f1[i + 1], t2 = f2[i + 1], t3 = f3[i + 1];
      for (int j = min(lim1[i], i); j >= low1[i]; j--)
        for (int k = min(i - j, lim2[i]); k >= low2[i]; k--)
          if (g[j][k] > 1e-9) {
            if (i == n) {
              double t = g[j][k] / (k + 1);
              ans[id][j + 1] += t;
              ans[id][j + k + 2] -= t;
              continue;
            }
            double tt = g[j][k];
            g[j][k] = 0;
            if (t1) g[j + 1][k] += tt * v1;
            if (t2) g[j][k + 1] += tt * v2;
            if (t3) g[j][k] += tt * v3;
          }
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    b[++b[0]] = l[i];
    b[++b[0]] = r[i];
  }
  sort(b + 1, b + b[0] + 1);
  int top = 1;
  for (int i = 2; i <= b[0]; i++)
    if (b[i] != b[top]) b[++top] = b[i];
  b[0] = top;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < b[0]; j++)
      if (l[i] <= b[j] && r[i] >= b[j + 1])
        p[i][j] = (double)(b[j + 1] - b[j]) / (r[i] - l[i]) + p[i][j - 1];
      else
        p[i][j] = p[i][j - 1];
  m = b[0] - 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (l[i] <= b[j] && r[i] >= b[j + 1]) solved(i, j);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans[i][j] += ans[i][j - 1];
      printf("%.10lf ", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
