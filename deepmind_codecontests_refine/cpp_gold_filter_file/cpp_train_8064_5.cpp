#include <bits/stdc++.h>
int interval[2005][2];
int lista[2005], nr;
int desc[2005], inc[2005];
char s[2005];
int l = 0;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &interval[i][0], &interval[i][1]);
  }
  int j = 1;
  for (int i = 1; i <= 2 * n; ++i) {
    if (nr == 0) {
      s[l] = '(';
      ++l;
      desc[j] = i;
      ++nr;
      lista[nr] = j;
      ++j;
    } else {
      if (interval[lista[nr]][0] <= i - desc[lista[nr]]) {
        s[l] = ')';
        ++l;
        inc[lista[nr]] = i;
        --nr;
      } else {
        s[l] = '(';
        ++l;
        desc[j] = i;
        ++nr;
        lista[nr] = j;
        ++j;
      }
    }
  }
  s[l] = '\0';
  int advr = 1;
  for (int i = 1; i <= n; ++i) {
    if (inc[i] - desc[i] < interval[i][0] || inc[i] - desc[i] > interval[i][1])
      advr = 0;
  }
  if (advr) {
    printf("%s", s);
  } else {
    printf("IMPOSSIBLE");
  }
  return 0;
}
