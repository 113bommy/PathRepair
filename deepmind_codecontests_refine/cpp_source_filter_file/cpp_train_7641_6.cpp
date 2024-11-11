#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int n;
int mp[maxn][maxn];
int vis[maxn][maxn];
char stk[3000007];
int top;
void dfs(int x, int y) {
  vis[x][y] = true;
  if (mp[x][y] == 0) {
    mp[x][y] = 1;
    stk[++top] = '1';
  }
  for (int i = x - 1; i >= 1; i--) {
    if (mp[i][y] == 1) {
      if (!vis[x - 1][y]) {
        stk[++top] = 'U';
        dfs(x - 1, y);
        stk[++top] = 'D';
      }
      break;
    }
  }
  for (int i = x + 1; i <= n; i++) {
    if (mp[i][y] == 1) {
      if (!vis[x + 1][y]) {
        stk[++top] = 'D';
        dfs(x + 1, y);
        stk[++top] = 'U';
      }
      break;
    }
  }
  for (int i = y - 1; i >= 1; i--) {
    if (mp[x][i] == 1) {
      if (!vis[x][y - 1]) {
        stk[++top] = 'L';
        dfs(x, y - 1);
        stk[++top] = 'R';
      }
      break;
    }
  }
  for (int i = y + 1; i <= n; i++) {
    if (mp[x][y] == 1) {
      if (!vis[x][y + 1]) {
        stk[++top] = 'R';
        dfs(x, y + 1);
        stk[++top] = 'L';
      }
      break;
    }
  }
  mp[x][y] = 0;
  stk[++top] = '2';
}
int main() {
  int stx, sty;
  scanf("%d%d%d", &n, &stx, &sty);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &mp[i][j]);
    }
  }
  top = 0;
  dfs(stx, sty);
  bool ok = true;
  for (int i = 1; i <= n && ok; i++) {
    for (int j = 1; j <= n && ok; j++) {
      if (mp[i][j]) {
        ok = false;
        break;
      }
    }
  }
  if (!ok)
    puts("NO");
  else {
    puts("YES");
    for (int i = 1; i <= top; i++) {
      printf("%c", stk[i]);
    }
    puts("");
  }
  return 0;
}
