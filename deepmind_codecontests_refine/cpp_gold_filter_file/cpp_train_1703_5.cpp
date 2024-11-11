#include <bits/stdc++.h>
using namespace std;
char s[500009];
int n, k;
char f(int x, int y) {
  char cc = 'A' + (k - 1);
  for (char c = 'A'; c <= cc; c++) {
    if (c != s[x] && c != s[y]) return c;
  }
  return '0';
}
int main() {
  int i, j, m, d, test, t = 0;
  while (scanf("%d%d", &n, &k) == 2) {
    scanf("%s", s + 1);
    s[0] = '0';
    int cnt = 0;
    if (k == 2) {
      int cnt1 = 0, cnt2 = 0;
      for (i = 1; i <= n; i++) {
        if (i % 2 == 1 && s[i] == 'B') cnt1++;
        if (i % 2 == 0 && s[i] == 'A') cnt1++;
      }
      for (i = 1; i <= n; i++) {
        if (i % 2 == 0 && s[i] == 'B') cnt2++;
        if (i % 2 == 1 && s[i] == 'A') cnt2++;
      }
      if (cnt1 <= cnt2) {
        for (i = 1; i <= n; i++) {
          if (i % 2 == 1)
            s[i] = 'A';
          else
            s[i] = 'B';
        }
      } else {
        for (i = 1; i <= n; i++) {
          if (i % 2 == 1)
            s[i] = 'B';
          else
            s[i] = 'A';
        }
      }
      printf("%d\n%s\n", min(cnt1, cnt2), s + 1);
      continue;
    }
    for (i = 1; i < n; i++) {
      if (s[i] == s[i + 1]) {
        cnt++;
        if (i != n - 1 && s[i] == s[i + 2]) {
          s[i + 1] = f(i, i + 2);
          i++;
        } else
          s[i] = f(i - 1, i + 1);
      }
    }
    printf("%d\n%s\n", cnt, s + 1);
  }
  return 0;
}
