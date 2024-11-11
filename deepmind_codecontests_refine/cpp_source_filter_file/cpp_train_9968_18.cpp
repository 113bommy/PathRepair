#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long INFLL = 1e12;
const long long MOD = 1000000007;
const long double eps = 1e-6;
const long long MOD2 = (1 << 30) + 1;
const long long dosz = 5e5;
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long precalc(long long n) {
  vector<bool> used(1e6, false);
  long long ans = 0;
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= n - i; j++) {
      for (long long l = 0; l <= n - i - j; l++) {
        if (!used[i + j * 5 + l * 10 + (n - i - j - l) * 50]) {
          used[i + j * 5 + l * 10 + (n - i - j - l) * 50] = true;
          ans++;
        }
      }
    }
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  if (n <= 20) {
    cout << precalc(n) << endl;
  } else {
    long long ans = precalc(n) + (n - 20) * 49;
    cout << ans << endl;
  }
}
signed main() {
  fast_io();
  long long q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
