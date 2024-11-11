#include <bits/stdc++.h>
using namespace std;
int n, k;
double f[700], g[700];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 666; ++j) {
      if (i & 1) {
        f[j] =
            (g[j] * (k - 1) / (double)k + (g[j + 1] + j) * (1.0 / (k * j + k)) +
             (g[j] + (1 + j) / (double)2) * (j * 1.0 / k / (j + 1)));
      } else {
        g[j] =
            (f[j] * (k - 1) / (double)k + (f[j + 1] + j) * (1.0 / (k * j + k)) +
             (f[j] + (1 + j) / (double)2) * (j * 1.0 / k / (j + 1)));
      }
    }
  }
  printf("%.10lf", n % 2 == 1 ? f[1] * k : g[1] * k);
}
