#include <bits/stdc++.h>
using namespace std;
int dx8[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int X[6] = {0, 0, 0, -1, 0, 1};
int Y[6] = {0, 0, -1, 0, 1, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
char g[111][111];
bool f[111][111];
int n, cnt = 0;
bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!f[i][j] && g[i][j] == '#') {
        int c = 1;
        for (int k = 0; k < 4; k++) {
          if (valid(i + dx[k], j + dy[k]) && g[i + dx[k]][j + dy[k]] &&
              !f[i + dx[k]][j + dy[k]])
            c++;
        }
        if (c == 5) {
          f[i][j] = 1;
          for (int k = 0; k < 4; k++) {
            f[i + dx[k]][j + dy[k]] = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == '#' && !f[i][j]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
}
