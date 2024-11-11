#include <bits/stdc++.h>
using namespace std;
long long int n, m, k, j = 1, p, a, b;
long long gcd(int a, int b) {
  if (b < 2) return 1;
  if (a % b != 0) return gcd(b, a % b);
  return b;
}
int main() {
  cin >> n >> m >> k;
  a = n;
  b = m;
  p = gcd(n, k);
  n /= p;
  k /= p;
  p = gcd(m, k);
  m /= p;
  k /= p;
  if (k > 2) {
    cout << "NO";
  } else {
    if (k == 1) {
      if (n * 2 <= a)
        n *= 2;
      else if (m * 2 <= b)
        m *= 2;
    }
    cout << "YES\n0 0\n";
    cout << n << " 0\n";
    cout << "0 " << m;
  }
  return 0;
}
