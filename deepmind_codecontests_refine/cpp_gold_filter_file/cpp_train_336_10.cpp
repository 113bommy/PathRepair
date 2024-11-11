#include <bits/stdc++.h>
using namespace std;
long long a[200007], b[200007];
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res;
}
long long fact(long long n, long long p) {
  if (n >= p) return 0;
  long long result = 1;
  for (int i = 1; i <= n; i++) result = ((result % p) * (i % p)) % p;
  return result;
}
int main() {
  long long t = 1;
  while (t--) {
    long long i, j, k, l, ans = 0, count = 0, n;
    cin >> n;
    cout << (((fact(n, 1000000007)) + 1000000007) -
             (power(2, n - 1, 1000000007)) % 1000000007) %
                1000000007
         << "\n";
  }
}
