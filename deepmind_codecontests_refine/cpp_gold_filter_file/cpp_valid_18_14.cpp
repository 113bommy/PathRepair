#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;
int64_t add(int64_t a, int64_t b) { return (a + b) % mod; }
int64_t sub(int64_t a, int64_t b) { return (a + mod - b) % mod; }
int64_t mul(int64_t a, int64_t b) { return a * b % mod; }
int64_t bpow(int64_t x, int64_t n) {
  return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int64_t inv(int64_t x) { return bpow(x, mod - 2); }
void solve() {
  int64_t n, k;
  cin >> n >> k;
  int64_t x[k + 1], y[k + 1];
  int64_t seg[2 * n];
  fill(seg, seg + 2 * n, 0);
  for (int64_t i = 1; i <= k; i++) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
    seg[x[i]] = seg[y[i]] = i;
  }
  int64_t ans = 0;
  int64_t t = n - k - 1;
  int64_t idx = k + 1;
  for (int64_t i = 0; i < 2 * n; i++) {
    vector<int64_t> cnt(n + 1);
    for (int64_t j = (i + 1) % (2 * n);; j = (j + 1) % (2 * n)) {
      if (seg[j] == seg[i]) {
        if (seg[j]) {
          break;
        } else if (cnt[0] == t) {
          seg[j] = seg[i] = idx++;
          t--;
          break;
        }
      }
      cnt[seg[j]]++;
    }
  }
  for (int64_t i = 0; i < 2 * n; i++) {
    vector<int64_t> cnt(n + 1);
    for (int64_t j = (i + 1) % (2 * n);; j = (j + 1) % (2 * n)) {
      if (seg[j] == seg[i]) {
        break;
      }
      cnt[seg[j]]++;
    }
    for (int64_t i = 1; i <= n; i++) {
      ans += cnt[i] % 2;
    }
  }
  cout << ans / 4 << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
