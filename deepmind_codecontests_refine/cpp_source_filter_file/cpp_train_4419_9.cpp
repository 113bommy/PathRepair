#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, int>> groups(n);
  for (int i = 0; i < n; ++i) {
    get<0>(groups[i]) = i;
    cin >> get<1>(groups[i]) >> get<2>(groups[i]);
  }
  int k;
  cin >> k;
  map<int, set<int>> tables;
  for (int i = 0; i < k; ++i) {
    int t;
    cin >> t;
    if (auto itr = tables.find(t); itr == tables.end())
      tables[t] = set<int>{i};
    else
      itr->second.insert(i);
  }
  sort(groups.begin(), groups.end(),
       [](const tuple<int, int, int> &g1, const tuple<int, int, int> &g2) {
         if (get<2>(g1) > get<2>(g2))
           return true;
         else if (get<2>(g1) == get<2>(g1))
           return get<1>(g1) < get<1>(g2);
         else
           return false;
       });
  int moneyMade = 0;
  vector<pair<int, int>> arrangements;
  arrangements.reserve(n);
  for (int i = 0; i < n; ++i) {
    int size = get<1>(groups[i]);
    if (auto pos = tables.lower_bound(size); pos != tables.end()) {
      moneyMade += get<2>(groups[i]);
      arrangements.push_back(
          make_pair(get<0>(groups[i]), *(pos->second.begin())));
      pos->second.erase(pos->second.begin());
      if (pos->second.empty()) tables.erase(pos);
    }
  }
  int seated = arrangements.size();
  cout << seated << " " << moneyMade << "\n";
  for (pair<int, int> aa : arrangements)
    cout << aa.first + 1 << " " << aa.second + 1 << "\n";
  return 0;
}
