#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 5;
int n, m;
int color[N], timer[N];
vector<pair<int, int>> go[N];
bool used[N];
vector<int> sat[N];
vector<int> rev_sat[N];
vector<int> topo;
int comp[N];
int scc;
struct Cmp {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    return color[a.second] < color[b.second];
  }
};
void dfs_topo(int v) {
  used[v] = true;
  for (int to : sat[v])
    if (!used[to]) dfs_topo(to);
  topo.push_back(v);
}
void dfs_scc(int v, int c) {
  comp[v] = c;
  for (int to : rev_sat[v])
    if (comp[to] == -1) dfs_scc(to, c);
}
int inv(int x) {
  if (x < 2 * m) return x ^ 1;
  return ((x - 2 * m) ^ 1) + 2 * m;
}
void add_edge(int a, int b) {
  sat[a].push_back(b);
  sat[inv(b)].push_back(inv(a));
}
bool good(int max_t) {
  fill(used, used + 6 * m, false);
  topo.clear();
  scc = 0;
  for (int i = 0; i < 6 * m; i++) {
    sat[i].clear();
    rev_sat[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int pos = 0;
    for (int j = 1; j <= (int)go[i].size(); j++)
      if (j == (int)go[i].size() ||
          color[go[i][j].second] != color[go[i][pos].second]) {
        if (j - pos > 2) return false;
        if (j - pos == 2) {
          int x = go[i][pos].second;
          int y = go[i][pos + 1].second;
          add_edge(2 * x, 2 * y + 1);
          add_edge(2 * x + 1, 2 * y);
          if (timer[x] > max_t && timer[y] > max_t) return false;
          if (timer[x] > max_t) add_edge(2 * x + 1, 2 * x);
          if (timer[y] > max_t) add_edge(2 * y + 1, 2 * y);
        }
        pos = j;
      }
  }
  int deg = 0;
  for (int i = 0; i < n; i++) {
    int old_deg = deg;
    for (auto e : go[i]) {
      int x = e.second;
      add_edge(2 * x + 1, 2 * m + 2 * deg + 1);
      if (old_deg < deg) {
        add_edge(2 * m + 2 * (deg - 1) + 1, 2 * m + 2 * deg + 1);
        add_edge(2 * m + 2 * (deg - 1) + 1, 2 * x);
      }
      deg++;
    }
    if (old_deg < deg)
      add_edge(2 * m + 2 * (deg - 1), 2 * m + 2 * (deg - 1) + 1);
  }
  for (int i = 0; i < 6 * m; i++)
    for (int to : sat[i]) rev_sat[to].push_back(i);
  for (int i = 0; i < 6 * m; i++)
    if (!used[i]) dfs_topo(i);
  reverse(topo.begin(), topo.end());
  fill(comp, comp + 6 * m, -1);
  for (int i : topo)
    if (comp[i] == -1) {
      dfs_scc(i, scc);
      scc++;
    }
  for (int i = 0; i < m; i++)
    if (comp[2 * i] == comp[2 * i + 1]) return false;
  for (int i = 0; i < 2 * m; i++)
    if (comp[2 * m + 2 * i] == comp[2 * m + 2 * i + 1]) return false;
  return true;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c, t;
    scanf("%d%d%d%d", &a, &b, &c, &t);
    a--;
    b--;
    color[i] = c;
    timer[i] = t;
    go[a].emplace_back(b, i);
    go[b].emplace_back(a, i);
  }
  for (int i = 0; i < n; i++) sort(go[i].begin(), go[i].end(), Cmp());
  int left = 0, right = (int)1e9 + 1;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (good(mid))
      right = mid;
    else
      left = mid;
  }
  if (right == (int)1e9 + 1) {
    puts("No");
    return;
  }
  good(right);
  vector<int> res;
  for (int i = 0; i < m; i++)
    if (comp[2 * i + 1] > comp[2 * i]) res.push_back(i);
  puts("Yes");
  printf("%d %d\n", right, (int)res.size());
  for (int e : res) printf("%d ", e + 1);
  printf("\n");
}
int main() {
  solve();
  0;
  return 0;
}
