#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int maxn = 200001;
long long int binpow(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b % 2) {
      res = (res * a) % mod;
      b--;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return res % mod;
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b % 2) {
      res = (res * a);
      b--;
    }
    a = (a * a);
    b /= 2;
  }
  return res;
}
bool isPrime(long long int n) {
  if (n == 1) return false;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int mulmod(long long int a, long long int b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long int addmod(long long int a, long long int b) {
  return (((a % mod) + (b % mod)) + mod) % mod;
}
void solve() {
  long long int n;
  cin >> n;
  n *= 4;
  long long int ar[n];
  for (long long int i = 0; i < n; i++) cin >> ar[i];
  ;
  sort(ar, ar + n);
  if (ar[n - 1] != ar[n - 2] or ar[0] != ar[1]) {
    cout << "NO"
         << "\n";
    return;
  }
  long long int area = ar[n - 1] * ar[0];
  for (long long int i = 2; i < n / 2; i += 2) {
    if (ar[i] != ar[i + 1] or ar[n - i - 1] != ar[n - i - 2] or
        area != (ar[i] * ar[n - i - 1])) {
      cout << "NO"
           << "\n";
      return;
    }
  }
  cout << "YES"
       << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  for (long long int tt = 1; tt <= t; tt++) {
    if (false) {
      cout << "Case #" << tt << ":"
           << "\n";
    }
    solve();
  }
}
