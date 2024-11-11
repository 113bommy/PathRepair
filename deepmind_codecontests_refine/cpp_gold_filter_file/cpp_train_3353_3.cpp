#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int give[257] = {};
  bool test[256] = {};
  int i, j, n, d[257] = {}, t[257] = {}, v1, v2, v3;
  bool done[8] = {};
  int donor[8] = {};
  vector<int> all_d[8];
  vector<pair<int, int>> ed;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> v1 >> v2 >> v3;
    d[i] = (v1 ? 1 : 0) + (v2 ? 2 : 0) + (v3 ? 4 : 0);
    all_d[d[i]].push_back(i);
  }
  for (i = 1; i <= n; i++) {
    cin >> v1 >> v2 >> v3;
    t[i] = (v1 ? 1 : 0) + (v2 ? 2 : 0) + (v3 ? 4 : 0);
  }
  for (i = 0; i < 7; i++) done[i] = !all_d[i].size();
  done[0] = 1;
  test[1] = 1;
  donor[7] = 1;
  int deal = 1, dealt = 0;
  while (deal != dealt) {
    dealt = deal;
    for (i = 1; i < 8; i++) {
      if (done[i] || !all_d[i].size()) continue;
      if (!donor[i]) {
        if (i == 3 || i == 5 || i == 6) {
          int rest = i & (i - 1), new_donor = all_d[i][0];
          if (donor[i & (-i)] && donor[rest]) {
            ed.push_back(make_pair(donor[i & (-i)], new_donor));
            ed.push_back(make_pair(donor[rest], new_donor));
            donor[i] = new_donor;
            give[new_donor] = i;
          }
        }
      }
      if (donor[i]) {
        deal++;
        for (auto v : all_d[i]) {
          if (v == donor[i]) continue;
          ed.push_back(make_pair(donor[i], v));
          test[v] = true;
          give[v] = d[v] & t[v];
          if (!donor[give[v]]) donor[give[v]] = v;
        }
        done[i] = 1;
      }
    }
  }
  for (i = 0; i < 8; i++)
    if (!done[i]) break;
  if (i != 8) {
    cout << "Impossible\n";
    return 0;
  }
  cout << "Possible\n";
  for (i = 1; i <= n; i++) cout << test[i] << " ";
  cout << "\n";
  cout << ed.size() << "\n";
  for (auto e : ed) cout << e.first << " " << e.second << "\n";
}
