#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
char s[N], t[N];
int l[N], r[N];
int main() {
  int T;
  scanf("%d", &T);
  int n, k, tot;
  while (T--) {
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
    for (int i = 1; i <= (k - 1) * 2 - 1; i += 2) {
      t[i] = '(';
      t[i + 1] = ')';
    }
    for (int i = (k - 1) * 2 + 1; i <= n / 2 + k - 1; i++) {
      t[i] = '(';
    }
    for (int i = n / 2 + k; i <= n; i++) {
      t[i] = ')';
    }
    tot = 0;
    for (int i = 1; i <= n - 1; i++) {
      if (s[i] != t[i]) {
        for (int j = i + 1; j <= n; j++) {
          if (s[j] == t[i]) {
            tot++;
            l[tot] = i;
            r[tot] = j;
            reverse(s + i, s + j + 1);
            break;
          }
        }
      }
    }
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++) {
      printf("%d %d\n", l[i], r[i]);
    }
  }
  return 0;
}
