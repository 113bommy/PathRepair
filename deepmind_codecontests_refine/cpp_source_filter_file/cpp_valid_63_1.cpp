#include <bits/stdc++.h>
using namespace std;
int findParent(int v, int* arr) {
  if (arr[v] == v) return v;
  return arr[v] = findParent(arr[v], arr);
}
int main() {
  int n;
  cin >> n;
  int g1[n + 1][n + 1], g2[n + 1][n + 1];
  int p1[n + 1], p2[n + 1];
  for (int i = 0; i <= n; i++) {
    p1[i] = i;
    p2[i] = i;
  }
  memset(g1, 0, sizeof(g1));
  memset(g2, 0, sizeof(g2));
  int e1, e2;
  cin >> e1 >> e2;
  for (int i = 0; i < e1; i++) {
    int u, v;
    cin >> u >> v;
    g1[u][v] = 1;
    g1[v][u] = 1;
    p1[u] = p1[v];
  }
  for (int i = 0; i < e2; i++) {
    int u, v;
    cin >> u >> v;
    g2[u][v] = 1;
    g2[v][u] = 1;
    p2[u] = p2[v];
  }
  vector<pair<int, int>> inc;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (g1[i][j] == 0 && g2[i][j] == 0) {
        int a1, a2, b1, b2;
        a1 = findParent(i, p1);
        a2 = findParent(j, p1);
        b1 = findParent(i, p2);
        b2 = findParent(j, p2);
        if (a1 != a2 && b1 != b2) {
          p1[a1] = a2;
          p2[b1] = b2;
          inc.push_back({i, j});
          g1[i][j] = 1;
          g1[j][i] = 1;
          g2[i][j] = 1;
          g2[j][i] = 1;
        }
      }
    }
  }
  cout << inc.size() << "\n";
  for (int i = 0; i < inc.size(); i++)
    cout << inc[i].first << " " << inc[i].second << "\n";
}
