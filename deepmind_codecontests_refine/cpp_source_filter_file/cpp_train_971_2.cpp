#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 500;
bool Grid[2][N];
int dist[2][N];
queue<pair<bool, int> > q;
string L, R;
int n, k;
int main() {
  cin >> n >> k;
  cin >> L >> R;
  for (int i = 0; i <= n + k; i++) {
    if (i < n) {
      Grid[0][i] = (L[i] == 'X');
      Grid[1][i] = (R[i] == 'X');
    }
    dist[0][i] = dist[1][i] = 1e9;
  }
  dist[0][0] = 0;
  q.push({0, 0});
  int water = 0;
  while (!q.empty()) {
    pair<bool, int> u = q.front();
    q.pop();
    water = dist[u.first][u.second];
    if (u.second - 1 >= 0 && u.second - 1 >= water) {
      if (!Grid[u.first][u.second - 1] && dist[u.first][u.second - 1] == 1e9) {
        dist[u.first][u.second - 1] = dist[u.first][u.second] + 1;
        q.push({u.first, u.second - 1});
      }
    }
    if (u.second + 1 >= 0) {
      if (!Grid[u.first][u.second + 1] && dist[u.first][u.second + 1] == 1e9) {
        dist[u.first][u.second + 1] = dist[u.first][u.second] + 1;
        q.push({u.first, u.second + 1});
      }
    }
    if (u.second + k >= 0) {
      if (u.second + k >= n) {
        cout << "YES" << endl;
        exit(0);
      }
      if (!Grid[!u.first][u.second + k] &&
          dist[!u.first][u.second + k] == 1e9) {
        dist[!u.first][u.second + k] = dist[u.first][u.second] + 1;
        q.push({!u.first, u.second + k});
      }
    }
    water++;
    if (u.second >= n) break;
  }
  bool flag = false;
  for (int i = n - 1; i <= n + k; i++) {
    if (dist[0][i] != 1e9 || dist[1][i] != 1e9) {
      flag = true;
      break;
    }
  }
  flag ? puts("YES") : puts("NO");
  return 0;
}
