#include <bits/stdc++.h>
using namespace std;
int g_maxLength;
int dfs(vector<int> v[], bool visited[], int s, int Bob, int da) {
  int maxDepth = 0;
  int secondMaxDepth = 0;
  for (int i = 0; i < v[s].size(); i++) {
    if (v[s][i] == Bob && da >= 0) g_maxLength = 1000000;
    if (!visited[v[s][i]]) {
      visited[v[s][i]] = true;
      int depth = dfs(v, visited, v[s][i], Bob, da - 1);
      visited[v[s][i]] = false;
      if (depth > maxDepth) swap(depth, maxDepth);
      if (depth > secondMaxDepth) secondMaxDepth = depth;
    }
  }
  if (maxDepth + secondMaxDepth + 1 > g_maxLength)
    g_maxLength = maxDepth + secondMaxDepth + 1;
  return (maxDepth + 1);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<int> v[n];
    bool visited[n];
    g_maxLength = 0;
    visited[0] = false;
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      v[x - 1].push_back(y - 1);
      v[y - 1].push_back(x - 1);
      visited[i + 1] = false;
    }
    visited[a - 1] = true;
    dfs(v, visited, a - 1, b - 1, da * 2 - 1);
    if (da - db >= -1 || g_maxLength == 1000000 || da >= g_maxLength / 2)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
}
