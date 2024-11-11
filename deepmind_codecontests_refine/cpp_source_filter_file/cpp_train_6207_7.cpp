#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n == 1)
    printf("x\nx\ny\n\y");
  else if (n % 2 == 0) {
    for (int j = 1; j < n; j += 2) {
      if (j % 4 == 1)
        printf("aa");
      else
        printf("bb");
    }
    printf("\nx");
    for (int j = 1; j < n - 2; j += 2) {
      if (j % 4 == 3)
        printf("cc");
      else
        printf("dd");
    }
    printf("y\nx");
    for (int j = 1; j < n - 2; j += 2) {
      if (j % 4 == 1)
        printf("aa");
      else
        printf("bb");
    }
    printf("y\n");
    for (int j = 1; j < n; j += 2) {
      if (j % 4 == 3)
        printf("cc");
      else
        printf("dd");
    }
    printf("\n");
  } else {
    for (int j = 1; j < n; j += 2) {
      if (j % 4 == 1)
        printf("aa");
      else
        printf("bb");
    }
    printf("y\n");
    for (int j = 1; j < n; j += 2) {
      if (j % 4 == 3)
        printf("aa");
      else
        printf("bb");
    }
    printf("y\nx");
    for (int j = 1; j < n; j += 2) {
      if (j % 4 == 1)
        printf("aa");
      else
        printf("bb");
    }
    printf("\nx");
    for (int j = 1; j < n; j += 2) {
      if (j % 4 == 3)
        printf("aa");
      else
        printf("bb");
    }
    printf("\n");
  }
  return 0;
}
