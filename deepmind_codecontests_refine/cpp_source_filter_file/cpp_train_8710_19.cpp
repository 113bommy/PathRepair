#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int i;
  int b[6] = {0};
  if (n == 0) {
    printf("0\n");
    printf("Power\n");
    printf("Time\n");
    printf("Space\n");
    printf("Soul\n");
    printf("Reality\n");
    printf("Mind\n");
  } else {
    int l;
    for (l = 0; l < n; l++) {
      char a[100];
      scanf("%s", a);
      if (a[0] == 'p') b[0] = 1;
      if (a[0] == 'g') b[1] = 1;
      if (a[0] == 'b') b[2] = 1;
      if (a[0] == 'o') b[3] = 1;
      if (a[0] == 'r') b[4] = 1;
      if (a[0] == 'y') b[5] = 1;
    }
    printf("%d\n", 6 - n);
    if (b[0] == 0) printf("Power\n");
    if (b[1] == 0) printf("Time\n");
    if (b[2] == 0) printf("Space\n");
    if (b[3] == 0) printf("Soul\n");
    if (b[4] == 0) printf("Reality\n");
    if (b[5] == 0) printf("Mind\n");
  }
}
