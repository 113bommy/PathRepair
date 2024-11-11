#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e5 + 6;
char a[maxx];
int pre[maxx][3];
int main() {
  while (~scanf("%s", a + 1)) {
    int t;
    int len = strlen(a + 1);
    scanf("%d", &t);
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= len; i++) {
      pre[i][0] += pre[i - 1][0];
      pre[i][1] += pre[i - 1][1];
      pre[i][2] += pre[i - 1][2];
      if (a[i] == 'x') {
        pre[i][0]++;
      } else if (a[i] == 'y') {
        pre[i][1]++;
      } else {
        pre[i][2]++;
      }
    }
    int l, r;
    while (t--) {
      scanf("%d%d", &l, &r);
      if (r - l + 1 < 2) {
        printf("YES\n");
        continue;
      }
      int x = pre[r][0] - pre[l - 1][0];
      int y = pre[r][1] - pre[l - 1][1];
      int z = pre[r][2] - pre[l - 1][2];
      int w = min(x, min(y, z));
      int f = max(x, max(y, z));
      if (f - w >= 2) {
        printf("NO\n");
      } else {
        printf("YES\n");
      }
    }
  }
  return 0;
}
