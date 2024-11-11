#include <bits/stdc++.h>
using namespace std;
int grand(double n) {
  if (n > 0.5) return 500;
  if (n > 0.25) return 1000;
  if (n > 0.125) return 1500;
  if (n > 0.0625) return 2000;
  if (n > 0.03125) return 2500;
  if (n >= 0) return 3000;
}
int score(double n, int x) { return grand(n) - grand(n) * x / 250; }
int main() {
  int n;
  int a[125][6];
  int b[6];
  int grand1 = 0, grand2 = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= 6; i++) {
    b[i] = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j][i] > 0) b[i]++;
    }
  }
  double c;
  for (int i = 1; i <= 6; i++) {
    c = b[i] * 1.0 / n;
    if (a[1][i] != -1) grand1 += score(c, a[1][i]);
    if (a[2][i] != -1) grand2 += score(c, a[2][i]);
  }
  int k = -1;
  for (int i = 0; i <= 500000; i++) {
    if (grand1 > grand2) {
      k = i;
      break;
    }
    n++;
    grand1 = grand2 = 0;
    for (int j = 1; j <= 5; j++) {
      if (a[1][j] == -1 && a[2][j] != -1) {
        c = b[j] * 1.0 / n;
        grand2 += score(c, a[2][j]);
      } else if (a[1][j] > a[2][j] && a[2][j] != -1) {
        b[j]++;
        c = b[j] * 1.0 / n;
        grand1 += score(c, a[1][j]);
        grand2 += score(c, a[2][j]);
      } else if (a[1][j] > a[2][j] && a[2][j] == -1) {
        c = b[j] * 1.0 / n;
        grand1 += score(c, a[1][j]);
      } else if (a[1][j] < a[2][j]) {
        c = b[j] * 1.0 / n;
        grand1 += score(c, a[1][j]);
        grand2 += score(c, a[2][j]);
      }
    }
  }
  printf("%d\n", k);
}
