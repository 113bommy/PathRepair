#include <bits/stdc++.h>
int main() {
  unsigned short n;
  scanf("%hu", &n);
  short res = 0;
  for (int i = 0; i < n; i = i + 1) {
    unsigned short m, c;
    scanf("%hu%hu", &m, &c);
    if (m > c) {
      res = res + 1;
    } else if (m < c) {
      res = res - 1;
    }
  }
  if (res > 0) {
    printf("Mishka\n");
  } else if (res < 0) {
    printf("Chris\n");
  } else {
    printf("Friendship is magic!^^\n");
  }
  return 0;
}
