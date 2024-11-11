#include <bits/stdc++.h>
using namespace std;
double a[200][200], b[200][200], w[200][200], n;
int main() {
  scanf("%f", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%f", &w[i][j]);
      if (i == j) a[i][j] = w[i][j];
    }
  for (int i = 1; i < n; i++)
    for (int j = 2; j <= n; j++) {
      b[i][j] = (w[i][j] - w[j][i]) / 2;
      b[j][i] = -b[i][j];
      a[i][j] = a[j][i] = w[i][j] - b[i][j];
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%.8f ", a[i][j]);
    puts("");
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%.8f ", b[i][j]);
    puts("");
  }
  return 0;
}
