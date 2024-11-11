#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> f(1e5 + 1);
  f[0] = f[1] = 1;
  for (int i = 2; i <= 1e5; ++i) {
    f[i] = (f[i - 1] + f[i - 2]) % MOD;
  }
  long long ans = (f[n] + f[m] - 1) * 2;
  cout << ans % MOD << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
