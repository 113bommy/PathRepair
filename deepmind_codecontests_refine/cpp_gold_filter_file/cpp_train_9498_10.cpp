#include <bits/stdc++.h>
char str[1005];
int r[1005];
int h(int x) {
  int b[8], v, i;
  for (i = 0; i < 8; i++, x /= 2) b[i] = x % 2;
  for (v = i = 0; i < 8; i++) v = v * 2 + b[i];
  return v;
}
int main() {
  gets(str);
  int i, j, n;
  n = strlen(str);
  for (i = n - 1; i >= 0; i--) {
    if (!i) {
      r[i] = 0 - h(str[i]);
      if (r[i] < 0) r[i] += 256;
      continue;
    }
    str[i] = h(str[i]);
    r[i] = h(str[i - 1]) - str[i];
    if (r[i] < 0) r[i] += 256;
  }
  for (i = 0; i < n; i++) printf("%d\n", r[i] % 256);
  return 0;
}
