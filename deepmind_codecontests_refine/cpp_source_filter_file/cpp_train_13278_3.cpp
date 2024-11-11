#include <bits/stdc++.h>
int main(void) {
  int TOTAL;
  int COUNT = 0;
  scanf("%d", &TOTAL);
  for (COUNT = 0; COUNT < TOTAL; COUNT++) {
    if (COUNT == 0) {
      printf("I hate ");
    } else if (COUNT % 2 == 1) {
      printf("that i love ");
    } else {
      printf("that i hate ");
    }
  }
  printf("it\n");
}
