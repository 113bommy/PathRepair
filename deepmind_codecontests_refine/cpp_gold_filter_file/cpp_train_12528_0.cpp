#include <bits/stdc++.h>
using namespace std;
template <typename T>
T inline SQR(const T &a) {
  return a * a;
}
int nc, root, rootC;
vector<int> num, low, parent, art;
vector<int> grafo[3333];
void artPtAndBridge(int u) {
  low[u] = num[u] = nc++;
  for (int j = 0; j < (int)grafo[u].size(); ++j) {
    int v = grafo[u][j];
    if (num[v] == -1) {
      parent[v] = u;
      if (u == root) {
        rootC++;
      }
      artPtAndBridge(v);
      if (low[v] >= num[u]) {
        art[u] = true;
      }
      if (low[v] > num[u]) {
      }
      low[u] = min(low[u], low[v]);
    } else if (v != parent[u]) {
      low[u] = min(low[u], num[v]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  char mat[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }
  int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  int nav = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '#') {
        nav++;
        for (int k = 0; k < 4; ++k) {
          int x = i + dir[k][0], y = j + dir[k][1];
          if ((x >= 0 && x < n && y >= 0 && y < m) && mat[x][y] == '#') {
            grafo[i * m + j].push_back(x * m + y);
          }
        }
      }
    }
  }
  if (nav == 1 || nav == 2) {
    cout << -1 << '\n';
    return 0;
  }
  int numV = n * m;
  nc = 0;
  num.assign(numV, -1);
  low.assign(numV, 0);
  parent.assign(numV, 0);
  art.assign(numV, false);
  for (int i = 0; i < numV; ++i) {
    if (num[i] == -1) {
      root = i;
      rootC = 0;
      artPtAndBridge(i);
      art[root] = (rootC > 1);
    }
  }
  int cnt = 0;
  for (int i = 0; i < numV; ++i) {
    if (art[i]) {
      cnt++;
      break;
    }
  }
  if (cnt) {
    cout << 1 << '\n';
  } else {
    cout << 2 << '\n';
  }
  return 0;
}
