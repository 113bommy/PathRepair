#include <bits/stdc++.h>
using namespace std;
const double eps(1e-10);
double E[2][600];
int main() {
  memset(E, 0, sizeof(E));
  int n, k;
  scanf("%d %d", &n, &k);
  int now = 1;
  for (int i = n - 1; i >= 0; i--) {
    now ^= 1;
    for (int j = 1; j < 600; j++)
      E[now][j] = E[now ^ 1][j] * (j * 1. / (j + 1) / k + (k - 1) * 1. / k) +
                  (j * 1. / 2 + j * 1. / (j + 1)) / k +
                  1. / (j + 1) * E[now ^ 1][j + 1] / k;
  }
  printf("%.9f\n", k * E[now][1]);
  return 0;
}
