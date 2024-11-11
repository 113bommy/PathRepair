#include <bits/stdc++.h>
using namespace std;
double f[100005];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 400; j++)
      f[j] = (1 / (j + 1.0) * (f[j + 1] + j) +
              j / (j + 1.0) * (f[j] + (j + 1) / 2.0)) /
                 k +
             (k - 1.0) / k * f[j];
  printf("%.12lf\n", f[1] * k);
  return 0;
}
