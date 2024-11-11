#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 322;
const long long INF = 1e18;
char mat[maxN][maxN];
bool vis[maxN][maxN];
int n, m, t;
bool isValid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> t;
  long long change[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      change[i][j] = INF;
      cin >> mat[i][j];
    }
  }
  int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  queue<pair<long long, pair<long long, long long> > > pq;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (isValid(x, y) && !vis[i][j] && mat[i][j] == mat[x][y]) {
          vis[i][j] = true;
          pq.push({1, {i, j}});
        }
      }
    }
  }
  while (!pq.empty()) {
    int c = pq.front().first;
    int x = pq.front().second.first;
    int y = pq.front().second.second;
    pq.pop();
    change[x][y] = min(change[x][y], (long long)c);
    for (int i = 0; i < 4; i++) {
      int new_x = x + dir[i][0];
      int ney_y = y + dir[i][1];
      if (isValid(new_x, ney_y) && !vis[new_x][ney_y] &&
          mat[x][y] != mat[new_x][ney_y]) {
        vis[new_x][ney_y] = true;
        pq.push({c + 1, {new_x, ney_y}});
      }
    }
  }
  for (int i = 0; i < t; i++) {
    long long x, y, p;
    cin >> x >> y >> p;
    --x;
    --y;
    if (p < change[x][y]) {
      cout << mat[x][y] << endl;
    } else {
      long long dis = (p - change[x][y]) % 2;
      if (dis == 1) {
        cout << mat[x][y] << endl;
      } else {
        cout << (mat[x][y] == '1' ? '0' : '1') << endl;
      }
    }
  }
  return 0;
}
