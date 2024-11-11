#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> diff(n);
  for (auto &x : diff) cin >> x;
  int curr = 1;
  reverse(diff.begin(), diff.end());
  int sum = 0;
  int add = 1;
  for (auto x : diff) {
    sum += 1ll * curr * x % MOD;
    sum %= MOD;
    curr = (2ll * curr + add) % MOD;
    add = 2ll * add % MOD;
  }
  cout << sum << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
