#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> g[N];
pair<int, int> dfsMax(int v, int p, int op) {
  int cnt = g[v].size();
  if (p != 0) cnt -= 1;
  if (cnt == 0) {
    return {1, 1};
  }
  if (op == 1) {
    int tot = 0;
    int mn = 1e9;
    for (int u : g[v]) {
      if (u == p) continue;
      pair<int, int> tmp = dfsMax(u, v, 0);
      tot += tmp.first;
      mn = min(mn, tmp.first - tmp.second);
    }
    return {tot, tot - mn};
  } else {
    int tot = 0;
    int mn = 0;
    for (int u : g[v]) {
      if (u == p) continue;
      pair<int, int> tmp = dfsMax(u, v, 0);
      tot += tmp.first;
      mn += tmp.second - 1;
    }
    return {tot, mn + 1};
  }
}
pair<int, int> dfsMin(int v, int p, int op) {
  int cnt = g[v].size();
  if (p != 0) cnt -= 1;
  if (cnt == 0) {
    return {1, 1};
  }
  if (op == 0) {
    int tot = 0;
    int mn = 1e9;
    for (int u : g[v]) {
      if (u == p) continue;
      pair<int, int> tmp = dfsMax(u, v, 0);
      tot += tmp.first;
      mn = min(mn, tmp.second);
    }
    return {tot, mn};
  } else {
    int tot = 0;
    int mn = 0;
    for (int u : g[v]) {
      if (u == p) continue;
      pair<int, int> tmp = dfsMax(u, v, 0);
      tot += tmp.first;
      mn += tmp.second;
    }
    return {tot, mn};
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << dfsMax(1, 0, 1).second << " " << dfsMin(1, 0, 1).second << '\n';
  return 0;
}
