#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 228;
vector<int> g[MX];
vector<int> rg[MX];
vector<int> comps[MX];
vector<int> aa[MX];
int seg[MX];
int sz = 0;
int num = 0;
int order[MX];
bool used[MX];
int xx[MX];
void dfs1(int v) {
  used[v] = true;
  for (int to : g[v])
    if (!used[to]) dfs1(to);
  order[sz] = v;
  ++sz;
}
void dfs2(int v) {
  seg[v] = num;
  comps[num].push_back(v);
  for (int to : rg[v])
    if (seg[to] == -1) dfs2(to);
}
signed main() {
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << "! 1" << endl;
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
    rg[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i)
    if (!used[i]) dfs1(i);
  for (int i = 1; i <= n; ++i) seg[i] = -1;
  for (int i = n - 1; i >= 0; --i)
    if (seg[order[i]] == -1) {
      dfs2(order[i]);
      ++num;
    }
  for (int i = 1; i <= n; ++i) {
    for (int to : g[i]) {
      if (seg[to] != seg[i]) aa[seg[i]].push_back(seg[to]);
    }
  }
  for (int i = 0; i < m; ++i) {
    sort(aa[i].begin(), aa[i].end());
    aa[i].erase(unique(aa[i].begin(), aa[i].end()), aa[i].end());
    for (int to : aa[i]) xx[to]++;
  }
  vector<int> kek;
  for (int i = 0; i < m; ++i)
    if (!xx[i]) kek.push_back(i);
  int from = kek.size() > 0 ? kek[0] : 0;
  for (int i = 1; i < kek.size(); ++i) {
    int to = kek[i];
    while (comps[from].size() > 0 && comps[to].size() > 0) {
      cout << "? " << comps[from].back() << " " << comps[to].back() << endl;
      int a;
      cin >> a;
      if (a == 1)
        comps[to].pop_back();
      else
        comps[from].pop_back();
      if (comps[from].empty()) swap(to, from);
    }
    for (int j : aa[to]) {
      xx[j]--;
      if (xx[j] == 0) kek.push_back(j);
    }
  }
  cout << "! " << comps[from].back();
  return 0;
}
