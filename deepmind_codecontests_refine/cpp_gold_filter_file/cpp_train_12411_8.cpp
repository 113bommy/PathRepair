#include <bits/stdc++.h>
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int n;
char s[60], t[60], c[4] = "OHC";
void ask() {
  printf("? %s\n", t + 1), fflush(stdout);
  int m = read();
  for (int i = 1; i <= m; ++i)
    for (int p = read() - 1, j = 1; t[j]; ++j) s[p + j] = t[j];
}
void work1() {
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 3; ++j)
      memcpy(t, s, n + 1), t[1] = c[i], t[4] = c[j], ask();
}
void solve2() {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      if ((i == 2 && !s[1]) || (j == 0 && !s[n]) || (s[1] && s[1] ^ c[i]) ||
          (s[n] && s[n] ^ c[j]) || (!s[1] && !s[n] && i == 1 && j == 2))
        continue;
      memcpy(t, s, n + 1), t[1] = c[i], t[n] = c[j], ask();
    }
  if (!s[1] && !s[n]) s[1] = 'H', s[n] = 'C';
}
int main() {
  for (int T = read(); T; --T) {
    n = read(), memset(s, 0, sizeof s), memset(t, 0, sizeof t);
    t[1] = 'C', t[2] = 'C', ask(), t[1] = 'C', t[2] = 'H', ask(), t[1] = 'C',
    t[2] = 'O', ask(), t[1] = 'H', t[2] = 'O', ask();
    if (n == 4 && !s[1] && s[2] && s[3] && !s[4])
      work1();
    else {
      t[1] = 'O', t[2] = 'O', ask();
      for (int i = 2; i < n; ++i)
        if (!s[i]) s[i] = 'H';
      if (n == 4 && !s[1] && s[2] == 'H' && s[3] == 'H' && !s[4]) {
        t[1] = 'H', t[2] = 'H', t[3] = 'H', ask();
        if (!s[1]) s[1] = 'O';
        if (!s[4]) s[4] = 'C';
      } else
        solve2();
    }
    printf("! %s\n", s + 1), fflush(stdout), read();
  }
}
