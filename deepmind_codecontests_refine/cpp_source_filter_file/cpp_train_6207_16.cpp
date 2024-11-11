#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n % 2 == 0) {
    for (int i = 1; i <= n; ++i) {
      if (i % 4 == 1 || i % 4 == 2)
        printf("a");
      else
        printf("b");
    }
    puts("");
    printf("e");
    for (int i = 1; i <= n - 2; ++i) {
      if (i % 4 == 1 || i % 4 == 2)
        printf("c");
      else
        printf("d");
    }
    printf("e");
    puts("");
    printf("e");
    for (int i = 1; i <= n - 2; ++i) {
      if (i % 4 == 1 || i % 4 == 2)
        printf("d");
      else
        printf("c");
    }
    printf("e");
    puts("");
    for (int i = 1; i <= n; ++i) {
      if (i % 4 == 1 || i % 4 == 2)
        printf("a");
      else
        printf("b");
    }
  } else {
    for (int i = 1; i <= n - 1; ++i) {
      if (i % 4 == 1 || i % 4 == 2)
        printf("a");
      else
        printf("b");
    }
    printf("d");
    puts("");
    for (int i = 1; i <= n - 1; ++i) {
      if (i % 4 == 1 || i % 4 == 2)
        printf("b");
      else
        printf("a");
    }
    printf("d");
    puts("");
    printf("a");
    for (int i = 1; i <= n - 1; ++i) {
      if (i % 4 == 1 || i % 4 == 2)
        printf("c");
      else
        printf("d");
    }
    puts("");
    printf("a");
    for (int i = 1; i <= n - 1; ++i) {
      if (i % 4 == 1 || i % 4 == 2)
        printf("d");
      else
        printf("c");
    }
  }
  return 0;
}
