#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using pii = std::pair<long long, long long>;
using namespace std;
const long long maxn = 5e5 + 5;
long long n, a[maxn], origvals[maxn], bit[2][maxn];
long long sum(long long dir, long long idx) {
  long long curans = 0;
  for (++idx; idx > 0; idx -= idx & -idx) curans += bit[dir][idx];
  return curans;
}
void add(long long dir, long long idx, long long val) {
  for (++idx; idx < maxn; idx += idx & -idx) bit[dir][idx] += val;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<pii> compress;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    compress.push_back({a[i], i});
  }
  sort(compress.begin(), compress.end());
  for (long long i = 0; i < compress.size(); i++) {
    origvals[i] = compress[i].first;
    a[compress[i].second] = i;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    add(0, a[i], i + 1);
    long long cnt = (sum(0, a[i]) * (n - i)) % MOD;
    ans += (origvals[a[i]] * cnt) % MOD;
    ans %= MOD;
  }
  for (long long i = n - 1; i >= 0; i--) {
    add(1, a[i], n - i);
    long long cnt = (sum(1, a[i]) * (i + 1));
    ans += (origvals[a[i]] * cnt) % MOD;
    ans %= MOD;
  }
  for (long long i = 0; i < n; i++) {
    long long cnt = ((i + 1) * (n - i)) % MOD;
    ans -= (origvals[a[i]] * cnt) % MOD;
    ans += MOD;
    ans %= MOD;
  }
  cout << ans << "\n";
  return 0;
}
