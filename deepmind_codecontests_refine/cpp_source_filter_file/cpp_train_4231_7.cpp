#include <bits/stdc++.h>
using namespace std;
long long n, ans = 1;
vector<long long> cnt;
vector<long long> use;
vector<long long> use1;
void solve() {
  cin >> n;
  cnt.resize(n);
  use.resize(n + 1, 0);
  unordered_set<long long> check;
  check.insert(0);
  for (long long i = 0; i < n; ++i) cin >> cnt[i];
  for (long long i = 0; i < n; ++i) {
    if (check.find(cnt[i]) == check.end()) {
      check.insert(i);
      ++ans;
    } else {
      check.erase(check.find(cnt[i]));
      check.insert(i + 1);
    }
  }
  cout << ans;
}
signed main() {
  solve();
  return 0;
}
