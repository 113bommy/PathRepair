#include <bits/stdc++.h>
using namespace std;
long double f(int k, int m, int n) {
  long double t = exp(n * log(k) - n * log(m));
  if (k > 1) t -= exp(n * log(k - 1) - n * log(m));
  return t;
}
int main() {
  int m, n;
  cin >> m >> n;
  long double sol = 0.0;
  for (int k = 1; k <= m; ++k) {
    sol += k * f(k, m, n);
  }
  printf("%.9Lf\n", sol);
  return 0;
}
