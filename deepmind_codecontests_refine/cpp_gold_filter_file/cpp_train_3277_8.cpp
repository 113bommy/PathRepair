#include <bits/stdc++.h>
int main() {
  int n, a[200005] = {0}, len, i, t, m;
  char str[200005];
  scanf("%s", str);
  len = strlen(str);
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &t);
    t--;
    a[t]++;
    a[len - t + 1]++;
  }
  m = (len - 1) / 2;
  for (i = 0; i <= m; i++) {
    if (i == 0) {
      if (a[i] % 2 == 0)
        continue;
      else
        str[i] = str[len - i - 1] + str[i] - (str[len - i - 1] = str[i]);
    } else {
      a[i] = a[i] + a[i - 1];
      if (a[i] % 2 == 0)
        continue;
      else
        str[i] = str[len - i - 1] + str[i] - (str[len - i - 1] = str[i]);
    }
  }
  printf("%s", str);
  return 0;
}
