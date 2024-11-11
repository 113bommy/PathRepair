#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
inline void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
char s[3][100010];
int main() {
  scanf("%s%s", s[1] + 1, s[2] + 1);
  int l = strlen(s[1] + 1), ans = 0;
  for (int i = 1; i <= l; i++) {
    if (s[1][i] == '0' && s[2][i] == '0') {
      if (s[1][i + 1] == '0') {
        s[1][i] = s[2][i] = s[1][i + 1] = 'X';
        ans++;
      } else if (s[2][i + 1] == '0') {
        s[1][i] = s[2][i] = s[2][i + 1] = 'X';
        ans++;
      }
    } else if (s[1][i] == '0') {
      if (s[1][i + 1] == '0' && s[2][i + 1] == '0') {
        s[1][i] = s[1][i + 1] = s[2][i + 1] = 'X';
        ans++;
      }
    } else if (s[2][i] == '0') {
      if (s[1][i + 1] == '0' && s[2][i + 1] == '0') {
        s[2][i] = s[1][i + 1] = s[2][i + 1] = 'X';
        ans++;
      }
    }
  }
  writeln(ans);
  return 0;
}
