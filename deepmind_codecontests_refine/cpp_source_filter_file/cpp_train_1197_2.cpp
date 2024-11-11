#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<int, pair<int, int>> p[100005];
  int t, i, j, k, l, m, n, a[100005];
  vector<int> v;
  map<int, int> mp;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> p[i].second.first >> p[i].second.second;
    p[i].first = p[i].second.second - p[i].second.first;
    v.push_back(p[i].first);
    mp[p[i].first]++;
  }
  sort(p, p + n);
  sort(v.begin(), v.end());
  int flag = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (mp[a[i]] == 0) flag = 1;
  }
  if (flag) {
    cout << "NO";
    return 0;
  }
  pair<int, int> p1[100005];
  map<int, int> mp1;
  for (i = 0; i < n; i++) {
    auto itr = lower_bound(v.begin(), v.end(), a[i]);
    k = itr - v.begin();
    if (mp1[k] == 0) {
      p1[i].first = p[k].second.first;
      p1[i].second = p[k].second.second;
      mp1[k]++;
    } else {
      while (true) {
        k++;
        if (mp1[k] == 0) {
          p1[i].first = p[k].second.first;
          p1[i].second = p[k].second.second;
          mp1[k]++;
          break;
        }
      }
    }
  }
  for (i = 1; i < n; i++) {
    if (p1[i].first >= p1[i - 1].first || p1[i].second >= p1[i - 1].second)
      continue;
    else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (i = 0; i < n; i++) cout << p1[i].first << " " << p1[i].second << '\n';
  return 0;
}
