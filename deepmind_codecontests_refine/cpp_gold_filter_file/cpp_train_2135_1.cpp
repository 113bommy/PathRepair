#include <bits/stdc++.h>
using namespace std;
string s[3];
int n, x, dp[169][169];
int yo(int r, int c) {
  if (c >= n) return 1;
  if (dp[r][c] != -1) return dp[r][c];
  if (s[r][c + 1] != '.') return dp[r][c] = 0;
  int ans = 0;
  if (r && s[r - 1][c + 1] == '.' && s[r - 1][c + 2] == '.' &&
      s[r - 1][c + 3] == '.')
    ans |= yo(r - 1, c + 3);
  if (r != 2 && s[r + 1][c + 1] == '.' && s[r + 1][c + 2] == '.' &&
      s[r + 1][c + 3] == '.')
    ans |= yo(r + 1, c + 3);
  if (s[r][c + 3] == '.' && s[r][c + 2] == '.') ans |= yo(r, c + 3);
  return dp[r][c] = ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n), scanf("%d", &x);
    for (int i = 0; i < 50; i++)
      for (int j = 0; j < 150; j++) dp[i][j] = -1;
    int sr = 0;
    cin >> s[0] >> s[1] >> s[2];
    s[0] += ".......";
    s[1] += ".......";
    s[2] += ".......";
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < n; j++)
        if (s[i][j] == 's') sr = i;
    if (yo(sr, 0))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
