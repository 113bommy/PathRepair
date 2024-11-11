#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const string nl = "\n";
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  long long n, k, second, t;
  cin >> n >> k >> second >> t;
  vector<pair<long long, long long>> a(n);
  for (auto& i : a) {
    cin >> i.first >> i.second;
  }
  vector<long long> b(k);
  for (auto& i : b) {
    cin >> i;
  }
  sort(b.begin(), b.end());
  vector<long long> temp = {0};
  for (auto& i : b) {
    temp.push_back(i);
  }
  temp.push_back(second);
  b = temp;
  auto check = [&](long long x) -> bool {
    long long ans = 0;
    for (long long i = 0; i < ((long long)(b).size()); ++i) {
      long long dist = b[i] - (i == 0 ? 0 : b[i - 1]);
      long long hld = min(x - dist, dist);
      if (hld < 0) {
        return 0;
      }
      ans += hld + (dist - hld) * 2;
    }
    return ans <= t;
  };
  long long l = 0, r = 1e9;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  auto cmp = [&](pair<long long, long long> a,
                 pair<long long, long long> b) -> bool {
    return a.second < b.second;
  };
  sort(a.begin(), a.end(), cmp);
  long long ans = INF;
  for (long long i = 0; i < ((long long)(a).size()); ++i) {
    if (a[i].second >= l) {
      ans = min(ans, a[i].first);
    }
  }
  cout << (ans == INF ? -1 : ans) << nl;
}
