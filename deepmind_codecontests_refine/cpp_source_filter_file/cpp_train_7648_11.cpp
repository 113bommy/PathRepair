#include <bits/stdc++.h>
using namespace std;
long long sum[2 * 100 * 1000 + 10];
double apr[2 * 100 * 1000 + 10];
int main() {
  int n, t;
  double c;
  cin >> n >> t >> c;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum[i] = a;
    if (i) sum[i] += sum[i - 1];
    double prev = 0;
    if (i) prev = apr[i - 1];
    apr[i] = (prev + (a + .0) / t) / c;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    long long sm = sum[q - 1];
    if (q - t) sm -= sum[q - t - 1];
    double Real = sm / t;
    double App = apr[q - 1];
    printf("%.06lf %.06lf %.06lf\n", Real, App, abs(Real - App) / Real);
  }
  return 0;
}
