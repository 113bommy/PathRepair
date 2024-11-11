#include <bits/stdc++.h>
using namespace std;
long double eps = 1e-12, X = 1.0;
long long nCr(long long n, long long r) {
  if (r > n) return 0;
  if (r == 1) return n;
  if (r == 2) return n * (n - 1) / 2;
  if (r == 3) return n * (n - 1) * (n - 2) / 6;
  return 0;
}
long double fun(int m, int n) {
  int r = n - m;
  long double a = 0, b = 0;
  if (r >= 3) a = nCr(r, 3) * X / nCr(n, 3);
  if (r >= 2 and m >= 1) {
    long double p = (nCr(r, 2) * X * m / nCr(n, 3));
    p *= (X / 2);
    b = p;
  }
  return X - (a + b);
}
int main() {
  int n;
  long double p;
  cin >> n >> p;
  for (int i = 0; i <= n; i++) {
    if (abs(fun(i, n)) + eps >= p) {
      cout << i;
      return 0;
    }
  }
}
