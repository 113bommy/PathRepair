#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
char maps[maxn][maxn];
int main() {
  int n, m, K;
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 0; i < n; i++) scanf("%s", maps[i]);
  if (K == 1) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (maps[i][j] == '.') ans++;
      }
    }
    printf("%d\n", ans);
    return 0;
  }
  int ans = 0;
  int cnt = 0;
  int i, j;
  for (i = 0; i < n; i++) {
    cnt = 0;
    for (j = 0; j < m; j++) {
      if (maps[i][j] == '*' || maps[i][j + 1] == '\0') {
        if (maps[i][j] == '.') cnt++;
        ans += cnt >= K ? cnt - K + 1 : 0;
        cnt = 0;
        continue;
      }
      cnt++;
    }
  }
  if (m != 1) {
    for (i = 0; i < m; i++) {
      cnt = 0;
      for (j = 0; j < n; j++) {
        if (maps[j][i] == '*' || maps[j + 1][i] == '\0') {
          if (maps[j][i] == '.') cnt++;
          ans += cnt >= K ? cnt - K + 1 : 0;
          cnt = 0;
          continue;
        }
        cnt++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
