#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > ht;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int di, hi;
    cin >> di >> hi;
    ht.push_back(make_pair(di, hi));
  }
  int max_h = ht[0].second;
  for (int i = 1; i < m; ++i) {
    if (ht[i].second - ht[i - 1].second > ht[i].first - ht[i - 1].first ||
        ht[i - 1].second - ht[i].second > ht[i].first - ht[i - 1].first) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    max_h = max(
        max_h,
        (ht[i - 1].second + ht[i].second + ht[i].first - ht[i - 1].first) / 2);
  }
  max_h = max(max_h, ht[0].second + ht[0].first - 1);
  max_h = max(max_h, ht[ht.size() - 1].second + n - ht[ht.size() - 1].first);
  cout << max_h << endl;
  return 0;
}
