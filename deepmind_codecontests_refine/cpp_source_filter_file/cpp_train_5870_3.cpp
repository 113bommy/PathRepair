#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const long long MOD = 1e9 + 7;
int n, m, cnt, c, idx[2 * N], low[2 * N], val[2 * N], comp[2 * N],
    comp_head[2 * N];
bool in_stack[2 * N];
stack<int> stk;
vector<vector<int> > g;
vector<pair<int, int> > roads;
inline int Not(int a) { return (a >= m ? a - m : a + m); }
inline void add(int a, int b) {
  g[Not(a)].push_back(b);
  g[Not(b)].push_back(a);
}
inline bool isIntersct(pair<int, int> a, pair<int, int> b) {
  return ((a.first > b.first && a.first < b.second && a.second > b.second) ||
          (b.first > a.first && b.first < a.second && b.second > a.second));
}
void dfs(int u) {
  idx[u] = low[u] = ++cnt;
  in_stack[u] = 1;
  stk.push(u);
  for (int i = 0; i < g[u].size(); i++) {
    if (idx[g[u][i]] == -1) dfs(g[u][i]);
    if (in_stack[g[u][i]]) low[u] = min(low[u], low[g[u][i]]);
  }
  if (idx[u] == low[u]) {
    while (!stk.empty()) {
      int v = stk.top();
      stk.pop();
      in_stack[v] = 0;
      comp[v] = c;
      if (v == u) break;
    }
    comp_head[c++] = u;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  roads.resize(m);
  g.resize(2 * m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &roads[i].first, &roads[i].second);
    if (roads[i].first > roads[i].second) swap(roads[i].first, roads[i].second);
  }
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      if (isIntersct(roads[i], roads[j])) {
        add(i, j);
        add(Not(i), Not(j));
      }
    }
  memset(idx, -1, sizeof idx);
  for (int i = 0; i < 2 * m; i++)
    if (idx[i] == -1) dfs(i);
  for (int i = 0; i < m; i++)
    if (comp[i] == comp[Not(i)]) {
      puts("Impossible");
      return 0;
    }
  memset(val, -1, sizeof val);
  for (int i = 0; i < c; i++)
    if (val[i] == -1) {
      val[i] = 0;
      val[comp[Not(comp_head[comp[i]])]] = 1;
    }
  string ans = "";
  for (int i = 0; i < m; i++) ans += !val[comp[i]] ? "i" : "o";
  puts(ans.c_str());
  return 0;
}
