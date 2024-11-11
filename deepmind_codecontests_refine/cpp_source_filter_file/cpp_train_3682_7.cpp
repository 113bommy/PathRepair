#include <bits/stdc++.h>
using namespace std;
int clrsvis[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int clr[100005];
  vector<int> clrindx[100005];
  vector<int> adj[100005];
  for (int i = 0; i < n; i++) {
    cin >> clr[i];
    clrindx[clr[i]].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  int maxx = 0, ans = 0;
  map<int, int> mymap;
  for (int i = 0; i < n; i++) {
    int k = clr[i];
    if (clrsvis[k]) continue;
    clrsvis[k] = 1;
    int cnt = 0;
    int len = clrindx[k].size();
    for (int j = 0; j < len; j++) {
      int v = clrindx[k][j];
      int len1 = 0;
      if (!adj[v].empty()) len1 = adj[v].size();
      for (int x = 0; x < len1; x++) {
        int u = adj[v][x];
        if (k != clr[u] && mymap.empty()) {
          mymap[clr[u]] = 1;
          cnt++;
        } else if (k != clr[u] && mymap.find(clr[u]) == mymap.end()) {
          mymap[clr[u]] = 1;
          cnt++;
        }
      }
    }
    if (maxx < cnt) {
      maxx = cnt;
      ans = clr[i];
    } else if (maxx == cnt) {
      if (ans > clr[i]) ans = clr[i];
    }
    mymap.clear();
  }
  cout << ans;
  return 0;
}
