#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long n, l, r, ql, qr;
  cin >> n >> l >> r >> ql >> qr;
  long long ans = INT64_MAX;
  vector<long long> prefix(n + 6, 0);
  vector<long long> suffix = prefix;
  vector<int> w(n + 5, 0);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    prefix[i] = w[i] + prefix[i - 1];
  }
  for (int i = n; i >= 0; i--) {
    suffix[i] = suffix[i + 1] + w[i];
  }
  for (int i = 0; i <= n; i++) {
    long long cost = prefix[i] * l + suffix[i + 1] * r;
    int right = n - i;
    int left = i;
    int diff = max(0, abs(right - left) - 1);
    cost += max(0ll, (right > left) ? qr * diff : ql * diff);
    ans = min(ans, cost);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
