#include <bits/stdc++.h>
using namespace std;
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
template <typename T>
inline T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
inline void amin(T& x, T y) {
  if (x > y) x = y;
}
template <typename T>
inline void amax(T& x, T y) {
  if (x < y) x = y;
}
int n, m;
char s[1005][1005];
vector<vector<int> > dist[3];
queue<pair<int, int> > q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void preprocess(void) { return; }
void BFS(int k) {
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = (0); i <= ((int)(4) - 1); i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ny >= 0 && ny < m && nx >= 0 && nx < n) {
        if (s[nx][ny] == '#' || dist[k][nx][ny] >= 0) {
          continue;
        }
        dist[k][nx][ny] = 1 + dist[k][x][y];
        q.push({nx, ny});
      }
    }
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  preprocess();
  int t;
  t = 1;
  for (int ze = (1); ze <= (t); ze++) {
    cin >> n >> m;
    for (int i = (0); i <= ((int)(3) - 1); i++) {
      dist[i].assign(n, vector<int>(m, -1));
    }
    for (int i = (0); i <= ((int)(n)-1); i++) {
      cin >> s[i];
    }
    for (int k = (0); k <= ((int)(3) - 1); k++) {
      for (int i = (0); i <= ((int)(n)-1); i++) {
        for (int j = (0); j <= ((int)(m)-1); j++) {
          if (s[i][j] == k + '1') {
            dist[k][i][j] = 0;
            q.push({i, j});
          }
        }
      }
      BFS(k);
    }
    int ans = 1000000007;
    for (int i = (0); i <= ((int)(n)-1); i++) {
      for (int j = (0); j <= ((int)(m)-1); j++) {
        if (s[i][j] == '.' && dist[0][i][j] >= 0 && dist[1][i][j] >= 0 &&
            dist[2][i][j] >= 0) {
          int tans = -2;
          for (int k = (0); k <= ((int)(3) - 1); k++) {
            tans += dist[k][i][j];
          }
          amin(ans, tans);
        }
      }
    }
    int x = 0, y = 1, z = 2;
    for (int te = (0); te <= ((int)(3) - 1); te++) {
      int tans1 = 1000000007, tans2 = 1000000007;
      for (int i = (0); i <= ((int)(n)-1); i++) {
        for (int j = (0); j <= ((int)(m)-1); j++) {
          if (s[i][j] == '1' + y && dist[x][i][j] >= 0) {
            amin(tans1, dist[x][i][j]);
          } else if (s[i][j] == '1' + z && dist[x][i][j] >= 0) {
            amin(tans2, dist[x][i][j]);
          }
        }
      }
      amin(ans, tans1 + tans2 - 2);
      int tmp = x;
      x = y;
      y = z;
      z = tmp;
    }
    if (ans >= 1000000007) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
