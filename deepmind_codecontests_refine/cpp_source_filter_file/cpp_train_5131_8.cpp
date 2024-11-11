#include <bits/stdc++.h>
using namespace std;
const long long MOD = (int)998244353;
long long binPow(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = binPow(a, b / 2);
  ans = ans * ans % MOD;
  if (b % 2) ans = ans * a % MOD;
  return ans;
}
long long f(long long i) { return i * (i - 1) / 2; }
long long b, d, a;
long long ff(long long i) { return f(i + 1) * b * d - a * (i + 1); }
void solve() {
  long long c;
  cin >> a >> b >> c >> d;
  if (b * c < a) {
    cout << "-1\n";
    return;
  }
  int l = 0;
  int r = c / d;
  while (r - l > 1) {
    int c = (l + r) / 2;
    if (-ff(c) > -f(c + 1))
      l = c;
    else
      r = c;
  }
  long long ans = a;
  for (int i = max(0, l - 20); i <= min(c / d, (long long)r + 20); ++i)
    ans = max(ans, -ff(i));
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  srand(228);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
