#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int n, m;
vector<int> graph[MAXN];
bool used[MAXN];
void init() {
  for (int i = 0; i <= n; i++) {
    used[i] = 0;
    graph[i].clear();
  }
}
void read_input() {
  cin >> n >> m;
  init();
  int v, w;
  for (int i = 0; i < m; i++) {
    cin >> v >> w;
    graph[v].push_back(w);
    graph[w].push_back(v);
  }
}
int m_lvl;
map<int, vector<int>> mp;
map<int, int> par;
void dfs(int v, int lvl) {
  used[v] = true;
  m_lvl = max(m_lvl, lvl);
  mp[lvl].push_back(v);
  for (auto x : graph[v]) {
    if (!used[x]) {
      par[x] = v;
      dfs(x, lvl + 1);
    }
  }
}
void solve() {
  par.clear();
  mp.clear();
  m_lvl = 0;
  dfs(1, 0);
  if (m_lvl + 1 >= (n + 1) / 2) {
    cout << "PATH\n" << m_lvl + 1 << "\n";
    int sta = mp[m_lvl][0];
    for (int i = sta; i != 1; i = par[i]) {
      cout << i << " ";
    }
    cout << "1\n";
  } else {
    cout << "PAIRING\n";
    vector<pair<int, int>> ans;
    for (int i = 0; i <= m_lvl; i++) {
      for (int j = 0; j + 1 < mp[i].size(); j += 2) {
        ans.push_back({mp[i][j], mp[i][j + 1]});
      }
    }
    cout << ans.size() << "\n";
    for (auto x : ans) {
      cout << x.first << " " << x.second << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    read_input();
    solve();
  }
  return 0;
}
