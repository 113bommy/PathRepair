#include <bits/stdc++.h>
void intl() {}
using namespace std;
long long round_up(long long a, long long b) { return (a + b - 1) / b; }
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long nCr(long long n, long long r, long long m, long long *fact,
              long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
void solve() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << "1";
    return;
  }
  if (n == 3) {
    cout << "7";
    return;
  }
  string ans = "";
  while (n > 0) {
    if (n % 2 == 1) {
      ans += "7";
      n -= 3;
    } else {
      ans += "1";
      n -= 2;
    }
  }
  cout << ans << endl;
}
signed main() {
  intl();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
