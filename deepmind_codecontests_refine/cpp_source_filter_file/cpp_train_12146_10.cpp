#include <bits/stdc++.h>
using namespace std;
char mp[105][105];
int flag, cnt[105][105], n, m;
void dfs(int i, int j) {
  if (mp[i][j] == '*') {
    for (int p = -1; p <= 1; p++) {
      for (int q = -1; q <= 1; q++) {
        if (p == 0 && q == 0) continue;
        if (i + p < 0 || j + q < 0 || i + p >= n || j + q >= m) continue;
        if (mp[i + p][j + q] == '.') flag = 1;
        if (mp[i + p][j + q] >= '1' && mp[i + p][j + q] <= '8')
          cnt[i + p][j + q]++;
      }
    }
  }
}
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", mp[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dfs(i, j);
    }
  }
  if (flag == 1)
    printf("NO\n");
  else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mp[i][j] != '*' && mp[i][j] != '.' && mp[i][j] - '0' != cnt[i][j]) {
          flag = 1;
          break;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 1)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
