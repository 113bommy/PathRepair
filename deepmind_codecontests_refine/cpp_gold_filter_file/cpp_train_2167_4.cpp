#include <bits/stdc++.h>
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d\n", b / a < c ? b / a : c);
}