#include <bits/stdc++.h>
using namespace std;
char buf[3000];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int c1(0), c2(0), c3(0);
  getchar();
  for (auto i = 0; i < n; i++) {
    fgets(buf, 3000, stdin);
    for (auto j = 0; j < m; j++) {
      if (buf[3 * j] == buf[3 * j + 1]) {
        if (buf[3 * j] == '1') {
          c1++;
        } else {
          c3++;
        }
      } else {
        c2++;
      }
    }
  }
  for (auto i = 0; i < n; i++) {
    if (i % 2 == 0) {
      int j = 0;
      for (; j < m && c1 > 0; j++, c1--) {
        buf[3 * j] = '1';
        buf[3 * j + 1] = '1';
        buf[3 * j + 2] = ' ';
      }
      for (; j < m && c2 > 0; j++, c2--) {
        buf[3 * j] = '1';
        buf[3 * j + 1] = '0';
        buf[3 * j + 2] = ' ';
      }
      for (; j < m && c3 > 0; j++, c3--) {
        buf[3 * j] = '0';
        buf[3 * j + 1] = '0';
        buf[3 * j + 2] = ' ';
      }
    } else {
      int j = m;
      for (; j > 0 && c1 > 0; j--, c1--) {
        buf[3 * j - 1] = ' ';
        buf[3 * j - 2] = '1';
        buf[3 * j - 3] = '1';
      }
      for (; j > 0 && c2 > 0; j--, c2--) {
        buf[3 * j - 1] = ' ';
        buf[3 * j - 2] = '1';
        buf[3 * j - 3] = '0';
      }
      for (; j > 0 && c3 > 0; j--, c3--) {
        buf[3 * j - 1] = ' ';
        buf[3 * j - 2] = '0';
        buf[3 * j - 3] = '0';
      }
    }
    buf[3 * m - 1] = '\0';
    printf("%s\n", buf);
  }
  return 0;
}
