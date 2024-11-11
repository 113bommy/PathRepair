#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e9;
const long long int INFF = 1e18;
const long long int M = 998244353;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> x(n), y(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> s[i];
  }
  vector<long long int> loop(n);
  vector<long long int> pre(n + 1), q(n + 1);
  for (int i = 0; i < n; i++) {
    auto lb = lower_bound(x.begin(), x.end(), y[i]);
    loop[i] = lb - x.begin();
    q[i + 1] = (((x[i] % M - y[i] % M + M) % M + pre[i + 1 - 1]) % M -
                pre[loop[i] + 1 - 1] + M) %
               M;
    pre[i + 1] = (pre[i + 1 - 1] + q[i + 1]) % M;
  }
  long long int ans = (x[n - 1] + 1) % M;
  for (int i = 0; i < n; i++) {
    if (s[i] == 1) {
      ans = (ans + q[i + 1]) % M;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  int tt = t;
  while (t--) {
    solve();
  }
  return 0;
}
