#include <bits/stdc++.h>
bool b[100005], flag;
int s[100005], x, y, n, m;
char c;
int main() {
  scanf("%d%d\n", &n, &m);
  while (m--) {
    scanf("%c %d\n", &c, &x);
    if (c == '+') {
      if (b[x]) {
        puts("Already on");
        continue;
      }
      flag = true;
      y = x;
      for (int i = 2; i <= (int)sqrt(x) + 1; ++i)
        if (y % i == 0) {
          if (s[i]) {
            printf("Conflict with %d\n", s[i]);
            flag = false;
            break;
          }
          while (y % i == 0) y /= i;
        }
      if (flag && y != 1 && s[y]) {
        printf("Conflict with %d\n", s[y]);
        flag = false;
      }
      y = x;
      if (flag) {
        b[x] = true;
        for (int i = 2; i <= (int)sqrt(x) + 1; ++i)
          if (y % i == 0) {
            s[i] = x;
            while (y % i == 0) y /= i;
          }
        s[y] = x;
        puts("Success");
      }
    } else {
      if (!b[x]) {
        puts("Already off");
        continue;
      }
      b[x] = false;
      y = x;
      for (int i = 2; i <= (int)sqrt(x) + 1; ++i)
        if (y % i == 0) {
          s[i] = 0;
          while (y % i == 0) y /= i;
        }
      s[y] = 0;
      puts("Success");
    }
  }
}
