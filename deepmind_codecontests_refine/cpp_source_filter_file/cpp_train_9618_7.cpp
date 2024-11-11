#include <bits/stdc++.h>
const int N = 5005;
int sg[N];
bool u[N];
char s[N];
int main() {
  int n, i, j;
  sg[0] = 0;
  sg[1] = 1;
  for (i = 2; i < N; i++) {
    memset(u, 0, sizeof(u));
    u[sg[i - 2]] = true;
    for (j = 2; j < i; j++) {
      int fg = (sg[j - 2] ^ sg[i - j - 1]);
      u[fg] = true;
    }
    for (j = 0; j < N; j++)
      if (!u[j]) break;
    sg[i] = j;
  }
  scanf("%s", s);
  n = strlen(s);
  memset(u, 0, sizeof(u));
  for (i = 2; i < n; i++) {
    if (s[i - 2] == s[i]) u[i] = true;
  }
  int r = 0, cnt = 0;
  for (i = 1; i <= n; i++) {
    if (u[i])
      cnt++;
    else if (cnt) {
      r ^= sg[cnt];
      cnt = 0;
    }
  }
  r ^= sg[cnt];
  if (!r) {
    puts("Second");
    return 0;
  }
  cnt = 0;
  int p = -1;
  for (i = 1; i <= n && p == -1; i++) {
    if (u[i])
      cnt++;
    else if (cnt) {
      if (cnt == 1) {
        if (r == 1) {
          p = i - 1;
          break;
        }
      } else {
        if ((r ^ sg[cnt]) == sg[cnt - 2]) {
          p = i - cnt;
          break;
        }
        for (j = 2; j < cnt; j++) {
          if ((r ^ sg[cnt]) == (sg[j - 2] ^ sg[i - j - 1])) {
            p = i - cnt + j - 1;
            break;
          }
        }
      }
      cnt = 0;
    }
  }
  puts("First");
  printf("%d\n", p);
  return 0;
}
