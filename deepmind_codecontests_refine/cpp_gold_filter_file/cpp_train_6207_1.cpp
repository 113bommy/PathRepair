#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("a");
    puts("a");
    puts("b");
    puts("b");
  } else if (n == 2) {
    puts("aa");
    puts("bb");
    puts("aa");
    puts("bb");
  } else {
    int i, c;
    for (c = 0, i = n; i >= 2; i -= 2, c++, c %= 2)
      (!c) ? printf("aa") : printf("bb");
    if (i) printf("e");
    printf("\n");
    for (c = 0, i = n; i >= 2; i -= 2, c++, c %= 2)
      (!c) ? printf("cc") : printf("dd");
    if (i) printf("e");
    printf("\n");
    printf("x");
    for (c = 0, i = n - 1; i >= 2; i -= 2, c++, c %= 2)
      (!c) ? printf("qq") : printf("ww");
    if (i) printf("y");
    printf("\n");
    printf("x");
    for (c = 0, i = n - 1; i >= 2; i -= 2, c++, c %= 2)
      (!c) ? printf("rr") : printf("tt");
    if (i) printf("y");
    printf("\n");
  }
  return 0;
}
