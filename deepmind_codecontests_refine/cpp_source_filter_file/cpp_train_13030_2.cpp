#include <bits/stdc++.h>
using namespace std;
int timer = 0;
void ap(int src, int par, vector<int>& low, vector<int>& in,
        vector<vector<int>>& graph, vector<pair<int, int>>& ans, bool isPoss) {
  in[src] = low[src] = timer++;
  for (int v : graph[src]) {
    if (in[v] == -1) {
      ans.push_back({src, v});
      ap(v, src, low, in, graph, ans, isPoss);
      if (in[src] < low[v]) {
        isPoss = true;
        return;
      }
      low[src] = min(low[src], low[v]);
    } else if (v != par) {
      low[src] = min(low[src], in[v]);
      if (in[src] > in[v]) ans.push_back({src, v});
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1, vector<int>());
  vector<int> in(n + 1, -1);
  vector<int> low(n + 1, -1);
  vector<pair<int, int>> ans;
  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  bool isBridge = false;
  ap(1, -1, low, in, graph, ans, isBridge);
  if (isBridge) {
    cout << "0" << '\n';
  } else {
    for (pair<int, int> p : ans) {
      cout << p.first << " " << p.second << "\n";
    }
  }
}
