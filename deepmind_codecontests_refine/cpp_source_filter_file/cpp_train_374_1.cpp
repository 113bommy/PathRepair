#include <bits/stdc++.h>
using namespace std;
const int B = 26;
vector<set<int>> g(B);
vector<set<int>> ginv(B);
int color[B];
void DFS_cyc(int v) {
  color[v] = 1;
  if (g[v].size() > 1) {
    cout << "NO";
    exit(0);
  }
  for (auto u : g[v]) {
    if (color[u] == 0) DFS_cyc(u);
    if (color[u] == 1) {
      cout << "NO";
      exit(0);
    }
  }
  color[v] = 2;
}
void cycle() {
  for (int i = 0; i < B; ++i) color[i] = 0;
  for (int i = 0; i < B; ++i)
    if (color[i] == 0) DFS_cyc(i);
}
void DFSinv_cyc(int v) {
  color[v] = 1;
  if (ginv[v].size() > 1) {
    cout << "NO";
    exit(0);
  }
  for (auto u : ginv[v]) {
    if (color[u] == 0) DFS_cyc(u);
    if (color[u] == 1) {
      cout << "NO";
      exit(0);
    }
  }
  color[v] = 2;
}
void invcycle() {
  for (int i = 0; i < B; ++i) color[i] = 0;
  for (int i = 0; i < B; ++i)
    if (color[i] == 0) DFSinv_cyc(i);
}
void DFS(int v) {
  color[v] = 1;
  char r = v + 'a';
  cout << r;
  for (auto u : g[v]) {
    if (color[u] == 0) DFS(u);
  }
  color[v] = 2;
}
void solve() {
  int n;
  cin >> n;
  string now;
  int cnt[B], cntt[B];
  for (int i = 0; i < B; ++i) cnt[i] = 0, cntt[i] = 0;
  for (int i = 0; i < n; ++i) {
    cin >> now;
    for (auto p : now) cntt[p - 'a']++;
    for (int j = 0; j < now.size() - 1; ++j)
      g[now[j] - 'a'].insert(now[j + 1] - 'a'), cnt[now[j + 1] - 'a']++;
    for (int j = 1; j < now.size(); ++j)
      ginv[now[j] - 'a'].insert(now[j - 1] - 'a');
  }
  cycle();
  invcycle();
  for (int i = 0; i < B; ++i) color[i] = 0;
  for (int i = 0; i < B; ++i)
    if (color[i] == 0 && cnt[i] == 0 && cntt[i] != 0) DFS(i);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
