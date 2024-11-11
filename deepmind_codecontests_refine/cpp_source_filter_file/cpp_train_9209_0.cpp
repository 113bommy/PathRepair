#include <bits/stdc++.h>
using namespace std;
int n, m, mm, q;
const int maxn = 1e5 + 100;
const int maxs = 321;
vector<pair<int, int> > road[maxn];
int fa[maxn][maxs];
map<pair<int, int>, int> mapa;
vector<int> bign, sman;
int father(int x, int p) {
  if (fa[x][p] == x) return x;
  return fa[x][p] = father(fa[x][p], p);
}
void unionn(int x, int y, int p) {
  if (father(x, p) != father(y, p)) fa[father(x, p)][p] = father(y, p);
}
void work() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    road[w].push_back(make_pair(u, v));
  }
  mm = floor(sqrt(m));
  for (int i = 1; i <= m; i++) {
    if (road[i].size() >= mm)
      bign.push_back(i);
    else
      sman.push_back(i);
  }
  for (int i = 0; i < bign.size(); i++) {
    for (int j = 1; j <= m; j++) fa[j][i] = j;
    for (int j = 0; j < road[bign[i]].size(); j++) {
      pair<int, int> tmp = road[bign[i]][j];
      unionn(tmp.first, tmp.second, i);
    }
  }
  int uu = bign.size();
  for (int i = 0; i < sman.size(); i++) {
    set<int> second;
    vector<int> ve;
    for (int j = 0; j < road[sman[i]].size(); j++) {
      pair<int, int> tmp = road[sman[i]][j];
      second.insert(tmp.first);
      second.insert(tmp.second);
    }
    for (set<int>::iterator it = second.begin(); it != second.end(); it++)
      ve.push_back(*it);
    for (int j = 0; j < ve.size(); j++) fa[ve[j]][uu] = ve[j];
    for (int j = 0; j < road[sman[i]].size(); j++) {
      pair<int, int> tmp = road[sman[i]][j];
      unionn(tmp.first, tmp.second, uu);
    }
    for (int j = 0; j <= (long long)ve.size() - 2; j++) {
      for (int k = j + 1; k <= (long long)ve.size() - 1; k++) {
        int u = min(ve[j], ve[k]);
        int v = max(ve[j], ve[k]);
        if (father(u, uu) == father(v, uu)) mapa[make_pair(u, v)]++;
      }
    }
  }
}
void solve() {
  work();
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int u, v;
    cin >> u >> v;
    int tmp1 = 0, tmp2;
    for (int j = 0; j < bign.size(); j++) {
      if (father(u, j) == father(v, j)) tmp1++;
    }
    tmp2 = mapa[make_pair(min(u, v), max(u, v))];
    cout << tmp1 + tmp2 << endl;
  }
}
int main() {
  solve();
  return 0;
}
