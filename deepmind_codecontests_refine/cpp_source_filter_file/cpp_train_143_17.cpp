#include <bits/stdc++.h>
using namespace std;
int ans[5200];
int str[5200];
int oper[5200][10];
int n, m;
int val[5200];
bool have[5200];
bool judge() {
  int i, j, k;
  int tmp;
  for (i = 1; i <= m; i++) {
    if (oper[i][1] == 2) {
      tmp = -1100000000;
      for (j = oper[i][2]; j <= oper[i][3]; j++) {
        tmp = max(val[j], tmp);
      }
      if (tmp != oper[i][4]) return false;
    } else {
      for (j = oper[i][2]; j <= oper[i][3]; j++) {
        val[j] += oper[i][4];
        if (val[j] > 1000000000) {
          return false;
        }
      }
    }
  }
  return true;
}
int main() {
  int i, j, k;
  int tmp, cnt, len;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(have, true, sizeof(have));
    memset(val, 0, sizeof(val));
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= 4; j++) {
        scanf("%d", &oper[i][j]);
      }
    }
    for (i = m; i >= 1; i--) {
      if (oper[i][1] == 2) {
        for (j = oper[i][2]; j <= oper[i][3]; j++) {
          if (!have[j]) {
            val[j] = oper[i][4];
          } else {
            val[j] = min(oper[i][4], val[j]);
          }
          have[j] = true;
        }
      } else {
        for (j = oper[i][2]; j <= oper[i][3]; j++) {
          if (have[j]) val[j] -= oper[i][4];
        }
      }
    }
    for (i = 1; i <= n; i++) {
      if (have[i])
        ans[i] = val[i];
      else
        ans[i] = 0;
    }
    if (judge()) {
      puts("YES");
      for (i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
      }
      puts("");
    } else {
      puts("NO");
    }
  }
  return 0;
}
