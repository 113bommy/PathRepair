#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<long long> a(n + 1), sum(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  set<pair<long long, int>> s;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto it = s.rbegin(); it != s.rend(); it++) {
      if (sum[i] - 2 * a[i] > it->first) break;
      int l = it->second;
      if ((i - l >= 3) && (a[i] ^ a[l]) == (sum[i] - a[i] - sum[l])) ans++;
    }
    s.insert({sum[i] + a[i], i});
  }
  cout << ans;
  return 0;
}
