#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  char str[100], bits[100], res[100];
  scanf("%s", str);
  int cry = 0, i, count = 0;
  if (str[0] == '1')
    bits[0] = '0', cry = 1;
  else
    bits[0] = '1', cry = 0;
  for (i = 1; i < n; i++) {
    if (str[i] == '1' && cry == 1)
      bits[i] = '0', cry = 1;
    else if ((str[i] == '1' && cry == 0) || (str[i] == '0' && cry == 1))
      bits[i] = '1', cry = 0;
    else
      bits[i] = '0', cry = 0;
  }
  for (i = 0; i < n; i++) {
    if ((bits[i] == '1' && str[i] == '0') || (bits[i] == '0' && str[i] == '1'))
      count++;
  }
  printf("%d\n", count);
  return 0;
}
