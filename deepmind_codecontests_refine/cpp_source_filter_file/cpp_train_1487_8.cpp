#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC optimize("unroll-loops")
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<long long>> pos(n + 1);
  for (long long i = 0; i < n; ++i) {
    pos[a[i]].push_back(i);
  }
  vector<long long> lens(n + 1, 1e9);
  for (long long i = 0; i <= n; ++i) {
    if (pos[i].empty()) {
      continue;
    }
    vector<long long> v = pos[i];
    long long ans = max(v.front() + 1, n - v.back());
    for (long long j = 0; j + 1 < (long long)v.size(); ++j) {
      ans = max(ans, v[j + 1] - v[j]);
    }
    lens[ans] = min(lens[ans], i);
  }
  for (long long i = 0; i < n - 1; ++i) {
    lens[i + 1] = min(lens[i], lens[i + 1]);
  }
  for (long long i = 1; i <= n; ++i) {
    if (lens[i] == 1e9) lens[i] = -1;
    cout << lens[i] << ' ';
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
