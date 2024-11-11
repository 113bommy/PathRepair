#include <bits/stdc++.h>
long long int power(long long int a, long long int n) {
  long long int p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long int power(long long int a, long long int n, long long int mod) {
  long long int p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    long long int m;
    cin >> n >> m;
    if (n == 1) {
      cout << 0 << endl;
    } else if (n == 2) {
      cout << m << endl;
    } else if (m == n) {
      cout << 2 * n << endl;
    } else if (n > m) {
      cout << 2 * m << endl;
    } else {
      cout << n + m << endl;
    }
  }
}
