#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long LINF = 1e18;
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> caves(n);
  for (long long i{}; i < n; ++i) {
    long long t;
    cin >> t;
    for (long long j{}; j < t; ++j) {
      long long a;
      cin >> a;
      caves[i].push_back(a);
    }
  }
  vector<pair<long long, long long>> t;
  for (long long i{}; i < n; ++i) {
    long long need = caves[i][0] + 1;
    for (long long j{1}; j < caves[i].size(); ++j) {
      if (caves[i][j] >= need + j) {
        need = caves[i][j] - j + 1;
      }
    }
    t.push_back({need, -(long long)(caves[i].size())});
  }
  sort(t.begin(), t.end());
  long long totaladd = -t[0].second, out = t[0].first;
  for (long long i{1}; i < t.size(); ++i) {
    if (out + totaladd <= t[i].first) {
      out = t[i].first - totaladd;
    }
    totaladd -= t[i].second;
  }
  cout << out << '\n';
}
long long main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  for (long long t = 1; t <= tc; t++) {
    solve();
  }
}
