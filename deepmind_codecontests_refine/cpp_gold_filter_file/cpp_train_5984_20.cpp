#include <bits/stdc++.h>
int main(void) {
  long long a[65] = {0};
  char c[100005];
  int length;
  long long sum = 0;
  int i, j;
  scanf("%s", c);
  length = strlen(c);
  for (i = 0; i < length; i++) {
    if (c[i] <= 57 && c[i] >= 48) a[c[i] - 48]++;
    if (c[i] >= 65 && c[i] <= 90) a[c[i] - 65 + 11]++;
    if (c[i] >= 97 && c[i] <= 122) a[c[i] - 97 + 37]++;
  }
  for (i = 0; i < 65; i++) sum += a[i] * a[i];
  printf("%I64d\n", sum);
}
