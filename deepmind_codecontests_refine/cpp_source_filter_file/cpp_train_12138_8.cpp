#include <bits/stdc++.h>
using namespace std;
int inf_int = 1e9;
long long inf_ll = 1e16;
const double pi = 3.1415926535898;
const int mod = 1e9 + 9;
const int MAXN = 2e5 + 100;
bool debug = false;
char a[1005][1005];
char used[1005][1005][4][3];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
inline bool is_ok(int x, int y, int d, int z) {
  return x >= 1 && x <= n && y >= 1 && y <= n && z <= 2 && a[x][y] != '*' &&
         !used[x][y][d][z];
}
void solve() {
  cin >> n >> m;
  int x1, y1;
  for (int i = 1; i <= n; ++i) {
    for (int e = 1; e <= m; ++e) {
      cin >> a[i][e];
      if (a[i][e] == 'S') {
        x1 = i;
        y1 = e;
      }
    }
  }
  queue<pair<pair<int, int>, pair<int, int> > > q;
  used[x1][y1][0][0] = 1;
  used[x1][y1][1][0] = 1;
  used[x1][y1][2][0] = 1;
  used[x1][y1][3][0] = 1;
  q.push({{x1, y1}, {0, 0}});
  q.push({{x1, y1}, {1, 0}});
  q.push({{x1, y1}, {2, 0}});
  q.push({{x1, y1}, {3, 0}});
  while (!q.empty()) {
    int x = q.front().first.first, y = q.front().first.second;
    int d = q.front().second.first, z = q.front().second.second;
    q.pop();
    if (is_ok(x + dx[d], y + dy[d], d, z)) {
      q.push({{x + dx[d], y + dy[d]}, {d, z}});
      used[x + dx[d]][y + dy[d]][d][z] = 1;
    }
    for (int i = 0; i < 4; ++i) {
      if (is_ok(x + dx[i], y + dy[i], i, z + 1)) {
        q.push({{x + dx[i], y + dy[i]}, {i, z + 1}});
        used[x + dx[i]][y + dy[i]][i][z + 1] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int e = 1; e <= m; ++e) {
      if (a[i][e] == 'T') {
        for (int j = 0; j < 4; ++j) {
          for (int f = 0; f <= 2; ++f) {
            if (used[i][e][j][f]) {
              cout << "YES";
              return;
            }
          }
        }
      }
    }
  }
  cout << "NO";
}
int main() {
  if (!debug) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t = 1;
  while (t--) solve();
  return 0;
}
