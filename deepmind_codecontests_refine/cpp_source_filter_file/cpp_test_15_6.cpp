#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 10;
int n, m, k;
char mp[15][15];
int vis[15][15];
void check(int x, int y) {
  int pos1 = 0, pos2 = 0;
  for (int i = x, j = y; i >= 1 && j >= 1; i--, j--) {
    if (mp[i][j] == '*') {
      pos1++;
    } else {
      break;
    }
  }
  for (int i = x, j = y; i >= 1 && j <= m; i--, j++) {
    if (mp[i][j] == '*') {
      pos2++;
    } else {
      break;
    }
  }
  for (int i = x, j = y; i >= x - min(pos1, pos2) + 1; i--, j--) {
    vis[i][j] = max(vis[i][j], min(pos1, pos2) - 1);
  }
  for (int i = x, j = y; i >= x - min(pos1, pos2) + 1; i--, j++) {
    vis[i][j] = max(vis[i][j], min(pos1, pos2) - 1);
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(vis, 0, sizeof vis);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
      getchar();
      for (int j = 1; j <= m; j++) {
        scanf("%c", &mp[i][j]);
      }
    }
    int kk = 1;
    for (int i = k + 1; i <= n; i++) {
      for (int j = k + 1; j <= m - k; j++) {
        if (mp[i][j] == '*') {
          check(i, j);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (mp[i][j] == '*' && vis[i][j] < k) kk = 0;
      }
    }
    if (kk)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
