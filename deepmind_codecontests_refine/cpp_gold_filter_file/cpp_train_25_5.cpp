#include <bits/stdc++.h>
using namespace std;
bool isprime(int64_t n) {
  for (int64_t i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int64_t factorial(int64_t n) {
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
int64_t gcd(int64_t a, int64_t b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b) * b); }
int64_t max(int64_t a, int64_t b) {
  int64_t sol = a > b ? a : b;
  return sol;
}
int64_t min(int64_t a, int64_t b) {
  int64_t sol = a < b ? a : b;
  return sol;
}
int64_t power(int64_t x, int64_t y) {
  int64_t ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans *= x;
    }
    y >>= 1LL;
    x *= x;
  }
  return ans;
}
int64_t inf = 100000000001;
inline int64_t solve() {
  int64_t n;
  cin >> n;
  string s[n];
  for (int64_t i = 0; i <= n - 1; ++i) {
    cin >> s[i];
  }
  if (s[0][1] == s[1][0]) {
    if (s[n - 1][n - 2] == s[n - 2][n - 1]) {
      if (s[0][1] == s[n - 1][n - 2]) {
        cout << 2 << "\n";
        cout << n << " " << n - 1 << "\n";
        cout << n - 1 << " " << n << "\n";
      } else {
        cout << 0 << "\n";
      }
    } else if (s[n - 1][n - 2] == s[0][1]) {
      cout << 1 << "\n";
      cout << n << " " << n - 1 << "\n";
    } else if (s[n - 2][n - 1] == s[0][1]) {
      cout << 1 << "\n";
      cout << n - 1 << " " << n << "\n";
    }
  } else {
    if (s[n - 1][n - 2] == s[n - 2][n - 1]) {
      if (s[n - 1][n - 2] == s[0][1]) {
        cout << 1 << "\n";
        cout << 1 << " " << 2 << "\n";
      } else {
        cout << 1 << "\n";
        cout << 2 << " " << 1 << "\n";
      }
    } else {
      if ((s[0][1] == s[n - 1][n - 2] && s[1][0] == s[n - 2][n - 1])) {
        cout << 2 << "\n";
        cout << 1 << " " << 2 << "\n";
        cout << n - 1 << " " << n << "\n";
      } else if ((s[1][0] == s[n - 1][n - 2] && s[0][1] == s[n - 2][n - 1])) {
        cout << 2 << "\n";
        cout << 1 << " " << 2 << "\n";
        cout << n << " " << n - 1 << "\n";
      } else {
        cout << 2 << "\n";
        cout << 1 << " " << 2 << "\n";
        cout << n << " " << n - 1 << "\n";
      }
    }
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int64_t t;
  cin >> t;
  while (t--) {
    solve();
  }
}
