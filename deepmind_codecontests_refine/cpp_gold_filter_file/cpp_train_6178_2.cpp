#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > sol;
pair<int, int> ocu[1000100];
int n, m, t, x, kk, pu, p[1000100], pst, pend;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> t;
    kk = 0;
    while (t--) {
      ++kk;
      cin >> x;
      ocu[x] = make_pair(kk, i);
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!ocu[i].second) pu = i;
  pst = 1;
  for (int i = 1; i <= m; ++i) {
    t = 0;
    for (int j = 1; j <= n; ++j)
      if (ocu[j].second == i) {
        p[ocu[j].first] = j;
        t = max(ocu[j].first, t);
      }
    pend = pst + t - 1;
    kk = 0;
    for (int j = pst; j <= pend; ++j) {
      ++kk;
      if (ocu[j].second == i && ocu[j].first == kk) continue;
      if (ocu[j].second == i) {
        p[ocu[j].first] = pu;
        swap(ocu[j], ocu[pu]);
        sol.push_back(make_pair(j, pu));
        pu = j;
      }
      if (j == pu) {
        swap(ocu[pu], ocu[p[kk]]);
        pu = p[kk];
        sol.push_back(make_pair(p[kk], j));
      } else {
        swap(ocu[j], ocu[pu]);
        sol.push_back(make_pair(j, pu));
        pu = j;
        swap(ocu[p[kk]], ocu[pu]);
        sol.push_back(make_pair(p[kk], pu));
        pu = p[kk];
      }
    }
    pst = pend + 1;
  }
  cout << sol.size() << "\n";
  for (vector<pair<int, int> >::iterator it = sol.begin(); it != sol.end();
       it++)
    cout << it->first << " " << it->second << "\n";
  return 0;
}
