#include <bits/stdc++.h>
using namespace std;
struct dat {
  int u, v;
  dat(int u = 0, int v = 0) : u(u), v(v) {}
} edg[150];
int num[150];
vector<int> con[150];
bool vis[150], vis1[150];
vector<pair<int, char> > rlt;
void dfs(int u) {
  vis[u] = 1;
  for (int v : con[u]) {
    if (!vis1[v]) {
      vis1[v] = 1;
      int k;
      char ch;
      if (edg[v].u == u)
        k = edg[v].v, ch = '-';
      else
        k = edg[v].u, ch = '+';
      dfs(k);
      rlt.emplace_back(v, ch);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> edg[i].u >> edg[i].v;
    con[edg[i].u].push_back(i);
    con[edg[i].v].push_back(i);
    num[edg[i].v]++;
    num[edg[i].u]++;
  }
  int cnt = 0;
  for (int i = 1; i <= 6; i++)
    if (num[i] % 2) cnt++;
  if (cnt && cnt != 2) return puts("No solution"), 0;
  for (int i = 1; i <= 6; i++)
    if (num[i]) {
      if ((!cnt || num[i] % 2) && !vis[i]) {
        dfs(i);
        break;
      }
    }
  if (rlt.size() != n) return puts("No solution"), 0;
  for (int i = 0; i < rlt.size(); i++)
    cout << rlt[i].first << " " << rlt[i].second << endl;
}
