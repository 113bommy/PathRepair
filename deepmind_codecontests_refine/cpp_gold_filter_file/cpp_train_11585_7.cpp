#include <bits/stdc++.h>
using namespace std;
long long power(long long m, long long n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return power(m * m, n / 2);
  else
    return m * power(m * m, (n - 1) / 2);
}
long long nCr(long long n, long long r) {
  if (r == 0 || n == r)
    return 1;
  else
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    double a, b;
    cin >> a >> b;
    double res = labs(a - b);
    cout << long(ceil(res / 10)) << endl;
  }
  return 0;
}
