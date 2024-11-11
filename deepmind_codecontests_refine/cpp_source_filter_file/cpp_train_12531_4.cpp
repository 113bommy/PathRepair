#include <bits/stdc++.h>
using namespace std;
long long rpta = 0;
long long gcd(long long a, long long b) {
  if (!b) return a;
  rpta += a / b;
  return gcd(b, a % b);
}
int main() {
  long long n, a, b;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    gcd(a, b);
    cout << rpta;
    rpta = 0;
  }
  return 0;
}
