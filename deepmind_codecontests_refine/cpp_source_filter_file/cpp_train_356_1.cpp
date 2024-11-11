#include <bits/stdc++.h>
using namespace std;
int n;
double f[2][105], k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 100; j++)
      f[i & 1][j] = (1.0 / k) *
                    ((j * f[i & 1 ^ 1][j] + f[i & 1 ^ 1][j + 1] + j) / (j + 1) +
                     (k - 1) * f[i & 1 ^ 1][j] + j / 2.0);
  printf("%.9f\n", k * f[n & 1][1]);
}
