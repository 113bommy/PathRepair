#include <bits/stdc++.h>
int n, m;
char str[101][101];
char ans[101];
int ipt[101];
int cmpa(char a[]) {
  if (strlen(a) != strlen(ans)) return 0;
  for (int i = 0; i < strlen(a); ++i) {
    if (ans[i] == '?') continue;
    if (ans[i] != a[i]) return 0;
  }
  return 1;
}
int main() {
  int next;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", str[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &ipt[i]);
  strcpy(ans, str[ipt[0]]);
  for (int i = 1; i < m; ++i) {
    next = ipt[i];
    if (strlen(ans) != strlen(str[next])) {
      printf("No");
      return 0;
    } else {
      for (int k = 0; k < strlen(ans); ++k) {
        if (ans[k] != str[next][k]) ans[k] = '?';
      }
    }
  }
  for (int i = 0; i < ipt[0]; ++i) {
    if (1 == cmpa(str[i])) {
      printf("No");
      return 0;
    }
  }
  for (int t = 0; t < m - 1; ++t) {
    for (int i = ipt[t] + 1; i < ipt[t + 1]; ++i) {
      if (1 == cmpa(str[i])) {
        printf("No");
        return 0;
      }
    }
  }
  for (int i = ipt[m - 1] + 1; i < n; ++i) {
    if (1 == cmpa(str[i])) {
      printf("No");
      return 0;
    }
  }
  printf("Yes\n%s", ans);
  return 0;
}
