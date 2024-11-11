#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<vector<int> > grau(n, vector<int>(m));
  queue<int> q;
  int buides = 0;
  int xs[] = {0, 0, 1, -1};
  int ys[] = {1, -1, 0, 0};
  bool possible = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '*')
        grau[i][j] = -1;
      else {
        ++buides;
        int cont = 0;
        for (int k = 0; k < 4; k++) {
          int nx = i + xs[k], ny = j + ys[k];
          if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '.')
            ++cont;
        }
        grau[i][j] = cont;
        if (cont == 0) possible = false;
        if (cont == 1) q.push(i * m + j);
      }
    }
  }
  while (possible && !q.empty()) {
    int x = q.front() / m, y = q.front() % m;
    q.pop();
    bool found = true;
    for (int k = 0; k < 4; k++) {
      int nx = x + xs[k], ny = y + ys[k];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '.') {
        if (k == 0) {
          v[nx][ny] = '<';
          v[x][y] = '>';
        }
        if (k == 1) {
          v[nx][ny] = '>';
          v[x][y] = '<';
        }
        if (k == 2) {
          v[nx][ny] = '^';
          v[x][y] = 'v';
        }
        if (k == 3) {
          v[nx][ny] = 'v';
          v[x][y] = '^';
        }
        found = true;
        buides -= 2;
        for (int kk = 0; kk < 4; kk++) {
          int nnx = nx + xs[kk], nny = ny + ys[kk];
          if (nnx >= 0 && nnx < n && nny >= 0 && nny < m &&
              v[nnx][nny] == '.') {
            grau[nnx][nny]--;
            if (grau[nnx][nny] == 0) possible = false;
            if (grau[nnx][nny] == 1) q.push(nnx * m + nny);
          }
        }
        break;
      }
    }
    if (!found) possible = false;
  }
  if (possible && buides == 0) {
    for (int i = 0; i < n; i++) cout << v[i] << endl;
  } else
    cout << "Not unique" << endl;
}
