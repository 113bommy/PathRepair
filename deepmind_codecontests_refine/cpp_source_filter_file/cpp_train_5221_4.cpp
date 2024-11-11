#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> f(vector<pair<long long, long long>> arr) {
  long long right = -1;
  vector<pair<long long, long long>> p;
  for (auto segment : arr) {
    if (segment.first >= right) {
      right = segment.second;
      p.push_back(segment);
    }
  }
  return p;
}
int32_t main() {
  iostream::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> arr(n);
  map<long long, vector<pair<long long, long long>>> v;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long i = 0; i < n; i++) {
    long long sum = 0;
    for (long long j = i; j < n; j++) {
      sum += arr[j];
      v[sum].push_back({i, j});
    }
  }
  vector<pair<long long, long long>> ans;
  for (auto e : v) {
    vector<pair<long long, long long>> a = f(e.second);
    if (a.size() > ans.size()) ans = a;
  }
  cout << ans.size() << '\n';
  for (auto e : ans) cout << e.first + 1 << ' ' << e.second + 1 << '\n';
  return 0;
}
