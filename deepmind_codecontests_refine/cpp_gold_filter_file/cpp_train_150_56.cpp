#include <bits/stdc++.h>
using namespace std;
int n, cnt;
bool flag;
char vis[105];
int num[105];
int main() {
  while (~scanf("%d", &n)) {
    flag = false;
    scanf("%s", vis);
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++) {
      if (vis[i] == '*') num[i] = 1;
    }
    cnt = (n + 1) / 4;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= cnt; j++) {
        if (num[i] && num[i + j] && num[i + 2 * j] && num[i + 3 * j] &&
            num[i + 4 * j]) {
          flag = true;
          break;
        }
      }
    }
    if (flag)
      puts("yes");
    else
      puts("no");
  }
  return 0;
}
