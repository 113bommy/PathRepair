#include <bits/stdc++.h>
int main() {
  int n, p, f = 0, i;
  char a[100006];
  scanf("%d%d%s", &n, &p, a);
  for (i = 0; i < n - p; i++) {
    if (a[i] == '.' || a[i + p] == '.') {
      f = 1;
      if (a[i] == '.' && a[i + p] == '.') {
        a[i] == '0';
        a[i + p] == '1';
      } else if (a[i] == '.')
        a[i] == '0' + '1' - a[i + p];
      else
        a[i + p] == '0' + '1' - a[i];
    } else if (a[i] != a[i + p])
      f = 1;
  }
  for (i = 0; i < n; i++)
    if (a[i] == '.') a[i] = '0';
  puts(f ? a : "No");
  return 0;
}
