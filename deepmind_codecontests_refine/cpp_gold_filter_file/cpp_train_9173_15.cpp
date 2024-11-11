#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
const long long base = 1e9;
const double PI = acos(-1);
const long long MOD = 998244353;
const long long N = 1e5 + 10;
void solve();
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  long long f[n + 1], ans = 1;
  f[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    f[i] = (f[i - 1] * i) % MOD;
  }
  for (long long i = 1; i <= n; ++i) {
    ans = (((ans + f[i - 1] - 1) + MOD) % MOD * i) % MOD;
  }
  cout << ans << "\n";
  return;
}
