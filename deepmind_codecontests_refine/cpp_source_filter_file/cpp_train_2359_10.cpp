#include <bits/stdc++.h>
using namespace std;
long long pw(long long base, long long e) {
  return e ? pw(base * base, e / 2) * (e % 2 ? base : 1) : 1;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long to_int(string s) {
  long long ret = 0;
  for (int i = 0; i <= s.size(); i++) {
    ret += pw(10, s.size() - i - 1) * (long long)(s[i] - '0');
  }
  return ret;
}
const int maxn = 1e5 + 10, mod = 1e9 + 7;
const long long INF = 1e9;
long long n;
long long f(long long x) { return (n - x) / (2 * x); }
int main() {
  cin >> n;
  n--;
  long long ans = 0;
  for (int i = 1; i <= log2(n); i++) {
    ans += pw(2, i) * (f(pw(2, i)) + 1);
  }
  return cout << ans << "\n", 0;
}
