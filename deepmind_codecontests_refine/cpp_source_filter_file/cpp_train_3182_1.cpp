#include <bits/stdc++.h>
char a[105];
int c[105];
int main() {
  int n, i, j, len, cnt, C, S;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d ", &c[i]);
  }
  for (i = 1; i <= n; i++) {
    gets(a);
    len = strlen(a);
    cnt = 0, C = 0, S = 0;
    for (j = 0; j < len; j++) {
      if (a[j] == 'a' || a[j] == 'e' || a[j] == 'i' || a[j] == 'o' ||
          a[j] == 'u' || a[j] == 'y')
        cnt++;
      if (a[j] == ' ' && cnt) C++, S += cnt, cnt = 0;
    }
    if (cnt) C++, S += cnt;
    if (c[i] > S || C > c[i]) break;
  }
  if (i == n + 1)
    printf("YES");
  else
    printf("NO");
  return 0;
}
