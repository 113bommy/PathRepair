#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2550;
const int INF = 1e9;
int n, m;
bool mark[maxn], bmark[maxn];
vector<int> g[maxn], bg[maxn], ord, comp[maxn];
void dfs(int u) {
  mark[u] = 1;
  for (auto v : g[u])
    if (!mark[v]) dfs(v);
  ord.push_back(u);
}
int k, com[maxn];
void bdfs(int u) {
  bmark[u] = 1;
  com[u] = k;
  comp[k].push_back(u);
  for (auto v : bg[u])
    if (!bmark[v]) bdfs(v);
}
bool top_mark[maxn];
vector<int> top, g1[maxn];
void top_dfs(int u) {
  top_mark[u] = 1;
  for (auto v : g1[u])
    if (!top_mark[v]) top_dfs(v);
  top.push_back(u);
}
void slv_sat() {
  for (int v = 1; v <= 2 * m; v++)
    if (!mark[v]) dfs(v);
  while (ord.size()) {
    int v = ord.back();
    ord.pop_back();
    if (!bmark[v]) {
      k++;
      bdfs(v);
    }
  }
  for (int v = 1; v <= m; v++)
    if (com[v] == com[m + v]) {
      cout << "Impossible";
      exit(0);
    }
  for (int i = 1; i <= k; i++)
    for (auto v : comp[i])
      for (auto u : g[v])
        if (com[u] != i) g1[i].push_back(com[u]);
  for (int v = 1; v <= k; v++)
    if (!top_mark[v]) top_dfs(v);
  for (int i = 0; i < top.size(); i++)
    for (auto v : comp[top[i]]) com[v] = i;
}
int l[maxn], r[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i];
    if (r[i] < l[i]) swap(l[i], r[i]);
    for (int j = 1; j < i; j++)
      if (min(r[i], r[j]) > max(l[i], l[j]) &&
          !((r[i] >= r[j] && l[i] <= l[j]) ||
            ((r[j] >= r[i] && l[j] <= l[i])))) {
        g[i].push_back(m + j);
        g[j].push_back(m + i);
        g[m + i].push_back(j);
        g[m + j].push_back(i);
        bg[i].push_back(m + j);
        bg[j].push_back(m + i);
        bg[m + i].push_back(j);
        bg[m + j].push_back(i);
      }
  }
  slv_sat();
  for (int i = 1; i <= m; i++)
    if (com[i] > com[m + i])
      cout << "i";
    else
      cout << "o";
}
