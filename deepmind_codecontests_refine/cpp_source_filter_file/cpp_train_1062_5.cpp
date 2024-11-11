#include <bits/stdc++.h>
using namespace std;
const long long MXN = 2e3 + 10;
const long long MXM = 5e2 + 10;
const long long MX5 = 1e5 + 10;
const long long MX6 = 1e6 + 10;
const long long LOG = 20;
const long long INF = 8e18;
const double eps = 1e-9;
const long long MOD = 1e9 + 7;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
long long bmm(long long a, long long b) {
  return (a % b == 0 ? b : bmm(b, a % b));
}
string base2(long long n) {
  string a = "";
  while (n >= 2) {
    a += (char)(n % 2 + '0');
    n /= 2;
  }
  a += (char)(n + '0');
  reverse((a).begin(), (a).end());
  return a;
}
void solve() {
  long long x;
  string s;
  cin >> x >> s;
  long long ans = s.size();
  for (int i = 0; i < x; i++) {
    long long now = s[i] - '0', r = s.size() - i - 1;
    if (now == 1) continue;
    if (s.size() < x) {
      string Now = s.substr(i + 1, r);
      for (int j = 0; j < now; j++) {
        s += Now;
      }
    }
    now--;
    ans = (ans + ((ans - i + 1 + MOD) * now) % MOD) % MOD;
  }
  cout << ans << '\n';
  return;
}
int main() {
  long long q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
