#include <bits/stdc++.h>
using namespace std;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
long long expo(long long n, long long m, long long p) {
  long long r = 1;
  n = n % p;
  while (m > 0) {
    if (m % 2) r = (r * n) % p;
    n = (n * n) % p;
    m = m / 2;
  }
  return r % p;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1]) {
      cout << "No" << '\n';
      return 0;
    }
  }
  if (s[0] == '?' || s[n - 1] == '?') {
    cout << "Yes" << '\n';
    return 0;
  }
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] == '?' && s[i + 1] == '?') {
      cout << "Yes" << '\n';
      return 0;
    }
    if (s[i] == '?' && i > 0 && s[i + 1] == s[i - 1]) {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
}
