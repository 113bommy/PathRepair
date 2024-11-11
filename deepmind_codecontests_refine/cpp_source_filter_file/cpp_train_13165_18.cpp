#include <bits/stdc++.h>
int T[] = {2, 6, 2, 3, 3, 4, 2, 5, 1, 2};
char s[3];
int main() {
  scanf("%s", s);
  printf("%d\n", T[s[0] - '0'] * T[s[1] - '0']);
}
