#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int N = 200005;
char s[30][30];
bool check(int x, int y) {
  char ch = s[x][y];
  s[x][y] = 'X';
  bool flag = false;
  for (int ci = 1; ci <= 10; ci++)
    for (int cj = 1; cj <= 10; cj++)
      if (s[ci][cj] == 'X') {
        bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
        for (int ca = 0; ca <= 4; ca++) {
          if (s[ci][cj + ca] != 'X') f1 = 1;
          if (s[ci + ca][cj] != 'X') f2 = 1;
          if (s[ci + ca][cj + ca] != 'X') f3 = 1;
          if (ci - ca < 1 || s[ci - ca][cj + ca] != 'X') f4 = 1;
        }
        if (f1 == 0 || f2 == 0 || f3 == 0 || f4 == 0) {
          flag = 1;
          break;
        }
      }
  s[x][y] = ch;
  return flag;
}
int main() {
  for (int i = 1; i <= 10; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++) {
      if (s[i][j] == '.' && check(i, j)) return 0 * printf("YES\n");
    }
  puts("NO");
  return 0;
}
