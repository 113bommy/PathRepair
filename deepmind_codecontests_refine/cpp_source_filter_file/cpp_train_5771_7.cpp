#include <bits/stdc++.h>
using namespace std;
const int MN = 200111;
int n, k, p[MN], e[MN], cnt[MN];
vector<int> ls[MN];
multiset<int> s;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout << (fixed) << setprecision(6);
  while (cin >> n >> k) {
    for (int i = 0, _a = (MN); i < _a; i++) {
      cnt[i] = 0;
      ls[i].clear();
    }
    for (int i = (1), _b = (n); i <= _b; i++) {
      cin >> p[i] >> e[i];
      ls[p[i]].push_back(e[i]);
      ls[p[i] + 1].push_back(e[i]);
      cnt[p[i]] += 1;
    }
    for (int i = 0, _a = (MN); i < _a; i++) {
      if (i) cnt[i] += cnt[i - 1];
      sort(ls[i].begin(), ls[i].end());
    }
    s.clear();
    for (int i = (1), _b = (n); i <= _b; i++) s.insert(e[i]);
    int res = 1000111000;
    for (int win = (1), _b = (n - 1); win <= _b; win++) {
      int better = (win >= 2) ? cnt[win - 2] : 0;
      int need = (n + 1 - k) - better;
      if (need < 0) need = 0;
      if (need > ls[win].size()) continue;
      int cur = 0;
      vector<int> erased;
      for (int x = 0, _a = (need); x < _a; x++) {
        cur += ls[win][x];
        s.erase(s.find(ls[win][x]));
        erased.push_back(ls[win][x]);
      }
      for (int i = (1), _b = (win - need); i <= _b; i++) {
        int x = *s.begin();
        s.erase(s.begin());
        erased.push_back(x);
        cur += x;
      }
      for (int x : erased) {
        s.insert(x);
      }
      res = min(res, cur);
    }
    if (res == 1000111000) res = -1;
    cout << res << endl;
  }
  return 0;
}
