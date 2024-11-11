#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int inf = 1e9;
string s[N];
int n, m, k;
pair<int, int> st, en;
string t;
pair<int, int> pos[26];
int dis[27][N][N];
vector<pair<pair<int, int>, int> > g[N][N];
vector<pair<pair<int, int>, int> > g2[N][N];
void dijkstra(int x, int y, int id) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) dis[id][i][j] = inf;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  pq.push({0, (x * m) + y});
  while (!pq.empty()) {
    auto z = pq.top();
    pq.pop();
    int xx = (z.second / m);
    int yy = (z.second % m);
    if (dis[id][xx][yy] <= z.first) continue;
    dis[id][xx][yy] = z.first;
    if ((xx != x || yy != y) && s[xx][yy] >= 'a' && s[xx][yy] <= 'z') continue;
    for (auto v : g[xx][yy]) {
      int cur_best = v.second + z.first;
      if (dis[id][v.first.first][v.first.second] >= cur_best)
        pq.push({cur_best, (v.first.first * m) + v.first.second});
    }
  }
}
void pre() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#') continue;
      int cst = 0;
      if (s[i][j] >= 'a' && s[i][j] <= 'z')
        cst = 1;
      else
        cst = (s[i][j] - '0');
      if (i > 0 && s[i - 1][j] != '#') g[i][j].push_back({{i - 1, j}, cst});
      if (j > 0 && s[i][j - 1] != '#') g[i][j].push_back({{i, j - 1}, cst});
      if (i < n - 1 && s[i + 1][j] != '#') g[i][j].push_back({{i + 1, j}, cst});
      if (j < m - 1 && s[i][j + 1] != '#') g[i][j].push_back({{i, j + 1}, cst});
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (auto x : g[i][j])
        g2[x.first.first][x.first.second].push_back({{i, j}, x.second});
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] >= 'a' && s[i][j] <= 'z') {
        pos[s[i][j] - 'a'] = {i, j};
        dijkstra(i, j, s[i][j] - 'a');
      }
  dijkstra(en.first, en.second, 26);
}
void travel(pair<int, int> p, pair<int, int> q, int id) {
  while (p != q) {
    pair<int, int> nex = {-1, -1};
    int cst = -1;
    for (auto x : g2[p.first][p.second]) {
      if (dis[id][x.first.first][x.first.second] + x.second ==
          dis[id][p.first][p.second]) {
        nex = x.first;
        cst = x.second;
      }
    }
    if (k < cst) {
      cout << p.first + 1 << ' ' << p.second + 1;
      exit(0);
    }
    k -= cst;
    p = nex;
  }
  if (k <= 0) {
    cout << p.first + 1 << ' ' << p.second + 1;
    exit(0);
  }
}
void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> s[i];
  cin >> st.first >> st.second;
  cin >> t;
  cin >> en.first >> en.second;
  st.first--, st.second--;
  en.first--, en.second--;
  pre();
  for (auto x : t) {
    pair<int, int> temp_des = pos[x - 'a'];
    travel(st, temp_des, x - 'a');
    st = temp_des;
  }
  travel(st, en, 26);
  cout << en.first + 1 << ' ' << en.second + 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
