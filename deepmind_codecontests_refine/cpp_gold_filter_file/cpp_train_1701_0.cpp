#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<string, int> &p1, const pair<string, int> &p2) {
  return p1.second > p2.second;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<string, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end(), comp);
  vector<pair<string, int>> uniq;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    if (!mp[v[i].first]) {
      uniq.push_back(make_pair(v[i].first, v[i].second));
      mp[v[i].first] = 1;
    }
  }
  int sz = uniq.size();
  vector<pair<string, string>> ans;
  for (int i = 0; i < sz; i++) {
    int curr = 0;
    for (int j = 0; j < sz; j++) {
      if (i == j) {
        continue;
      }
      if (uniq[j].second > uniq[i].second) {
        curr++;
      }
    }
    double per = (double)(curr * 1.0) / sz;
    if (per * 100 > 50) {
      ans.push_back(make_pair(uniq[i].first, "noob"));
    } else if (per * 100 > 20) {
      ans.push_back(make_pair(uniq[i].first, "random"));
    } else if (per * 100 > 10) {
      ans.push_back(make_pair(uniq[i].first, "average"));
    } else if (per * 100 > 1) {
      ans.push_back(make_pair(uniq[i].first, "hardcore"));
    } else {
      ans.push_back(make_pair(uniq[i].first, "pro"));
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
