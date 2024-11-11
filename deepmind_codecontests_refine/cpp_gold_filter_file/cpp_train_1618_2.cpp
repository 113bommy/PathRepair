#include <bits/stdc++.h>
using namespace std;
void operator+(vector<int> &a, vector<int> &b) {
  for (auto x : b) a.push_back(x);
}
const int maxn = 1e5 + 5;
int n, m, col[maxn];
bool can1 = 1, can2 = 1;
bool mark[maxn];
vector<pair<int, bool> > adj[maxn];
vector<int> ans1[2], ans2[2], vans, ans, Ans1, Ans2;
void dfs2(int v, int c = 1) {
  mark[v] = 1;
  col[v] = c;
  ans2[c].push_back(v);
  for (auto u : adj[v])
    if (!mark[u.first])
      dfs2(u.first, (c + u.second) % 2);
    else if (col[u.first] != (c + u.second) % 2) {
      can2 = 0;
      return;
    }
}
void dfs1(int v, int c = 1) {
  mark[v] = 1;
  col[v] = c;
  ans1[c].push_back(v);
  for (auto u : adj[v])
    if (!mark[u.first])
      dfs1(u.first, (c + u.second + 1) % 2);
    else if (col[u.first] != (c + u.second + 1) % 2) {
      can1 = 0;
      return;
    }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c == 'B'});
    adj[v].push_back({u, c == 'B'});
  }
  for (int i = 1; i <= n; i++)
    if (!mark[i]) {
      dfs1(i);
      if (ans1[0].size() < ans1[1].size())
        Ans1 + ans1[0];
      else
        Ans1 + ans1[1];
      ans1[0].clear(), ans1[1].clear();
    }
  memset(mark, 0, sizeof mark);
  for (int i = 1; i <= n; i++)
    if (!mark[i]) {
      dfs2(i);
      if (ans2[0].size() < ans2[1].size())
        Ans2 + ans2[0];
      else
        Ans2 + ans2[1];
      ans2[0].clear(), ans2[1].clear();
    }
  if ((!can1) && (!can2)) return cout << -1 << '\n', 0;
  if ((Ans2.size() < Ans1.size() && can2) || !can1) {
    cout << Ans2.size() << '\n';
    for (auto x : Ans2) cout << x << " ";
  } else {
    cout << Ans1.size() << '\n';
    for (auto x : Ans1) cout << x << " ";
  }
}
