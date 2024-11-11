#include <bits/stdc++.h>
using namespace std;
int a[4], some[2];
int main() {
  for (register int i = 0; i < 4; i++) {
    scanf("%d", &a[i]);
  }
  for (register int i = 0; i < 2; i++) {
    while (some[i] * (some[i] - 1) / 2 < a[i * 3]) {
      some[i]++;
    }
    if (some[i] * (some[i] - 1) / 2 != a[i * 3]) {
      printf("Impossible\n");
      return 0;
    }
  }
  if (a[0] == 0 && a[1] == 0) {
    if (a[1] == 0 && a[2] == 0) {
      printf("1\n");
      return 0;
    }
    if (a[1] == 0 && a[2] == 1) {
      printf("10\n");
      return 0;
    }
    if (a[1] == 1 && a[2] == 0) {
      printf("01\n");
      return 0;
    }
    printf("Impossible\n");
    return 0;
  }
  if (a[0] == 0) {
    if (a[1] == 0 && a[2] == 0) {
      for (register int i = 1; i <= some[1]; i++) {
        printf("1");
      }
      printf("\n");
      return 0;
    }
    if (a[1] + a[2] == some[1]) {
      for (register int i = 1; i <= a[2]; i++) {
        printf("1");
      }
      printf("0");
      for (register int i = 1; i <= a[1]; i++) {
        printf("1");
      }
      printf("\n");
      return 0;
    }
    printf("Impossible\n");
    return 0;
  }
  if (a[3] == 0) {
    if (a[1] == 0 && a[2] == 0) {
      for (register int i = 1; i <= some[0]; i++) {
        printf("0");
      }
      printf("\n");
      return 0;
    }
    if (a[1] + a[2] == some[0]) {
      for (register int i = 1; i <= a[1]; i++) {
        printf("0");
      }
      printf("1");
      for (register int i = 1; i <= a[2]; i++) {
        printf("0");
      }
      printf("\n");
      return 0;
    }
    printf("Impossible\n");
    return 0;
  }
  if (a[1] + a[2] == some[0] * some[1]) {
    while (a[1] > 0) {
      for (register int i = 1; i <= some[1] - a[1]; i++) {
        printf("1");
      }
      some[1] = (some[1] < a[1] ? some[1] : a[1]);
      printf("0");
      some[0]--;
      a[1] -= some[1];
    }
    for (register int i = 1; i <= some[1]; i++) {
      printf("1");
    }
    for (register int i = 1; i <= some[0]; i++) {
      printf("0");
    }
    return 0;
  }
  printf("Impossible\n");
  return 0;
}
