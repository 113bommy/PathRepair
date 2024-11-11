#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 101;
const long long INF = 1e18;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> st(n);
  st[0] = 1;
  for (int i = 0; i < n; ++i) {
    st[i + 1] = st[i] * 10 % MOD;
  }
  for (long long i = 1; i < n; i++) {
    long long ans = 0;
    ans += 2ll * 10 * 9 * st[n - i - 1];
    ans %= MOD;
    ans += (n - i - 1) * 10 * 81 * st[n - i - 2];
    ans %= MOD;
    cout << ans << ' ';
  }
  cout << 10 << ' ';
}
