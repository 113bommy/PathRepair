#include <bits/stdc++.h>
int main() {
  int h, m;
  scanf("%d : %d", &h, &m);
  int a, h1, m1, c, M;
  scanf("%d", &a);
  h1 = a / 60;
  m1 = a % 60;
  M = (m + m1) % 60;
  c = (m + m1) / 60;
  h = (h + h1 + c) % 24;
  printf("%02d:%02d\n", h, M);
  return 0;
}
