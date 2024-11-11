#include <bits/stdc++.h>
using namespace std;
int vis[5];
int mp[5][105][105];
int a[5];
int b[205][205];
int n, ans;
void check() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) b[i][j] = mp[a[1]][i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) b[i + n][j] = mp[a[2]][i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) b[i][j + n] = mp[a[3]][i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) b[i + n][j + n] = mp[a[4]][i][j];
  }
  int tmp = 0;
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      if (b[i][j] != ((i + j) % 2)) tmp++;
    }
  }
  ans = min(ans, tmp);
  tmp = 0;
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      if (b[i][j] != ((i + j + 1) % 2)) tmp++;
    }
  }
  ans = min(ans, tmp);
}
void dfs(int x) {
  if (x == 5) {
    check();
    return;
  }
  for (int i = 1; i <= 4; i++) {
    if (!vis[i]) {
      a[x] = i;
      vis[i] = 1;
      dfs(x + 1);
      vis[i] = 0;
    }
  }
}
int main() {
  char s[105];
  scanf("%d", &n);
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%s", s + 1);
      for (int k = 1; k <= n; k++) {
        if (s[k] == '0')
          mp[i][j][k] = 0;
        else
          mp[i][j][k] = 1;
      }
    }
  }
  ans = 10050;
  dfs(1);
  printf("%d", ans);
}
