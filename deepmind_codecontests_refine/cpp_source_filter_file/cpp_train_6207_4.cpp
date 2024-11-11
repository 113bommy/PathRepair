#include <bits/stdc++.h>
int main() {
  int n, i;
  scanf("%d", &n);
  if (n == 1) {
    printf("a\na\nb\nb\n");
    return 0;
  }
  if (n == 2) {
    printf("aa\nbb\naa\nbb\n");
    return 0;
  }
  if (n % 2 == 0) {
    for (i = 0; i < n / 2; i++) printf(i % 2 ? "bb" : "aa");
    printf("\n");
    printf("b");
    for (i = 1; i < n / 2; i++) printf(i % 2 ? "dd" : "cc");
    printf((n % 4) ? "b\n" : "a\n");
    printf("b");
    for (i = 1; i < n / 2; i++) printf(i % 2 ? "cc" : "dd");
    printf((n % 4) ? "b\n" : "a\n");
    for (i = 0; i < n / 2; i++) printf(i % 2 ? "bb" : "aa");
    printf("\n");
    return 0;
  }
  for (i = 0; i < n / 2; i++) printf(i % 2 ? "bb" : "aa");
  printf("c\n");
  for (i = 0; i < n / 2; i++) printf(i % 2 ? "aa" : "bb");
  printf("c\n");
  printf("c");
  for (i = 0; i < n / 2; i++) printf(i % 2 ? "bb" : "aa");
  printf("\n");
  printf("c");
  for (i = 0; i < n / 2; i++) printf(i % 2 ? "aa" : "bb");
  printf("\n");
  return 0;
}
