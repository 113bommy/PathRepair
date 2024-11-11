#include <bits/stdc++.h>
int a[3];
int main() {
  int p;
  scanf("%d", &p);
  for (int i = 0; i < p; ++i) {
    char c;
    scanf("\n%c", &c);
    if (c == 'F') ++a[0];
    if (c == 'I') ++a[1];
    if (c == 'A') ++a[2];
  }
  if (a[1] > 1) {
    printf("0\n");
    return 0;
  }
  if (a[1] == 1) {
    printf("1\n");
    return 0;
  }
  printf("%d\n", a[2]);
}
