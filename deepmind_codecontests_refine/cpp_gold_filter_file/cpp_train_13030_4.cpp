#include <bits/stdc++.h>
const double PI = 3.141592653589793238460;
using namespace std;
vector<int> ar[100001];
int in[100001], low[100001], vis[100001], timer;
bool hasBridge;
vector<pair<int, int> > edgeList;
void dfs(int node, int par) {
  vis[node] = 1;
  in[node] = low[node] = timer++;
  for (int child : ar[node]) {
    if (child == par) continue;
    if (vis[child]) {
      low[node] = min(low[node], in[child]);
      if (in[node] > in[child]) edgeList.push_back({node, child});
    } else {
      dfs(child, node);
      if (low[child] > in[node]) {
        hasBridge = true;
        return;
      }
      edgeList.push_back({node, child});
      low[node] = min(low[node], low[child]);
    }
  }
}
int main() {
  int n, m, a, b;
  cin >> n >> m;
  while (m--) cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);
  dfs(1, -1);
  if (hasBridge) {
    cout << 0;
  } else {
    for (pair<int, int> e : edgeList)
      cout << e.first << " " << e.second << '\n';
  }
}
