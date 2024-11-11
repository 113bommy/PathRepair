#include <bits/stdc++.h>
using namespace std;
using LL = long long;
class SCC {
 public:
  SCC(int _n) : n(_n), x(_n), y(_n) {}
  void AddEdge(int a, int b) {
    x[a].push_back(b);
    y[b].push_back(a);
  }
  void FDfs(int a, int& cnt, vector<bool>& z) {
    z[a] = true;
    for (int i : x[a]) {
      if (!z[i]) FDfs(i, cnt, z);
    }
    list[--cnt] = a;
  }
  void RDfs(int a, vector<bool>& z, vector<int>& ans) {
    z[a] = true;
    ans.push_back(a);
    for (int i : y[a]) {
      if (!z[i]) RDfs(i, z, ans);
    }
  }
  vector<vector<int>> GetScc() {
    list = vector<int>(n);
    vector<bool> z(n);
    int cnt = n;
    for (int i = 0; i < n; ++i) {
      if (!z[i]) FDfs(i, cnt, z);
    }
    z = vector<bool>(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
      if (!z[list[i]]) {
        vector<int> temp;
        RDfs(list[i], z, temp);
        ans.push_back(temp);
      }
    }
    return ans;
  }
  int n;
  vector<vector<int>> x;
  vector<vector<int>> y;
  vector<int> list;
};
struct dsu {
 public:
  dsu() : _n(0) {}
  dsu(int n) : _n(n), parent_or_size(n, -1) {}
  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }
  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }
  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }
  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }
  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int>& v) { return v.empty(); }),
        result.end());
    return result;
  }

 private:
  int _n;
  std::vector<int> parent_or_size;
};
const int MAXN = 100010;
const int MAXD = 52;
vector<int> x[MAXN];
vector<int> ox[MAXN];
LL fullmask;
vector<int> d0[MAXN];
vector<int> gx[MAXN];
int g[MAXN], leader[MAXN];
LL st[MAXN];
LL z[MAXN];
int n, m, day;
int gans[MAXN][MAXD];
int ans[MAXN][MAXD];
bool zl[MAXN][MAXD];
int in[MAXN];
LL Shift(LL a, int t) { return ((a << t) & fullmask) + (a >> (day - t)); }
void Solve(int leader, int group) {
  z[leader] = 1;
  queue<pair<int, LL>> Q;
  Q.push({leader, 1});
  while (!Q.empty()) {
    auto [a, b] = Q.front();
    Q.pop();
    if (b != z[a]) continue;
    while (!x[a].empty() && g[x[a].back()] < group) x[a].pop_back();
    if (x[a].empty()) continue;
    if (g[x[a].back()] > group) continue;
    LL nxt = Shift(b, 1);
    for (int i = x[a].size() - 1; i >= 0; --i) {
      if (g[x[a][i]] != group) break;
      if ((z[x[a][i]] | nxt) == z[x[a][i]]) continue;
      z[x[a][i]] |= nxt;
      Q.push({x[a][i], z[x[a][i]]});
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> day;
  fullmask = (1LL << day) - 1;
  SCC scc(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    scc.AddEdge(a, b);
    x[a].push_back(b);
  }
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < day; ++j) {
      if (s[j] == '1') st[i] |= (1LL << j);
    }
  }
  vector<vector<int>> allscc = scc.GetScc();
  dsu dsu(n);
  map<int, int> h;
  int groups = 0;
  for (int i = 0; i < allscc.size(); ++i) {
    g[allscc[i][0]] = groups;
    for (int j = 0; j + 1 < allscc[i].size(); ++j) {
      dsu.merge(allscc[i][j], allscc[i][j + 1]);
      g[allscc[i][j + 1]] = groups;
    }
    h[dsu.leader(allscc[i][0])] = groups;
    for (int j = 0; j < allscc[i].size(); ++j) {
      leader[allscc[i][j]] = dsu.leader(allscc[i][j]);
    }
    ++groups;
  }
  for (int i = 0; i < n; ++i) {
    sort(x[i].begin(), x[i].end(),
         [&](const int& a, const int& b) { return g[a] > g[b]; });
    ox[i] = x[i];
    for (int j : x[i]) {
      if (g[i] != g[j]) ++in[leader[j]];
    }
  }
  for (int i = 0; i < allscc.size(); ++i) {
    Solve(dsu.leader(allscc[i][0]), i);
  }
  for (int i = 0; i < n; ++i) {
    int t = dsu.leader(i);
    for (int j = 0; j < day; ++j) {
      if (Shift(z[i], j) == z[t]) d0[i].push_back(j);
    }
  }
  memset(gans, 0, sizeof(gans));
  for (int t = 0; t < allscc.size(); ++t) {
    int leader = dsu.leader(allscc[t][0]);
    for (int i = 0; i < day; ++i) {
      for (int j : allscc[t]) {
        if (Shift(z[j], i) & st[j]) {
          ++gans[leader][i];
        }
      }
    }
  }
  int t = dsu.leader(0);
  for (int i = 0; i < d0[0].size(); ++i) {
    zl[t][(day - d0[0][i]) % day] = true;
  }
  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    if (leader[i] == i && in[leader[i]] == 0) {
      Q.push(i);
    }
  }
  int anss = 0;
  while (!Q.empty()) {
    int a = Q.front();
    Q.pop();
    bool flag = false;
    for (int i = 0; i < day; ++i) {
      if (zl[a][i]) {
        flag = true;
        ans[a][i] += gans[a][i];
        anss = max(anss, ans[a][i]);
      }
    }
    for (int i : allscc[g[a]]) {
      for (int b : ox[i]) {
        if (g[b] == g[a]) continue;
        --in[leader[b]];
        if (in[leader[b]] == 0) {
          Q.push(leader[b]);
        }
        if (!flag) continue;
        LL mk = 0;
        for (int db : d0[b]) {
          for (int di : d0[i]) {
            int dist = (day - di + day - db + 1) % day;
            mk |= 1LL << dist;
          }
        }
        int lb = leader[b];
        for (int i = 0; i < day; ++i) {
          if (!zl[a][i]) continue;
          for (int j = 0; j < day; ++j) {
            if (mk >> j & 1) {
              ans[lb][(i + j) % day] = max(ans[lb][(i + j) % day], ans[a][i]);
              zl[lb][(i + j) % day] = true;
            }
          }
        }
      }
    }
  }
  cout << anss << endl;
  return 0;
}
