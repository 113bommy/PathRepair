#include <bits/stdc++.h>
using namespace std;
const int MAXN = 222222;
const int INF = numeric_limits<int>::max();
unordered_map<string, int> id;
int text[MAXN];
pair<int, int> values[MAXN];
namespace main_graph {
vector<int> g[MAXN];
vector<int> gr[MAXN];
int used[MAXN];
pair<int, int> mn;
vector<int> comp;
int cnt = 0;
vector<int> sorted;
void cdfs(int v) {
  used[v] = 1;
  comp.push_back(v);
  for (int i = 0; i < gr[v].size(); i++) {
    int to = gr[v][i];
    if (!used[to]) cdfs(to);
  }
}
void tdfs(int v) {
  used[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (!used[to]) tdfs(to);
  }
  sorted.push_back(v);
}
void topological_sort() {
  sorted.reserve(cnt);
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= cnt; i++) {
    if (!used[i]) tdfs(i);
  }
}
}  // namespace main_graph
void to_lower(string& s) {
  for (int i = 0; i < s.length(); i++) {
    s[i] = tolower(s[i]);
  }
}
int rcount(const string& s) {
  int ans = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'r') ans++;
  }
  return ans;
}
void add_if_not_exist(string& s) {
  to_lower(s);
  if (!id[s]) {
    id[s] = ++main_graph::cnt;
    values[main_graph::cnt] = make_pair(rcount(s), s.length());
  }
}
pair<int, int> cvalues[MAXN];
vector<int> gc[MAXN];
int gcnt = 0;
int ncid[MAXN];
unordered_set<int> present[MAXN];
pair<int, int> dp[MAXN];
int used[MAXN];
void cond() {
  main_graph::topological_sort();
  memset(main_graph::used, 0, sizeof(main_graph::used));
  for (int i = int(main_graph::sorted.size()) - 1; i >= 0; i--) {
    int v = main_graph::sorted[i];
    if (!main_graph::used[v]) {
      main_graph::comp.clear();
      main_graph::cdfs(v);
      gcnt++;
      pair<int, int> mn(INF, INF);
      for (int j = 0; j < main_graph::comp.size(); j++) {
        ncid[main_graph::comp[j]] = gcnt;
        mn = min(mn, values[main_graph::comp[j]]);
      }
      cvalues[gcnt] = mn;
    }
  }
  for (int i = 1; i <= main_graph::cnt; i++) {
    for (int j = 0; j < main_graph::g[i].size(); j++) {
      int to = main_graph::g[i][j];
      int a = ncid[i], b = ncid[to];
      if (!present[a].count(b)) {
        gc[a].push_back(b);
        present[a].insert(b);
      }
    }
  }
}
void dfs(int v) {
  used[v] = 1;
  for (int i = 0; i < gc[v].size(); i++) {
    int to = gc[v][i];
    if (!used[to]) dfs(to);
    dp[v] = min(dp[v], dp[to]);
  }
}
int main() {
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    add_if_not_exist(s);
    text[i] = id[s];
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    add_if_not_exist(a);
    add_if_not_exist(b);
    main_graph::g[id[a]].push_back(id[b]);
    main_graph::gr[id[b]].push_back(id[a]);
  }
  cond();
  for (int i = 1; i <= gcnt; i++) {
    dp[i] = cvalues[i];
  }
  memset(used, 0, sizeof(used));
  int ans_r = 0, ans_cnt = 0;
  for (int i = 0; i < m; i++) {
    int v = ncid[text[i]];
    if (!used[v]) {
      dfs(v);
    }
    ans_r += dp[v].first;
    ans_cnt += dp[v].second;
  }
  cout << ans_r << " " << ans_cnt;
  return 0;
}
