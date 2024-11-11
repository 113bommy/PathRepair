#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
const long long int MOD = 998244353;
const int INF = 2e9;
const long long int INFLL = 1e18;
void solve() {
  long long int a, b, d = 0;
  cin >> a >> b;
  while ((d + 1) * (d + 2) / 2 <= a + b) ++d;
  vector<int> ans_a, ans_b;
  for (int i = d; i >= 1; --i) {
    if (a >= i) {
      a -= i;
      ans_a.push_back(i);
    } else {
      b -= i;
      ans_a.push_back(i);
    }
  }
  cout << ans_a.size() << '\n';
  for (int x : ans_a) cout << x << " ";
  cout << '\n' << ans_b.size() << '\n';
  for (int x : ans_b) cout << x << " ";
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
