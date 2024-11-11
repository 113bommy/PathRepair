#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e18;
long long power(long long a, long long b) {
  long long res = 1;
  a %= mod;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % mod;
    }
    b /= 2;
    a = (a * a) % mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    for (long long i = 1; i < n; i += 2) {
      cout << i << " ";
    }
    for (long long i = n - 1; i >= 1; i -= 2) {
      cout << i << " ";
    }
    for (long long i = 2; i <= n; i += 2) {
      cout << i << " ";
    }
    for (long long i = n - 2; i >= 2; i--) {
      cout << i << " ";
    }
    cout << n << endl;
  } else {
    for (long long i = 1; i <= n; i += 2) {
      cout << i << " ";
    }
    for (long long i = n - 2; i >= 1; i -= 2) {
      cout << i << " ";
    }
    for (long long i = 2; i < n; i += 2) {
      cout << i << " ";
    }
    for (long long i = n - 1; i >= 2; i -= 2) {
      cout << i << " ";
    }
    cout << n << endl;
  }
}
