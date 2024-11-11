#include <bits/stdc++.h>
using namespace std;
int nxt[504][10], dp[504][504][11], freq[504];
int n, k, cnt;
void insert(string s, int frq) {
  int x = 0;
  for (char c : s) {
    if (!nxt[x][c - '0']) nxt[x][c - '0'] = ++cnt;
    x = nxt[x][c - '0'];
  }
  freq[x] += frq;
}
bool Min(int &a, int b) { return a > b ? (a = b, 1) : 0; }
void dfs(int x, int dep) {
  for (int i = (0); i <= (dep); i++)
    for (int j = (0); j <= (k); j++) dp[x][i][j] = i * freq[x];
  for (int p = (0); p <= (9); p++)
    if (nxt[x][p]) {
      int y = nxt[x][p];
      dfs(y, dep + 1);
      for (int i = (0); i <= (dep); i++)
        for (int j = (k); j >= (0); j--) {
          dp[x][i][j] += dp[y][i + 1][0];
          for (int q = (0); q <= (j - 1); q++)
            Min(dp[x][i][j], dp[x][i][q] + dp[y][i + 1][j - q]);
        }
    }
  for (int i = (0); i <= (dep); i++)
    for (int j = (1); j <= (k); j++) Min(dp[x][i][j], dp[x][0][j - 1]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  string s;
  int frq;
  for (int i = (1); i <= (n); i++) cin >> s >> frq, insert(s, frq);
  dfs(0, 0);
  cout << dp[0][0][k] << endl;
  return 0;
}
