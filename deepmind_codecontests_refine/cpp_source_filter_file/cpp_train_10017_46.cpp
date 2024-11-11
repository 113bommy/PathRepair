#include <bits/stdc++.h>
int main() {
  unsigned short n, o = 0, i, t;
  scanf("%hu", &n);
  for (i = 0; i < n; i++) {
    scanf("%hu", &t);
    if (t % 2) {
      o++;
    }
  }
  if (o % 2) {
    printf("1");
  } else {
    printf("%hu", n - o);
  }
  return 0;
}
