#include <bits/stdc++.h>
using namespace std;
char mp[1005][1005];
char p[4] = {'A', 'B', 'C', 'D'};
int n, m;
int main() {
  int i, j, k;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i < n; i++) scanf("%s", mp[i]);
    bool flag = false;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (mp[i][j] == 'w') {
          if (j + 2 < m && mp[i][j + 1] == 'b' && mp[i][j + 2] == 'w') {
            for (k = 0; k < 4; k++) {
              if (j > 0 && mp[i][j - 1] == p[k]) continue;
              if (j > 0 && mp[i - 1][j] == p[k]) continue;
              if (j > 0 && mp[i - 1][j + 1] == p[k]) continue;
              if (j > 0 && mp[i - 1][j + 2] == p[k]) continue;
              if (j + 3 < m && mp[i][j + 3] == p[k]) continue;
              break;
            }
            mp[i][j] = mp[i][j + 1] = mp[i][j + 2] = p[k];
          } else if (i + 2 < n && mp[i + 1][j] == 'b' && mp[i + 2][j] == 'w') {
            for (k = 0; k < 4; k++) {
              if (i > 0 && mp[i - 1][j] == p[k]) continue;
              if (j > 0 && mp[i][j - 1] == p[k]) continue;
              if (j + 1 < m && mp[i][j + 1] == p[k]) continue;
              break;
            }
            mp[i][j] = mp[i + 1][j] = mp[i + 2][j] = p[k];
          } else {
            flag = true;
            break;
          }
        }
      }
      if (flag) break;
    }
    if (flag)
      puts("NO");
    else {
      puts("YES");
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          if (isupper(mp[i][j])) mp[i][j] = tolower(mp[i][j]);
          putchar(mp[i][j]);
        }
        puts("");
      }
    }
  }
  return 0;
}
