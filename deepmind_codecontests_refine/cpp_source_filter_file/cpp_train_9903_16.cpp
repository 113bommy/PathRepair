#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<array<ll, 2>> B(n);
  for (auto& _a : B) cin >> _a[1], --_a[1];
  for (auto& _a : B) cin >> _a[0];
  vector<ll> cnt(k, 0);
  for (auto [a, b] : B) ++cnt[b];
  sort(B.begin(), B.end());
  ll ib = 0;
  ll ans = 0;
  for (ll i = 0; i < k; ++i) {
    if (cnt[i]) continue;
    while (ib < n && cnt[B[ib][1]] <= 0) ++ib;
    --cnt[B[ib][1]];
    ans += B[ib++][0];
  }
  cout << ans << '\n';
}
