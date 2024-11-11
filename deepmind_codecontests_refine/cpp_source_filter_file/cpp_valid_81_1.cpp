#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
void solve() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> sum(n + 1, 0), a(n + 1);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1];
    if (s[i - 1] == '+')
      a[i] = 1;
    else
      a[i] = -1;
    if (i % 2)
      sum[i] += a[i];
    else
      sum[i] -= a[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (sum[r] - sum[l - 1] == 0)
      cout << 0;
    else if (r - l + 1 % 2)
      cout << 1;
    else
      cout << 2;
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
