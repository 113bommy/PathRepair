#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
char s[20];
int d[10][2] = {3, 1, 0, 0, 0, 1, 0, 2, 1, 0, 1, 1, 1, 2, 2, 0, 2, 1, 2, 2};
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    scanf("%s", s);
    if (n == 1) {
      printf("YES\n");
      continue;
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
      int id = 0;
      if (s[0] - '0' == i) continue;
      int flag = 0;
      int x = d[i][0], y = d[i][1];
      for (int j = 0; j < n - 1; j++) {
        int id0 = s[j] - '0', id1 = s[j + 1] - '0';
        x += (d[id1][0] - d[id0][0]);
        y += (d[id1][1] - d[id0][1]);
        int f = 0;
        for (int k = 0; k < 10; k++) {
          if (x == d[k][0] && y == d[k][1]) {
            f = 1;
            break;
          }
        }
        if (!f) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        ans = 1;
        break;
      }
    }
    if (!ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
