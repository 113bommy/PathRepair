#include <bits/stdc++.h>
using namespace std;
int n, m, ru, ju;
int s[200005];
int cmd[400005], dis[400005], p = 0;
int main() {
  scanf("%d %d %d %d", &n, &m, &ru, &ju);
  for (int i = (1); i <= (n); i++) scanf("%d", &s[i]);
  sort(s + 1, s + n + 1);
  s[0] = -1;
  s[n + 1] = m + 1 + ru;
  for (int i = (1); i <= (n); i++) {
    if (s[i] - s[i - 1] - 2 < ru) {
      printf("IMPOSSIBLE\n");
      return 0;
    }
    cmd[++p] = 1;
    dis[p] = s[i] - s[i - 1] - 2;
    int nx = -1;
    for (int j = (i + 1); j <= (n + 1); j++) {
      if (s[j - 1] - s[i] + 2 > ju) break;
      if (s[j] - s[j - 1] - 2 >= ru) {
        nx = j;
        break;
      }
    }
    if (nx == -1) {
      printf("IMPOSSIBLE\n");
      return 0;
    }
    cmd[++p] = 2;
    dis[p] = s[nx - 1] - s[i] + 2;
    i = nx - 1;
  }
  if (s[n] < m - 1) {
    cmd[++p] = 1;
    dis[p] = m - s[n] - 1;
  }
  for (int i = (1); i <= (p); i++) {
    if (cmd[i] == 1)
      printf("RUN %d\n", dis[i]);
    else
      printf("JUMP %d\n", dis[i]);
  }
  return 0;
}
