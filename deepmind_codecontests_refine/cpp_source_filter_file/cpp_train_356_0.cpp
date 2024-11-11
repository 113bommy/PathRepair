#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  long long int n, k;
  cin >> n >> k;
  double log_acc = 1.0;
  double log_phi = log(1.0 / (k - 1.0));
  double res = 0.0;
  double es[100001];
  for (int i = 0; i <= n; ++i) es[i] = 0;
  for (long long int m = 0; m <= n; ++m) {
    if (0 == m) log_acc = n * log(1.0 - 1.0 / k);
    double ee = es[1];
    res += exp(log_acc) * ee;
    log_acc += log_phi + log(n - m) - log(1.0 + m);
    if (k == 1 && n == m) res = ee;
    for (int l = 0; l <= 500; ++l) {
      double p = 1.0 / (l + 1.0);
      es[l] = (1.0 - p) * es[l] + l / 2.0 + p * (l + es[l + 1]);
    }
  }
  printf("%.14f\n", res * k);
  return 0;
}
