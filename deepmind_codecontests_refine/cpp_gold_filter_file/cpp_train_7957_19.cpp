#include <bits/stdc++.h>
int ar[125];
int main() {
  char s[1001];
  int max = 0, sum = 0, len, i, k;
  scanf("%s", s);
  scanf("%d", &k);
  len = strlen(s);
  for (i = 97; i <= 122; i++) {
    scanf("%d", &ar[i]);
    if (ar[i] > max) max = ar[i];
  }
  for (i = 0; i < len; i++) {
    sum = sum + ((i + 1) * ar[s[i]]);
  }
  k = k + len;
  k = ((k * (k + 1)) / 2) - ((len * (len + 1)) / 2);
  sum = sum + (k * max);
  printf("%d\n", sum);
  return 0;
}
