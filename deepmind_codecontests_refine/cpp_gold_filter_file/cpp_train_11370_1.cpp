#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
char s[100][100];
int n, m;
int check() {
  int tag = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'P') tag = 0;
    }
  if (tag) return 0;
  tag = 1;
  for (int j = 1; j <= m; j++)
    if (s[1][j] == 'P') tag = 0;
  if (tag) return 1;
  tag = 1;
  for (int j = 1; j <= m; j++)
    if (s[n][j] == 'P') tag = 0;
  if (tag) return 1;
  tag = 1;
  for (int j = 1; j <= n; j++)
    if (s[j][1] == 'P') tag = 0;
  if (tag) return 1;
  tag = 1;
  for (int j = 1; j <= n; j++)
    if (s[j][m] == 'P') tag = 0;
  if (tag) return 1;
  int L = 0, R = 0, len = 0;
  for (int j = 1; j <= m; j++)
    if (s[1][j] == 'A' && len == j - 1) len++;
  L = max(L, len);
  len = 0;
  for (int j = 1; j <= m; j++)
    if (s[n][j] == 'A' && len == j - 1) len++;
  L = max(L, len);
  len = 0;
  for (int j = m; j >= 1; j--)
    if (s[1][j] == 'A' && len == m - j) len++;
  R = max(R, len);
  len = 0;
  for (int j = m; j >= 1; j--)
    if (s[n][j] == 'A' && len == m - j) len++;
  R = max(R, len);
  len = 0;
  if (L + R >= m) return 2;
  L = R = 0;
  for (int j = 1; j <= n; j++)
    if (s[j][1] == 'A' && len == j - 1) len++;
  L = max(L, len);
  len = 0;
  for (int j = 1; j <= n; j++)
    if (s[j][m] == 'A' && len == j - 1) len++;
  L = max(L, len);
  len = 0;
  for (int j = n; j >= 1; j--)
    if (s[j][1] == 'A' && len == n - j) len++;
  R = max(R, len);
  len = 0;
  for (int j = n; j >= 1; j--)
    if (s[j][m] == 'A' && len == n - j) len++;
  R = max(R, len);
  if (L + R >= n) return 2;
  if (s[1][1] == 'A' || s[n][m] == 'A' || s[1][m] == 'A' || s[n][1] == 'A')
    return 2;
  for (int i = 1; i <= n; i++) {
    int tot = 0;
    for (int j = 1; j <= m; j++) tot += s[i][j] == 'A';
    if (tot == m) return 2;
  }
  for (int i = 1; i <= m; i++) {
    int tot = 0;
    for (int j = 1; j <= n; j++) tot += s[j][i] == 'A';
    if (tot == n) return 2;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if ((i == 1 || j == 1) && s[i][j] == 'A') return 3;
      if ((i == n || j == m) && s[i][j] == 'A') return 3;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'A') return 4;
    }
  return -1;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    int ans = check();
    if (ans != -1)
      cout << ans << endl;
    else
      puts("MORTAL");
  }
  return 0;
}
