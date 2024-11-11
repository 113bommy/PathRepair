#include <bits/stdc++.h>
using namespace std;
const int N = 1324;
char a[N][N];
int dp[N][N][5];
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, 1, 0, -1};
string w1 = "0^>v<";
string w2 = "1URDL";
bool funk(int x, char t) {
  if (w1[((x + 4 - 1) % 4 + 1)] == t) return 1;
  if (w2.find(t) < 10 && w2[(x + 4 - 1) % 4 + 1] != t) return 1;
  if (t == '+') return 1;
  if (t == '-') {
    if (x % 2 == 0) return 1;
  }
  if (t == '|') {
    if (x % 2 != 0) return 1;
  }
  return 0;
}
bool funk1(int x, char t) {
  if (t == '+') return 1;
  if (t == '-') {
    if (x % 2 == 0) return 1;
  }
  if (t == '|') {
    if (x % 2 != 0) return 1;
  }
  if (w1[((x + 4 + 2 - 1) % 4 + 1)] == t) return 1;
  if (w2.find(t) < 10 && w2[(x + 4 + 2 - 1) % 4 + 1] != t) return 1;
  return 0;
}
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      for (int k = 1; k <= 4; k++) {
        dp[i][j][k] = 1e9;
      }
    }
  }
  int x, y;
  cin >> x >> y;
  dp[x][y][1] = 0;
  queue<pair<int, pair<int, int> > > q;
  q.push(make_pair(1, make_pair(x, y)));
  while (!q.empty()) {
    int x = q.front().second.first;
    int y = q.front().second.second;
    int t = q.front().first;
    q.pop();
    for (int i = 1; i <= 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m &&
          funk(i - t + 1, a[x][y]) && a[xx][yy] != '*' &&
          funk1(i - t + 1, a[xx][yy])) {
        if (dp[xx][yy][t] == 1e9) {
          q.push(make_pair(t, make_pair(xx, yy)));
          dp[xx][yy][t] = dp[x][y][t] + 1;
        }
      }
    }
    int w = t + 1;
    if (w == 5) w = 1;
    if (dp[x][y][w] == 1e9) {
      q.push(make_pair(w, make_pair(x, y)));
      dp[x][y][w] = dp[x][y][t] + 1;
    }
  }
  cin >> x >> y;
  int ans = 1e9;
  for (i = 1; i <= 4; i++) ans = min(ans, dp[x][y][i]);
  if (ans == 1e9) ans = -1;
  cout << ans;
}
