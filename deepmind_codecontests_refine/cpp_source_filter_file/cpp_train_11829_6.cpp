#include <bits/stdc++.h>
using namespace std;
const long double Pi = 3.14159265359;
const long long MOD = 1000 * 1000 * 1000 + 7;
const long long MAXN = 2e5 + 10;
const long long INF = 1e18;
long long n, m, v, u;
vector<long long> g[MAXN];
set<pair<long long, long long> > h[MAXN];
set<long long> back_edge[MAXN];
long long Max = 0;
bool mark[MAXN];
vector<pair<pair<long long, long long>, long long> > ans;
long long par[MAXN];
vector<long long> com;
vector<long long> child[MAXN];
void DFS(long long v, long long p = -1, long long hei = 0) {
  mark[v] = 1;
  par[v] = p;
  long long Cnt = 0;
  com.push_back(v);
  Max = max(Max, hei);
  for (auto u : g[v]) {
    if (mark[u] && u != p) {
      back_edge[v].insert(u);
      Cnt++;
    }
  }
  for (auto u : g[v]) {
    if (!mark[u]) {
      DFS(u, v, hei + 1);
    }
  }
  h[hei].insert({(Cnt + 1) % 2, v});
}
long long ans1 = 0;
void Episode(long long v) {
  Max = 0;
  DFS(v);
  for (auto u : com) {
    while (back_edge[u].size() >= 2) {
      v = *(back_edge[u].begin());
      back_edge[u].erase(v);
      long long uu = *(back_edge[u].begin());
      back_edge[u].erase(uu);
      ans.push_back({{v, u}, uu});
    }
  }
  long long Cnt = 0;
  for (auto u : com) {
    Cnt += g[u].size();
  }
  ans1 += (Cnt / 2) / 2;
  for (int i = Max; i >= 1; i--) {
    set<long long> pa;
    for (auto u : h[i]) {
      if (u.first == 0) {
        ans.push_back(
            {{par[u.second], u.second}, *(back_edge[u.second].begin())});
      } else {
        pa.insert(par[u.second]);
        child[par[u.second]].push_back(u.second);
      }
    }
    for (auto u : pa) {
      for (int j = 0; j < child[u].size(); j += 2) {
        if (j != child[u].size() - 1) {
          ans.push_back({{child[u][j], u}, child[u][j + 1]});
        }
      }
      if (child[u].size() % 2 == 1 && i != 1) {
        v = child[u][child[u].size() - 1];
        if (back_edge[u].size()) {
          ans.push_back({{*(back_edge[u].begin()), u}, v});
          h[i - 1].erase({0, u});
          h[i - 1].insert({1, u});
        } else {
          ans.push_back({{par[u], u}, v});
          h[i - 1].erase({1, u});
        }
      }
    }
  }
  for (auto u : com) {
    back_edge[u].clear();
    child[u].clear();
  }
  for (int i = 0; i < Max; i++) h[i].clear();
  com.clear();
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> v >> u;
    g[v].push_back(u), g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) {
      Episode(i);
    }
  }
  cout << ans1 << '\n';
  for (auto u : ans) {
    cout << u.first.first << ' ' << u.first.second << ' ' << u.second << '\n';
  }
  return 0;
}
