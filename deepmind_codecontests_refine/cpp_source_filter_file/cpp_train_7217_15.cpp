#include <bits/stdc++.h>
using namespace std;
int main() {
  const int N = 18;
  int n;
  double a[N][N];
  double p[1 << N];
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (n); ++j) scanf("%lf", &a[i][j]);
  int que[N];
  p[(1 << n) - 1] = 1.0;
  for (int s = (1 << n) - 1; s > 0; s--) {
    if (p[s] < 0.0000005) continue;
    int qn = 0;
    for (int i = 0; i < (n); ++i)
      if (s >> i & 1) que[qn++] = i;
    if (qn == 1) continue;
    double c = p[s] / (qn * (qn - 1) >> 1);
    for (int i = 0; i < (qn); ++i)
      for (int j = (i + 1); j < (qn); ++j) {
        int& x = que[i];
        int& y = que[j];
        p[s ^ (1 << x)] += a[y][x] * c;
        p[s ^ (1 << y)] += a[x][y] * c;
      }
  }
  for (int i = 0; i < (n); ++i) {
    printf("%.6f", p[1 << i]);
    putchar(i + 1 < n ? 32 : 10);
  }
  return 0;
}
