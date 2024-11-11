#include <bits/stdc++.h>
using namespace std;
long long INF = (1e9);
char a[200010], b[200010];
bool dfs(int aL, int aR, int bL, int bR) {
  int len = aR - aL + 1;
  int flag = 1;
  for (int i = 1; i <= len; i++) {
    if (a[aL + i - 1] != b[bL + i - 1]) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    return true;
  }
  if (len % 2 == 1) return false;
  int AL1 = aL, AR1 = aL + len / 2 - 1;
  int AL2 = AR1 + 1, AR2 = aR;
  int BL1 = bL, BR1 = bL + len / 2 - 1;
  int BL2 = BR1 + 1, BR2 = bR;
  if (dfs(AL1, AR1, BL1, BR1) && dfs(AL2, AR2, BL2, BL2)) {
    return true;
  }
  if (dfs(AL1, AR1, BL2, BR2) && dfs(AL2, AR2, BL1, BR1)) {
    return true;
  }
  return false;
}
int main() {
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  int len = strlen(a + 1);
  if (dfs(1, len, 1, len)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
