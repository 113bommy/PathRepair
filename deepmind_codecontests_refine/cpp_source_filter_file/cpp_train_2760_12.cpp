#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005], vis1[1005][1005];
char s[1005][1005];
long long int c1[1005][1005], count1 = 0, n, m;
map<long long int, long long int> m1;
void dfs(long long int r, long long int c, long long int color) {
  if (vis[r][c]) return;
  vis[r][c] = true;
  c1[r][c] = color;
  m1[color]++;
  if ((r - 1) >= 0 && s[r - 1][c] != '*') {
    dfs((r - 1), c, color);
  }
  if ((r + 1) < n && s[r + 1][c] != '*') {
    dfs((r + 1), c, color);
  }
  if ((c - 1) >= 0 && s[r][c - 1] != '*') {
    dfs(r, (c - 1), color);
  }
  if ((c + 1) < m && s[r][c + 1] != '*') {
    dfs(r, (c + 1), color);
  }
}
int main() {
  long long int i, j, k, l, c2 = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) cin >> s[i][j];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (!vis[i][j] && s[i][j] != '*') {
        c2++;
        dfs(i, j, c2);
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        long long int count2 = 0;
        map<long long int, bool> take;
        if ((i - 1) >= 0 && s[i - 1][j] != '*' && !take[c1[i - 1][j]]) {
          count2 = (count2 + m1[c1[i - 1][j]]) % 10;
          take[c1[i - 1][j]] = true;
        }
        if ((i + 1) < n && s[i + 1][j] != '*' && !take[c1[i + 1][j]]) {
          count2 = (count2 + m1[c1[i + 1][j]]) % 10;
          take[c1[i + 1][j]] = true;
        }
        if ((j - 1) >= 0 && s[i][j - 1] != '*' && !take[c1[i][j - 1]]) {
          count2 = (count2 + m1[c1[i][j - 1]]) % 10;
          take[c1[i][j - 1]] = true;
        }
        if ((j + 1) < m && s[i][j + 1] != '*' && !take[c1[i][j + 1]]) {
          count2 = (count2 + m1[c1[i][j + 1]]) % 10;
          take[c1[i][j + 1]] = true;
        }
        cout << (count2 + 1);
      } else {
        cout << s[i][j];
      }
    }
    cout << "\n";
  }
  return 0;
}
