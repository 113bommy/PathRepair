#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, e;
  cin >> n >> e;
  vector<vector<int> > teams(n);
  vector<pair<int, int> > E(e);
  for (int i = 0; i < e; ++i) {
    cin >> E[i].first >> E[i].second;
    --E[i].first;
    --E[i].second;
  }
  int T = 1;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    teams[i] = vector<int>(l);
    for (int j = 0; j < l; ++j) {
      cin >> teams[i][j];
      T = max(teams[i][j], T);
    }
  }
  vector<int> c(1e6 + 10, 0);
  vector<int> l(1e6 + 10, -1);
  srand(1231245);
  int cnt = 0;
  while (true) {
    vector<int> team(n);
    for (int i = 0; i < n; ++i) {
      team[i] = teams[i][rand() % teams[i].size()];
      if (l[team[i]] != cnt) {
        l[team[i]] = cnt;
        c[team[i]] = rand() % 2;
      }
    }
    int ecnt = 0;
    for (int i = 0; i < e; ++i) {
      int u = E[i].first, v = E[i].second;
      if (c[team[u]] != c[team[v]]) ++ecnt;
    }
    ++cnt;
    if (ecnt * 2 >= e) {
      for (int i = 0; i < n; ++i) cout << (i ? " " : "") << team[i];
      cout << endl;
      for (int i = 1; i <= T; ++i) cout << (i != 1 ? " " : "") << c[i] + 1;
      cout << endl;
      break;
    }
  }
}
