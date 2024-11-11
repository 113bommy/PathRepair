#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, pair<int, int>> m;
  vector<long long> ssum(n + 1);
  ssum[0] = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (m.find(x) == m.end()) {
      m[x] = {i, i};
    } else {
      m[x].second = i;
    }
    a[i] = x;
    ssum[i + 1] = ssum[i] + (long long)max(0, x);
  }
  pair<int, int> best_interval = {-1, -1};
  long long best_sum = (long long)INT_MIN * 1000LL;
  for (auto kv : m) {
    pair<int, int> p = kv.second;
    if (p.first != p.second) {
      long long curr = ssum[p.second + 1] - ssum[p.first];
      if (a[p.first] < 0) curr += a[p.first] * 2;
      if (best_sum <= curr) {
        best_sum = curr;
        best_interval = p;
      }
    }
  }
  vector<int> ans;
  long long sssum = 0;
  for (int i = 0; i < n; ++i) {
    if (best_interval.first < i && i < best_interval.second) {
      if (a[i] < 0)
        ans.push_back(i + 1);
      else
        sssum += a[i];
    } else if (best_interval.first != i && i != best_interval.second) {
      ans.push_back(i + 1);
    } else {
      sssum += a[i];
    }
  }
  cout << sssum << " " << ans.size() << "\n";
  for (int x : ans) cout << x << " ";
  return 0;
}
