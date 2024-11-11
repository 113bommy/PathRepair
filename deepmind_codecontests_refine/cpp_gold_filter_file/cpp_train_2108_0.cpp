#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  long long sum = 0;
  long long p2 = 1;
  vector<int> ans;
  while (sum + p2 <= n) {
    sum += p2;
    ans.push_back(p2);
    p2 *= 2;
  }
  if (n - sum) ans.push_back(n - sum);
  sort(ans.begin(), ans.end());
  cout << ans.size() - 1 << '\n';
  for (int i = 1; i < (int)ans.size(); i++) cout << ans[i] - ans[i - 1] << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
