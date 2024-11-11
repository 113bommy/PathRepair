#include <bits/stdc++.h>
static char s[2000 + 2], t[2000 + 2];
static int hs[26], ht[26], sol[10000];
static void shift(int by, int n, int *m) {
  char aux[2000 + 1];
  int i;
  sol[(*m)++] = by;
  for (i = 1; i <= by; i++) {
    aux[i - 1] = s[n - i];
  }
  for (i = 1; i <= n - by; i++) {
    s[n - i] = s[n - i - by];
  }
  for (i = 0; i < by; i++) {
    s[i] = aux[i];
  }
}
int main(void) {
  int n, i, j, m;
  scanf("%d %s %s", &n, s, t);
  for (i = 0; i < n; i++) {
    hs[s[i] - 'a']++;
    ht[t[i] - 'a']++;
  }
  for (i = 0; i < 26; i++) {
    if (hs[i] != ht[i]) {
      puts("-1");
      return 0;
    }
  }
  m = 0;
  for (i = n - 1; i >= 0; i--) {
    for (j = n - 1; j >= 0; j--) {
      if (t[i] == s[j]) {
        break;
      }
    }
    shift(n, n, &m);
    shift(j, n, &m);
    shift(1, n, &m);
  }
  printf("%d\n", m);
  for (i = 0; i < m; i++) {
    printf("%d%c", sol[i], " \n"[i == m - 1]);
  }
  return 0;
}
