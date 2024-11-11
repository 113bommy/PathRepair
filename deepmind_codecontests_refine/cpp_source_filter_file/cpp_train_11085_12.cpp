#include <bits/stdc++.h>
int main() {
  long long int tes, i, b = 0, c = 0, d = 0;
  int a;
  scanf("%I64d", &tes);
  for (i = 0; i < tes; i++) {
    scanf("%d", &a);
    if (a == 1)
      b++;
    else if (a == 2)
      c++;
    else
      d++;
  }
  if (b >= c && b >= d)
    printf("%I64d\n", c + d);
  else if (c >= b && c >= d)
    printf("%I64d\n", b + d);
  else if (d >= b && d >= c)
    printf("%I64d\n", c + d);
  return 0;
}
