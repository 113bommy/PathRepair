#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int n, m, k, s1, s2;
char graph[1005][1005];
int step[1005][1005];
int row[4] = {1, 0, 0, -1};
int col[4] = {0, -1, 1, 0};
int flag = 0;
char s[4] = {'D', 'L', 'R', 'U'};
void bfs(int s1, int s2) {
  queue<pair<int, int> > q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) step[i][j] = INF;
  q.push({s1, s2});
  step[s1][s2] = 0;
  while (!q.empty()) {
    int u = q.front().first;
    int v = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = row[i] + u;
      int y = col[i] + v;
      if (graph[x][y] == '*' || x >= n || x < 0 || y >= m || y < 0) continue;
      if (step[x][y] > step[u][v] + 1) {
        step[x][y] = step[u][v] + 1;
        q.push({x, y});
      }
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> graph[i][j];
      if (graph[i][j] == 'X') {
        s1 = i;
        s2 = j;
      }
    }
  if (k % 2 != 0) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  bfs(s1, s2);
  string ans = "";
  for (int i = 0; i < k; i++) {
    int pos = 0;
    while (pos < 4) {
      int x = row[pos] + s1;
      int y = col[pos] + s2;
      if (graph[x][y] != '*' && x < n && x >= 0 && y < m && y >= 0 &&
          step[x][y] <= k - 1 - i) {
        break;
      }
      ++pos;
    }
    if (pos == 4) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    s1 += row[pos];
    s2 += col[pos];
    ans += s[pos];
  }
  cout << ans;
}
