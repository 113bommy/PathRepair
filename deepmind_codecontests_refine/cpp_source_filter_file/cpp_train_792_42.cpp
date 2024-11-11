#include <bits/stdc++.h>
using namespace std;
bool v[101][101];
void wait() {
  getchar();
  getchar();
}
string grid[101];
int main() {
  int n, m;
  int cnt = 0;
  cin >> n >> m;
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++) v[i][j] = 1;
  for (int i = 0; i < n; i++) cin >> grid[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 0) continue;
      char c = grid[i][j];
      bool f = 0;
      for (int k = j + 1; k < m; k++) {
        if (grid[i][k] == c) {
          f = 1;
          v[i][k] = 0;
        }
      }
      if (f) v[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char c = grid[j][i];
      bool f = 0;
      for (int k = j + 1; k < n; k++) {
        if (grid[k][i] == c) {
          f = 1;
          v[k][i] = 0;
        }
      }
      if (f) v[j][i] = 0;
    }
  }
  string ans;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j]) cout << grid[i][j];
    }
  }
  wait();
}
