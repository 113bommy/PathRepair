#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
struct NODE {
  char str[2];
} nodes[1010][1010];
int n, m;
int num[5];
char str[5];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%s", str);
        int re = str[0] - '0' + str[1] - '0';
        num[re]++;
      }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (!(i & 1)) {
        for (int j = 0; j < m; j++) {
          if (num[0]) {
            nodes[i][j].str[0] = nodes[i][j].str[1] = '1';
            num[0]--;
          } else if (num[1]) {
            if (flag) {
              nodes[i][j].str[0] = '0';
              nodes[i][j].str[1] = '1';
            } else {
              nodes[i][j].str[0] = '1';
              nodes[i][j].str[1] = '0';
            }
            num[1]--;
          } else {
            nodes[i][j].str[0] = '0';
            nodes[i][j].str[1] = '0';
          }
        }
      } else {
        for (int j = m - 1; j >= 0; j--) {
          if (num[0]) {
            nodes[i][j].str[0] = nodes[i][j].str[1] = '1';
            num[0]--;
          } else if (num[1]) {
            if (flag) {
              nodes[i][j].str[0] = '0';
              nodes[i][j].str[1] = '1';
            } else {
              nodes[i][j].str[0] = '1';
              nodes[i][j].str[1] = '0';
            }
            num[1]--;
          } else {
            nodes[i][j].str[0] = '0';
            nodes[i][j].str[1] = '0';
          }
        }
      }
      flag ^= 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%c%c ", nodes[i][j].str[0], nodes[i][j].str[1]);
      }
      printf("\n");
    }
  }
  return 0;
}
