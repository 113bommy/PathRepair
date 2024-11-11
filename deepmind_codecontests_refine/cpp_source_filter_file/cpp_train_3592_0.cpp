#include <bits/stdc++.h>
using namespace std;
vector<string> G;
int n, m;
vector<vector<vector<int> > > D(3);
void findC(int bF) {
  queue<pair<int, int> > Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (G[i][j] == bF + '1') Q.push(make_pair(i, j));
    }
  }
  Q.push(make_pair(-1, -1));
  vector<vector<bool> > B(n, vector<bool>(m, false));
  int t = 0;
  while (Q.size() > 1) {
    pair<int, int> p = Q.front();
    Q.pop();
    if (p.first == -1) {
      t++;
      Q.push(make_pair(-1, -1));
      continue;
    }
    if (B[p.first][p.second]) continue;
    B[p.first][p.second] = 1;
    if (G[p.first][p.second] == '#') continue;
    D[bF][p.first][p.second] = t;
    if (p.first - 1 >= 0) Q.push(make_pair(p.first - 1, p.second));
    if (p.first + 1 < n) Q.push(make_pair(p.first + 1, p.second));
    if (p.second - 1 >= 0) Q.push(make_pair(p.first, p.second - 1));
    if (p.second + 1 < m) Q.push(make_pair(p.first, p.second + 1));
  }
}
int main() {
  cin >> n >> m;
  G.resize(n);
  for (int i = 0; i < 3; i++) {
    D[i].resize(n, vector<int>(m, (1 << 29)));
  }
  for (int i = 0; i < n; i++) {
    cin >> G[i];
  }
  findC(0);
  findC(1);
  findC(2);
  int DD[3][3];
  for (int p = 0; p < 3; p++) {
    for (int q = 0; q < 3; q++) {
      if (p == q) continue;
      DD[p][q] = (1 << 29);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (G[i][j] == '1' + q) {
            if (D[p][i][j] - 1 < DD[p][q]) DD[p][q] = D[p][i][j] - 1;
          }
        }
      }
    }
  }
  int r = (1 << 29);
  r = min(DD[0][1] + DD[0][2], r);
  r = min(DD[0][1] + DD[1][2], r);
  r = min(DD[1][2] + DD[0][2], r);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      r = min(r, D[0][i][j] + D[1][i][j] + D[2][i][j] - 2);
    }
  }
  if (r >= (1 << 29))
    cout << "-1\n";
  else
    cout << r << "\n";
  return 0;
}
