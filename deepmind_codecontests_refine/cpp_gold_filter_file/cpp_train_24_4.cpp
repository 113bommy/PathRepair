#include <bits/stdc++.h>
using namespace std;
long long int isprime[1000001];
void sieve() {
  long long int i, j, k;
  isprime[0] = isprime[1] = 1;
  for (i = 2; i <= sqrt(1000000); i++) {
    if (!isprime[i]) {
      for (j = 2 * i; j <= 1000000; j += i) {
        isprime[j] = 1;
      }
    }
  }
}
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long int mod(long long int x, long long int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    long long int y = mod(x, n / 2);
    return ((y % 1000000007) * (y % 1000000007)) % 1000000007;
  } else {
    return ((x % 1000000007) * (mod(x, (n - 1)) % 1000000007)) % 1000000007;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], i;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a[0] + a[1] > a[n - 1]) {
      cout << "-1" << endl;
    } else {
      cout << 1 << " " << 2 << " " << n << endl;
    }
  }
  return 0;
}
