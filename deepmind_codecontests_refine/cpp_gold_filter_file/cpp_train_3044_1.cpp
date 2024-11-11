#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    std::vector<pair<long long int, long long int>> v(n);
    for (auto &x : v) cin >> x.first >> x.second;
    long long int sum[n];
    sum[0] = v[0].first;
    for (i = 1; i < n; i++) {
      sum[i] = sum[i - 1] + max(v[i].first - v[i - 1].second, (long long int)0);
    }
    long long int mn = 1e18;
    for (i = 0; i < n; i++) {
      if (i == 0) {
        mn = min(mn, sum[n - 1]);
        continue;
      }
      long long int x = 0;
      x += sum[n - 1] - sum[i - 1];
      if (v[i].first > v[i - 1].second)
        x += v[i - 1].second;
      else
        x += v[i].first;
      x += sum[i - 1];
      if (v[0].first > v[n - 1].second)
        x -= v[n - 1].second;
      else
        x -= v[0].first;
      mn = min(mn, x);
    }
    cout << mn << "\n";
  }
  return 0;
}
