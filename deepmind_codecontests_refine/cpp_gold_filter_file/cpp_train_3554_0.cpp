#include <bits/stdc++.h>
using namespace std;
int getrd(int a, int b) { return (int)((100.0 * a) / b + 0.5); }
pair<int, int> occ[110];
map<int, set<int> > tst;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> df;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    df.push_back(x);
  }
  for (int i = 0; i < k; i++) occ[i] = make_pair(0, 0);
  int ctr = 0, don = 0;
  set<int> cur;
  set<int> ans, del;
  for (int i = 0; i <= 200000; i++) {
    for (int j = 0; j < k; j++) {
      if (occ[j].first) {
        tst[df[occ[j].second] - occ[j].first].erase(occ[j].second);
        occ[j].first--;
        tst[df[occ[j].second] - occ[j].first].insert(occ[j].second);
        if (!occ[j].first) {
          del.insert(occ[j].second);
        }
      }
    }
    if (getrd(don, n) > 0) {
      for (auto it = tst[getrd(don, n)].begin(); it != tst[getrd(don, n)].end();
           it++) {
        ans.insert(*it);
      }
    }
    while (del.size()) {
      int x = *del.begin();
      del.erase(x);
      tst[df[x]].erase(x);
      don++;
    }
    for (int j = 0; j < k; j++) {
      if (!occ[j].first) {
        if (ctr != n) {
          occ[j] = make_pair(df[ctr], ctr);
          tst[df[occ[j].second] - occ[j].first].insert(occ[j].second);
          ctr++;
        }
      }
    }
  }
  cout << ans.size() << '\n';
}
