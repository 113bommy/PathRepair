#include <bits/stdc++.h>
using namespace std;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
vector<string> mat;
vector<vector<int>> D;
int n, m;
int id = 0;
int dfs(int x, int y) {
  D[x][y] = id;
  int suma = 1;
  for (int h = 0; h < 4; h++) {
    int dx = x + dr[h], dy = y + dc[h];
    if (0 <= dx and dx < n and 0 <= dy and dy < m and D[dx][dy] == -1 and
        mat[dx][dy] == '.') {
      suma += dfs(dx, dy);
    }
  }
  return suma;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  D.assign(n, vector<int>(m, -1));
  mat.resize(n);
  for (int i = 0; i < n; i++) cin >> mat[i];
  vector<int> cont;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (D[i][j] == -1 and mat[i][j] == '.') {
        cont.push_back(dfs(i, j));
        id++;
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mat[i][j] == '*') {
        int suma = 0;
        set<int> S;
        for (int h = 0; h < 4; h++) {
          int dx = i + dr[h], dy = j + dc[h];
          if (0 <= dx and dx < n and 0 <= dy and dy < m and
              mat[dx][dy] == '.') {
            S.insert(D[dx][dy]);
          }
        }
        for (auto& s : S) suma += cont[s];
        mat[i][j] = char((suma + 1) % 10 + '0');
      }
  for (int i = 0; i < n; i++) cout << mat[i] << '\n';
  return 0;
}
