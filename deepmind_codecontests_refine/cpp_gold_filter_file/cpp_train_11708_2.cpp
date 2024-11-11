#include <bits/stdc++.h>
using namespace std;
char s[40];
struct node {
  char s[40];
  int o;
} nd[70];
int main() {
  int n, m, i, j, k;
  scanf("%d%d", &n, &m);
  scanf("%s%d", s, &k);
  for (i = 0; i < m - 1; i++) {
    scanf("%s%d", nd[i].s, &nd[i].o);
  }
  m--;
  char t[50] = {0};
  int ans = 0;
  for (long long comb = (1LL << k) - 1; comb < 1LL << n;) {
    for (i = 0; i < n; i++) {
      if (comb & (1LL << i)) {
        t[i] = s[i];
      } else {
        t[i] = s[i] == '1' ? '0' : '1';
      }
    }
    for (i = 0; i < m; i++) {
      int tmp = 0;
      for (j = 0; j < n; j++) {
        if (t[j] == nd[i].s[j]) ++tmp;
      }
      if (tmp != nd[i].o) break;
    }
    if (i == m) ans++;
    long long x = comb & -comb, y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
  }
  printf("%d\n", ans);
  return 0;
}
