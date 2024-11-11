#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char board[N][N];
int vst[N][N];
bool vst2[N][N];
bool cicle = 0;
int cnt = 0;
int fx[] = {1, 0, -1, 0};
int fy[] = {0, -1, 0, 1};
int n, m;
int dp[N][N];
inline int num(char c) {
  if (c == 'D') return 0;
  if (c == 'I') return 1;
  if (c == 'M') return 2;
  return 3;
}
inline int dfs(int i, int j) {
  vst[i][j] = cnt;
  vst2[i][j] = true;
  int val = (board[i][j] == 'A');
  for (int c = int(0); c < int(4); ++c) {
    int yy = i + fy[c];
    int xx = j + fx[c];
    if (xx < 0 || xx >= m) continue;
    if (yy < 0 || yy >= n) continue;
    int id1 = num(board[i][j]);
    int id2 = num(board[yy][xx]);
    if ((id2 - id1 + 4) % 4 == 1) {
      if (vst[yy][xx] == -1)
        val = max(val, (board[i][j] == 'A') + dfs(yy, xx));
      else
        val = max(val, dp[yy][xx] + (board[i][j] == 'A'));
      if (vst2[yy][xx]) cicle = true;
    }
  }
  vst2[i][j] = false;
  return dp[i][j] = val;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = int(0); i < int(n); ++i)
    for (int j = int(0); j < int(m); ++j) cin >> board[i][j];
  memset(vst, -1, sizeof(vst));
  int ans = 0;
  for (int i = int(0); i < int(n); ++i)
    for (int j = int(0); j < int(n); ++j)
      if (vst[i][j] == -1 && board[i][j] == 'D')
        ans = max(dfs(i, j), ans), cnt++;
  if (cicle)
    cout << "Poor Inna!" << endl;
  else if (ans == 0)
    cout << "Poor Dima!" << endl;
  else
    cout << ans << endl;
  return 0;
}
