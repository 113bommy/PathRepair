#include <bits/stdc++.h>
using namespace std;
const long long O = 1e10;
const int mod = 200907;
const int N = 3e6 + 5;
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int ONF = -0x3f3f3f3f;
const double PI = 3.1415926535898;
const double E = 2.718281828459;
char b[maxn], n[maxn], bb[maxn];
long long Big_mod(string s, long long m) {
  long long ans = 0;
  for (int i = 0; i < s.length(); i++) {
    ans = ans * 10 + (s[i] - '0');
    ans %= m;
  }
  return ans;
}
long long quick_mod(long long a, long long b, long long MOD) {
  long long ans = 1;
  a %= MOD;
  while (b) {
    if (b & 1) {
      ans = ans * a % MOD;
      b--;
    }
    b >>= 1;
    a = a * a % MOD;
  }
  return ans;
}
long long Euler(long long x) {
  long long ans = x;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      ans = ans * (i - 1) / i;
    }
  }
  if (x > 1) ans = ans * (x - 1) / x;
  return ans;
}
int main() {
  long long c;
  while (cin >> b >> n >> c) {
    long long m = strlen(n) - 1;
    while (!(n[m] - '0')) {
      n[m] = '9';
      m--;
    }
    n[m] -= 1;
    if (n[0] == '0') memcpy(n, n + 1, sizeof(n));
    memcpy(bb, b, sizeof(b));
    m = strlen(bb) - 1;
    while (!(bb[m] - '0')) {
      bb[m] = '9';
      m--;
    }
    bb[m] -= 1;
    if (bb[0] == '0') memcpy(bb, bb + 1, sizeof(bb));
    long long bbb = Big_mod(bb, c);
    long long po = Euler(c);
    long long p = Big_mod(n, po) + po;
    long long a = Big_mod(b, c);
    long long ans = quick_mod(a, p, c);
    ans = (ans * bbb) % c;
    if (n[0] == '\0') {
      ans = Big_mod(b, c);
      ans = (ans - 1 + c) % c;
    }
    if (ans)
      cout << ans << endl;
    else
      cout << c << endl;
  }
  return 0;
}
