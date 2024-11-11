#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[]{0, -1, 0, 1};
int dy[]{-1, 0, 1, 0};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<int>> g(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X') {
        vector<int> A;
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.') {
            A.push_back(x * m + y);
          }
        }
        if (A.size() % 2 != 0) {
          cout << "NO\n";
          return 0;
        }
        for (int k = 0; k < A.size(); k += 2) {
          g[A[k]].push_back(A[k + 1]);
          g[A[k + 1]].push_back(A[k]);
        }
      }
    }
  }
  vector<vector<int>> e(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X' || e[i][j]) {
        continue;
      }
      e[i][j] = 1;
      queue<int> q;
      q.push(i * m + j);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
          if (!e[v / m][v % m]) {
            e[v / m][v % m] = e[u / m][u % m] ^ 5;
            q.push(v);
          }
        }
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'X') {
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.') {
            e[i][j] += e[x][y];
          }
        }
      }
      cout << e[i][j] << " \n"[j == m - 1];
    }
  }
  return 0;
}
