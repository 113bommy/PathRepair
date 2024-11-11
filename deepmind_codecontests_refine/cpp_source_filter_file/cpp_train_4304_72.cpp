#include <bits/stdc++.h>
int l[20000];
int s[20000];
int i;
int a;
int main() {
  scanf("%d", &a);
  l[1] = 1;
  s[1] = 1;
  l[2] = 12;
  s[2] = 4;
  for (i = 3; i <= a; i++) {
    s[i] = s[i - 1] + 3;
    l[i] = 2 * (s[i] * 3 - 3) - (i - 1) * 6 - 6;
  }
  int sol = 0;
  for (i = 1; i <= a; i++) {
    sol += l[i];
  }
  printf("%d\n", sol);
  return 0;
}
