#include <bits/stdc++.h>
using namespace std;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
void util(int i, int j, vector<string> &str, vector<vector<int>> &visited,
          int &l) {
  int n = str.size();
  int m = str[0].size();
  if (i == n || j == m) return;
  visited[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int newX = i + x[k];
    int newY = j + y[k];
    if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
        !visited[newX][newY] && str[newX][newY] == '.') {
      util(newX, newY, str, visited, l);
    }
  }
  if (l > 0) {
    str[i][j] = 'X';
    l--;
  }
  return;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> str(n);
  for (int i = 0; i < n; i++) cin >> str[i];
  vector<vector<int>> visited(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (str[i][j] == '.' && !visited[i][j]) {
        util(i, j, str, visited, k);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << str[i] << endl;
  }
  return 0;
}
