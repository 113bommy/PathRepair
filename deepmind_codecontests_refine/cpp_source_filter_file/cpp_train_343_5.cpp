#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<vector<pair<long long, long long>>> ans(k);
  long long gr = k, cnt = 0;
  bool f = false;
  vector<pair<pair<long long, long long>, long long>> a(n);
  long double c = 0;
  for (long long i = 1; i <= n; ++i) {
    pair<long long, long long> x;
    cin >> x.first >> x.second;
    if (x.second == 1 && gr > 1) gr--;
    if (x.second == 1) cnt++;
    if (x.second == 2) f = true;
    a[i - 1] = {x, i};
  }
  sort(a.begin(), a.end(),
       greater<pair<pair<long long, long long>, long long>>());
  k--;
  long long free = 0;
  for (long long i = 0; i < n; ++i) {
    if (k == -1) {
      for (long long j = i; j < n; ++j) {
        ans[free].push_back({a[i].first.first, a[i].second});
        if (free + 1 < gr) free++;
      }
      break;
    }
    if (a[i].first.second == 1) {
      ans[k].push_back({a[i].first.first, a[i].second});
      k--;
    } else {
      ans[free].push_back({a[i].first.first, a[i].second});
      if (free + 1 < gr) free++;
    }
  }
  cout << fixed << setprecision(1);
  k = ans.size();
  for (long long i = 0; i < ans.size(); ++i) {
    long long mn = 1e9;
    sort(ans[i].begin(), ans[i].end());
    for (long long j = 0; j < ans[i].size(); ++j) {
      if (j == 0 && k - cnt - 1 < i)
        c += (long double)ans[i][j].first / 2;
      else
        c += ans[i][j].first;
    }
  }
  cout << c << '\n';
  for (auto i : ans) {
    cout << i.size() << ' ';
    for (auto j : i) cout << j.second << ' ';
    cout << '\n';
  }
}
