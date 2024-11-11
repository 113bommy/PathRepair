#include <bits/stdc++.h>
int main(void) {
  char a[1000], b[1000];
  int i;
  scanf("%s", &a);
  scanf("%s", &b);
  for (i = 0; i < strlen(a); i++) {
    if (a[i] != b[i]) {
      printf("1");
    } else {
      printf("0");
    }
  }
}
