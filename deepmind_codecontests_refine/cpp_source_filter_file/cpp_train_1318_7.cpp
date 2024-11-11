#include <bits/stdc++.h>
char c[115];
int main() {
  int a, b = 0, d = 0;
  scanf("%s", c);
  for (a = 0; a <= 99; a++) {
    if (c[a] == 'o')
      b++;
    else if (c[a] == '-')
      d++;
  }
  if (b == 0)
    printf("NO");
  else if (d % b == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}
