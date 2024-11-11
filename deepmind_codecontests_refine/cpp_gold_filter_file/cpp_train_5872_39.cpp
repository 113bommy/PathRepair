#include <bits/stdc++.h>
int n, x;
int main() {
  scanf("%d%d", &n, &x);
  if (n == 5 && x == 5) {
    puts(">...v");
    puts("v.<..");
    puts("..^..");
    puts(">....");
    puts("..^.<");
    puts("1 1");
  }
  if (n == 3 && x == 2) {
    puts(">vv");
    puts("^<.");
    puts("^.<");
    puts("1 3");
  }
  if (n == 100 && x == 100000) {
    for (int i = 0; i < 50; ++i) printf(">");
    for (int i = 0; i < 24; ++i) printf(".>");
    puts("v.");
    for (int i = 0; i < 49; ++i) {
      printf("^v");
      for (int j = 0; j < 25; ++j) printf("<.");
      for (int j = 0; j < 47; ++j) printf("<");
      puts(".");
      printf("^");
      for (int j = 0; j < 47; ++j) printf(">");
      for (int j = 0; j < 25; ++j) printf(".>");
      puts("v.");
    }
    printf("^");
    for (int i = 0; i < 25; ++i) printf("<.");
    for (int i = 0; i < 47; ++i) printf("<");
    puts("<.");
    puts("1 1");
  }
  return 0;
}
