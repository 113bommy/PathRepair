#include <bits/stdc++.h>
int main() {
  int a, b;
  int n;
  int i;
  int a1c = 0, a2c = 0;
  int a1, a2;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &a1, &a2);
    if (a1 > a2) {
      a1c++;
    } else if (a2 > a1) {
      a2c++;
    }
  }
  if (a1c > a2c) {
    printf("Mishka");
  } else if (a2c > a1c) {
    printf("Chris");
  } else {
    printf("Friendship is magic!");
  }
}
