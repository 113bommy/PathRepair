#include <bits/stdc++.h>
bool a[110];
char s[110];
int main() {
  int n, j, i, k;
  memset(a, 0, sizeof(a));
  scanf("%d%s", &n, s);
  for (i = 0; i < n; i++)
    if (s[i] == '*') a[i] = true;
  for (i = 0; i < n; i++) {
    for (j = 1; j < n; j++) {
      int cnt = 0;
      for (k = i; k < n; k += j)
        if (!a[k])
          break;
        else
          cnt++;
      if (cnt >= 5) {
        printf("yes\n");
        return 0;
      }
    }
  }
  printf("no\n");
  return 0;
}
