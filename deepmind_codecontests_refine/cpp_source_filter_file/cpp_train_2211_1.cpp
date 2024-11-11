#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 100002;
int n;
vector<int> edges[N_MAX];
int red[N_MAX], blue[N_MAX];
int answer;
void dfs(int node, int parent = -1) {
  red[node] = 0;
  blue[node] = 0;
  for (int u : edges[node])
    if (u != parent) {
      dfs(u, node);
      red[node] = max(red[node], max(red[u], blue[u]));
      blue[node] = max(blue[node], red[u]);
    }
  red[node] += max(0, (int)edges[node].size() - 2);
  blue[node] += 1;
  int max1 = 0, max2 = 0;
  int maxRed1 = 0, maxRed2 = 0;
  for (int u : edges[node])
    if (u != parent) {
      int val = max(red[u], blue[u]);
      if (val >= max1) {
        max2 = max1;
        max1 = val;
      } else if (val > max2)
        max2 = val;
      if (red[u] >= maxRed1) {
        maxRed2 = maxRed1;
        maxRed1 = red[u];
      } else if (red[u] > maxRed2)
        maxRed2 = red[u];
    }
  answer = max(answer, max1 + max2 + max(0, (int)edges[node].size() - 2));
  answer = max(answer, maxRed1 + maxRed2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1);
  cout << answer << "\n";
  return 0;
}
