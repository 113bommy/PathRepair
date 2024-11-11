#include <bits/stdc++.h>
using namespace std;
int fs[1000000];
bool pos[1000000], ss[1000000];
bool ass[1000000], sat[1000000];
bool vis[1000000], evis[1000000];
vector<vector<pair<int, int> > > ad;
bool dfs(int i) {
  if (sat[i] || vis[i]) return true;
  vis[i] = true;
  for (int j = 0; j < ad[i].size(); j++) {
    int ed = ad[i][j].second;
    if (evis[ed]) continue;
    evis[ed] = true;
    if (dfs(ad[i][j].first)) {
      if ((fs[ed] == i && pos[ed]) || (fs[ed] != i && !pos[ed]))
        ass[ed] = true;
      else
        ass[ed] = true;
      sat[i] = true;
      return true;
    }
    evis[ed] = false;
  }
  vis[i] = false;
  return false;
}
int main() {
  int n, m, k, l;
  scanf("%d", &n);
  scanf("%d", &m);
  ad.resize(n);
  for (int i = 0; i < m + 1; i++) fs[i] = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &l);
      int ind = abs(l);
      if (fs[ind] != (-1)) {
        if (l > 0 && pos[ind]) {
          sat[i] = sat[fs[ind]] = true;
          ass[ind] = true;
        } else if (l < 0 && !pos[ind]) {
          sat[i] = sat[fs[ind]] = true;
          ass[ind] = false;
        } else {
          ad[i].push_back(make_pair(fs[ind], ind));
          ad[fs[ind]].push_back(make_pair(i, ind));
        }
        ss[ind] = true;
      } else {
        fs[ind] = i;
        if (l > 0) pos[ind] = true;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (fs[i] != -1 && !ss[i]) {
      sat[fs[i]] = true;
      if (pos[i])
        ass[i] = true;
      else
        ass[i] = false;
    }
  }
  bool poss = true;
  for (int i = 0; i < n; i++) {
    if (sat[i]) continue;
    if (!dfs(i)) {
      poss = false;
      break;
    }
  }
  if (poss) {
    cout << "YES\n";
    for (int i = 1; i <= m; i++) cout << ass[i];
    cout << endl;
  } else
    cout << "NO\n";
  return 0;
}
