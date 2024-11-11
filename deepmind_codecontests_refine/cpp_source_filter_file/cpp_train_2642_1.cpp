#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
const int INF = 0x3fffffff;
const double EPS = 1e-9;
const double PI = 2 * asin(1);
int g_n, g_m;
vector<bool> vb;
vector<int> vi_ans, vi_dge;
vector<vector<int>> vvi_edge;
void pretreat() {}
bool input() {
  cin >> g_n >> g_m;
  if (cin.eof()) return false;
  vb.clear(), vb.resize(g_n + 1);
  vi_ans.clear(), vi_ans.resize(g_n + 1);
  vi_dge.clear(), vi_dge.resize(g_n + 1);
  vvi_edge.clear(), vvi_edge.resize(g_n + 1);
  for (int i = 0, u, v; i < g_m; ++i) {
    scanf(" %d %d", &u, &v);
    vvi_edge[u].push_back(v);
    vvi_edge[v].push_back(u);
    ++vi_dge[u], ++vi_dge[v];
  }
  return true;
}
void solve() {
  queue<int> qi;
  for (int i = 1; i <= g_n; ++i) {
    if (vi_dge[i] > 1) qi.push(i), vb[i] = true;
  }
  while (!qi.empty()) {
    int u = qi.front();
    qi.pop();
    vb[u] = false;
    if (vi_dge[u] < 2) continue;
    vi_ans[u] ^= 1;
    int k = 0;
    for (int i = 0; i < vvi_edge[u].size(); ++i) {
      int v = vvi_edge[u][i];
      if (vi_ans[u] == vi_ans[v])
        ++vi_dge[v], ++k;
      else
        --vi_dge[v];
      if (!vb[v] && k > 1) qi.push(v), vb[v] = true;
    }
    vi_dge[u] = k;
    if (k > 1) qi.push(u), vb[u] = true;
  }
  for (int i = 1; i <= g_n; ++i) printf("%d", vi_ans[i]);
  puts("");
}
int main() {
  pretreat();
  while (input()) {
    solve();
  }
  return 0;
}
