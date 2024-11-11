#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 1e5 + 5;
const long long MOD = 1000000007;
const long long MOD2 = 2010405347;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
int n, nr, nc;
bool vis[10][10][50];
char x[10][10];
inline bool cek(int r, int c) {
  if (r < 1) return 1;
  return x[r][c] != 'S';
}
void dfs(int r, int c, int t) {
  if (r == 1 && c == 8) {
    cout << "WIN\n";
    exit(0);
  }
  if (t > 45) return;
  vis[r][c][t] = 1;
  int nr, nc;
  for (int i = 0; i <= 8; ++i) {
    nr = r + dr[i], nc = c + dc[i];
    if (nr > 0 && nc > 0 && nr < 9 && nc < 9 && !vis[nr][nc][t + 1] &&
        cek(nr - t, nc) && cek(nr - t - 1, nc)) {
      dfs(nr, nc, t + 1);
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i <= 8; ++i)
    for (int j = 1; j <= 8; ++j) cin >> x[i][j];
  dfs(8, 1, 0);
  cout << "LOSE\n";
  return 0;
}
