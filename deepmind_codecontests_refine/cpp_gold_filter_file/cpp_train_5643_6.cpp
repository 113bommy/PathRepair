#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, pair<long long, long long>> a,
          pair<long long, pair<long long, long long>> b) {
  if (a.second.first != b.second.first) return a.second.first < b.second.first;
  return a.second.second < b.second.second;
}
void sol() {
  long long n, m, i, j, k;
  cin >> n >> k;
  vector<pair<long long, pair<long long, long long>>> v;
  for (i = 0; i < n; i++) {
    cin >> m >> j;
    v.push_back({i, {m, j}});
  }
  sort(v.begin(), v.end(), comp);
  set<pair<long long, long long>> q;
  vector<long long> ans;
  for (i = 0; i < n;) {
    while (q.size()) {
      pair<long long, long long> p = *q.begin();
      if (p.first < v[i].second.first)
        q.erase(p);
      else
        break;
    }
    long long x = v[i].second.first;
    q.insert({v[i].second.second, v[i].first});
    i++;
    while (q.size() > k) {
      pair<long long, long long> p = *q.rbegin();
      q.erase(p);
      ans.push_back(p.second);
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i + 1 << " ";
}
int main() {
  sol();
  return 0;
}
