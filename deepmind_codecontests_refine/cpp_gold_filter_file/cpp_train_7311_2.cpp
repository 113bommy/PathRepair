#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> sum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }
  map<ll, int> cnt;
  ll res = 0;
  for (int l = 0, r = 0; l < n; l++) {
    while (r <= n) {
      if (cnt[sum[r]]) break;
      ++cnt[sum[r]];
      ++r;
    }
    res += r - l - 1;
    --cnt[sum[l]];
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
