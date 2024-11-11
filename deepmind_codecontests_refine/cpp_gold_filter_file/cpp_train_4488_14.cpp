#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  string second;
  cin >> second;
  vector<long long> cnt(k, 0);
  for (long long i = 0; i < n; i++) {
    cnt[second[i] - 'A']++;
  }
  long long ans = cnt[0];
  for (long long i = 0; i < k; i++) {
    ans = min(ans, cnt[i]);
  }
  cout << ans * k << endl;
}
signed main() {
  long long n = 1;
  while (n--) {
    solve();
  }
}
