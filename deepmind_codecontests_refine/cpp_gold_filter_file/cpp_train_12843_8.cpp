#include <bits/stdc++.h>
int main() {
  int n, k, i, cnt, j, c = 0;
  scanf("%d %d", &n, &k);
  char a[14];
  for (i = 0; i < n; i++) {
    scanf("%s", a);
    cnt = 0;
    for (j = 0; j < strlen(a); j++) {
      if (a[j] == '4' || a[j] == '7') cnt++;
    }
    if (cnt <= k) c++;
  }
  printf("%d\n", c);
  return 0;
}
