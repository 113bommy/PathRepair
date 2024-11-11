#include <bits/stdc++.h>
const int W = 30;
double f[500001][W + 1];
int N = 1, fa[500001], Q;
int main() {
  std::fill(f[1], f[1] + W + 1, 1);
  for (scanf("%d", &Q); Q--;) {
    int ty, p;
    scanf("%d%d", &ty, &p);
    if (ty == 1) {
      fa[++N] = p;
      static int q[W + 1], D;
      D = 0;
      q[0] = N;
      while (D < W && q[D] > 1) {
        q[D + 1] = fa[q[D]];
        D++;
      }
      for (int i = D; i > 1; i--)
        f[q[i]][i - 1] /= 0.5 + f[q[i - 1]][i - 2] / 2;
      std::fill(f[N], f[N] + W + 1, 1);
      f[q[1]][0] /= 2;
      for (int i = 2; i <= D; i++)
        f[q[i]][i - 1] *= 0.5 + f[q[i - 1]][i - 2] / 2;
    } else {
      double O = f[p][W] * W;
      for (int i = 0; i < W; i++) O -= f[p][i];
      printf("%.10lf\n", O);
    }
  }
  return 0;
}
