#include <bits/stdc++.h>
using namespace std;
inline int ceil(int a, int b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
int32_t main() {
  ios::sync_with_stdio(false);
  string str;
  cin >> str;
  int n = str.size();
  vector<pair<int, char> > groups;
  for (int i = 0; i < n; i++) {
    if (i == 0 || str[i - 1] != str[i])
      groups.push_back(make_pair(1, str[i]));
    else
      groups.back().first++;
  }
  int res = 0;
  while (groups.size() > 1) {
    vector<int> tourCount(groups.size());
    for (int i = 1; i < groups.size() - 1; i++)
      tourCount[i] = ceil(groups[i].first, 2);
    tourCount[0] = groups[0].first;
    tourCount.back() = groups.back().first;
    int minTours = *min_element(tourCount.begin(), tourCount.end());
    vector<pair<int, char> > rebuild;
    for (int i = 0; i < groups.size(); i++) {
      if (tourCount[i] > minTours) {
        int amount = 0;
        if (i == 0 || i == groups.size() - 1)
          amount = groups[i].first - minTours;
        else
          amount = groups[i].first - 2 * minTours;
        if (rebuild.size() == 0 || rebuild.back().second != groups[i].second)
          rebuild.push_back(make_pair(amount, groups[i].second));
        else
          rebuild.back().first += amount;
      }
    }
    groups = rebuild;
    res += minTours;
  }
  cout << res << endl;
}
