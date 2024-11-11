#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> type;
vector<int> g[200100];
int used[200100];
vector<int> tp;
void dfs1(int v) {
  used[v] = 1;
  for (auto to : g[v]) {
    if (!used[to]) dfs1(to);
  }
  tp.push_back(v);
}
void dfs2(int v) {
  used[v] = 1;
  for (auto to : g[v]) {
    if (!used[to]) {
      type[make_pair(v, to)] = 0;
      dfs2(to);
    } else if (used[to] != 1)
      type[make_pair(v, to)] = 0;
  }
  used[v] = 2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > ans;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    ans.push_back(make_pair(a, b));
    g[a].push_back(b);
    type[make_pair(a, b)] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!used[i]) dfs1(i);
  reverse(tp.begin(), tp.end());
  for (int i = 1; i <= n; i++) used[i] = 0;
  for (int i = 0; i < tp.size(); i++) {
    if (!used[tp[i]]) {
      dfs2(tp[i]);
    }
  }
  vector<int> print;
  int d = -1;
  bool bad = 1;
  for (int i = 0; i < ans.size(); i++) {
    print.push_back(type[ans[i]]);
    if (d != -1 && print.back() != d)
      bad = 0;
    else if (d == -1)
      d = print.back();
  }
  cout << 2 - bad << endl;
  for (int i = 0; i < print.size(); i++) {
    cout << print[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}
