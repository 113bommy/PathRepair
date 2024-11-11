#include <bits/stdc++.h>
using namespace std;
const int N = 50, M = 50;
char cc[N][M + 1];
int n, m, k_;
void dfs(int i, int j, char c) {
  if (i < 0 || i >= n || j < 0 || j >= m || cc[i][j] != c) return;
  cc[i][j] ^= 1;
  k_++;
  dfs(i - 1, j, c);
  dfs(i + 1, j, c);
  dfs(i, j - 1, c);
  dfs(i, j + 1, c);
}
int main() {
  cin >> n >> m;
  int k = 0;
  int i1 = -1, j1 = -1, i2 = -1, j2 = -1;
  for (int i = 0; i < n; i++) {
    cin >> cc[i];
    for (int j = 0; j < m; j++)
      if (cc[i][j] == '#') {
        k++;
        if (i1 == -1)
          i1 = i, j1 = j;
        else if (i2 == -1)
          i2 = i, j2 = j;
      }
  }
  if (k <= 2) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (cc[i][j] == '#') {
        cc[i][j] = '.';
        int i_ = i1, j_ = j1;
        if (i == i_ && j == j_) i_ = i2, j_ = j2;
        k_ = 0;
        dfs(i_, j_, cc[i_][j_]);
        if (k_ < k - 1) {
          cout << "1\n";
          return 0;
        }
        dfs(i_, j_, cc[i_][j_]);
        cc[i][j] = '#';
      }
  cout << "2\n";
  return 0;
}
