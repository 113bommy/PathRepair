#include <bits/stdc++.h>
int main() {
  int n;
  char s[102];
  int a[30] = {0};
  scanf("%d%s", &n, &s);
  int len = strlen(s);
  int i;
  int sum = 0;
  for (i = 0; i < len; i++) {
    if (a[s[i] - 'a' + 1] == 0) sum++, a[s[i] - 'a' + 1] = 1;
  }
  if (sum >= n)
    printf("YES\n");
  else {
    printf("NO\n");
    return 0;
  }
  printf("%c", s[0]);
  a[s[0] - 'a' + 1] = 0;
  sum = 1;
  for (i = 1; i < len; i++) {
    if (sum == n) {
      printf("%c", s[i]);
      continue;
    }
    if (a[s[i] - 'a' + 1] == 0) {
      printf("%c", s[i]);
      continue;
    }
    if (sum < n && a[s[i] - 'a' + 1] == 1) {
      sum++;
      printf("\n%c", s[i]);
      a[s[i] - 'a' + 1] = 0;
      continue;
    }
  }
  printf("\n");
}
