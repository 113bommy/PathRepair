#include <bits/stdc++.h>
using namespace std;
void solve();
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
void solve() {
  int64_t n, k;
  cin >> n >> k;
  int64_t co = 1;
  vector<int64_t> ans;
  while (k--) {
    ans.push_back(co);
    co++;
    ans.push_back(co);
    co++;
    ans.push_back(co + 1);
    ans.push_back(co);
    co += 2;
  }
  for (int64_t i = co - 1; i < 2 * n; i += 2) {
    ans.push_back(co);
    ans.push_back(co + 1);
    co += 2;
  }
  for (int64_t i = 0; i < 2 * n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
