#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793;
const int mod = 1e9 + 7;
int CASE = 1;
const int mxn = 2e5 + 1;
const long long infll = 1e18;
const int infi = 1e9;
bool prime(long long n) {
  if (n <= 1) return false;
  if (n == 2 or n == 3) return true;
  if (n % 2 == 0 or n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long __gcd(long long a, long long b) { return !b ? a : __gcd(b, a % b); }
long long power(long long a, long long b, long long MOD) {
  long long x = a, res = 1, p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
    x %= MOD, res %= MOD;
  }
  return res;
}
void solve() {
  string s;
  cin >> s;
  if (s.length() & 1) {
    string str = "AHhIMOoTUVvWwXxY";
    if (str.find(s[s.length() / 2]) == -1) {
      cout << "NIE";
      return;
    }
  }
  string s1 = "AbdHhIMOoTUVvWwXxY", s2 = "AdbHhIMOoTUVvWwXxY";
  for (long long i = 0; i < s.length() >> 1; i++) {
    if (s1.find(s[i]) == -1 ||
        (s1.find(s[i]) != s2.find(s[s.length() - 1 - i]))) {
      cout << "NIE";
      return;
    }
  }
  puts("TAK");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
