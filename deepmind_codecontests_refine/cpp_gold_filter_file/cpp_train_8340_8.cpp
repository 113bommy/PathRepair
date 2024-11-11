#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return 0;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
int main() {
  long long n, i, k = 0;
  cin >> n;
  long long b[n], a[n / 2];
  for (long long i = 0; i < n / 2; ++i) cin >> a[i];
  b[0] = 0;
  b[n - 1] = a[0];
  for (long long i = 1; i < n / 2; ++i) {
    if (a[i - 1] < a[i]) {
      k = a[i] - b[n - i];
    }
    b[i] = k;
    b[n - 1 - i] = a[i] - k;
  }
  for (long long i = 0; i < n; ++i) cout << b[i] << " ";
  return 0;
}
