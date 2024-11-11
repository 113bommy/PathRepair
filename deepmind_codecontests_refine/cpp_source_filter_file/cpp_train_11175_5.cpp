#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1505;
constexpr int INF = 0x3f3f3f3f;
int n, m;
pair<int, int> seen[N][N];
string s[N];
void dfs(int x, int y) {
  int nx = (x + n + n) % n;
  int ny = (y + m + m) % m;
  if (s[nx][ny] == '#') return;
  if (seen[nx][ny] == make_pair(x, y)) return;
  if (seen[nx][ny] != make_pair(INF, INF)) {
    cout << "Yes\n";
    exit(0);
  }
  seen[nx][ny] = make_pair(x, y);
  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) seen[i][j] = make_pair(INF, INF);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  int sx = 0, sy = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'S') {
        sx = i, sy = j;
      }
    }
  }
  dfs(sx, sy);
  cout << "No\n";
}
