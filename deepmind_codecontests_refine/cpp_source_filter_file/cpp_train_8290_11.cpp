#include <bits/stdc++.h>
int main() {
  char s[81];
  unsigned short pass[8] = {}, nums[10] = {};
  int i = 0, j = 0, k;
  scanf("%s", s);
  while (i < 80) {
    for (k = 0; k < 10; k++, i++)
      if (s[i] - '0' == 1) pass[j] |= (1 << (7 - k));
    j++;
  }
  for (i = 0; i < 10; i++) {
    scanf("%s", s);
    for (k = 0; k < 10; k++)
      if (s[k] - '0' == 1) nums[i] |= (1 << (7 - k));
  }
  for (i = 0; i < 8; i++)
    for (j = 0; j < 10; j++)
      if (pass[i] == nums[j]) {
        printf("%d", j);
        break;
      }
  return 0;
}
