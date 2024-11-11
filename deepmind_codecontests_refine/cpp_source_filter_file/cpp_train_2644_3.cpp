#include <bits/stdc++.h>
using namespace std;
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first != b.first.first)
    return a.first.first < b.first.first;
  else if (a.first.second != b.first.second)
    return a.first.second < b.first.second;
  else
    return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, k(0);
  cin >> n;
  pair<pair<int, int>, int> group[n];
  int ans[n];
  bool flag;
  for (int i(0); i < n; ++i) {
    cin >> group[i].first.first >> group[i].first.second;
    group[i].second = i + 1;
  }
  sort(group, group + n, comp);
  for (int i(0); i < n; ++i) {
    flag = true;
    for (int j(0); j < n; ++j) {
      if (!flag) break;
      if (i == j) continue;
      if (j > 0 && j - 1 != i &&
          ((group[j].first.first < group[j - 1].first.first &&
            group[j].first.second <= group[j - 1].first.first) ||
           (group[j].first.first >= group[j - 1].first.second &&
            group[j].first.second > group[j - 1].first.second)))
        ;
      else if (j > 1 && j - 1 == i &&
               ((group[j].first.first < group[j - 2].first.first &&
                 group[j].first.second <= group[j - 2].first.first) ||
                (group[j].first.first >= group[j - 2].first.second &&
                 group[j].first.second > group[j - 2].first.second)))
        ;
      else if (j - 1 == i && j <= 1)
        ;
      else if (j - 1 != i && j == 0)
        ;
      else
        flag = false;
    }
    if (flag) {
      ans[k++] = group[i].second;
    }
  }
  sort(ans, ans + n);
  cout << k << "\n";
  for (int i(0); i < k; ++i) cout << ans[i] << " ";
  return 0;
}
