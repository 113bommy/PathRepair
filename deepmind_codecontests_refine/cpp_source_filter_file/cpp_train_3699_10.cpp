#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  int t, C = 1;
  while (scanf("%d", &n) != EOF) {
    int a1 = 0, a2 = 0, a3 = 0;
    char c;
    getchar();
    for (int i = 0; i < n; i++) {
      scanf("%c", &c);
      if (c == 'B') a1++;
      if (c == 'G') a2++;
      if (c == 'R') a3++;
    }
    if (a1 > 0 && a2 > 0 && a3 > 0) {
      printf("BGR\n");
      continue;
    }
    if (a1 == 0) {
      if (a2 == 0)
        printf("R\n");
      else if (a3 == 0)
        printf("G\n");
      else {
        if (a2 == 1 && a3 == 1)
          printf("B\n");
        else if (a2 == 1 && a3 > 1)
          printf("BG\n");
        else if (a2 > 1 && a3 == 1)
          printf("BR\n");
        else
          printf("BGR\n");
      }
    } else if (a2 == 0) {
      if (a3 == 0)
        printf("B\n");
      else if (a1 == 0)
        printf("R\n");
      else {
        if (a3 == 1 && a1 == 1)
          printf("G\n");
        else if (a3 == 1 && a1 > 1)
          printf("RG\n");
        else if (a3 > 1 && a1 == 1)
          printf("BG\n");
        else
          printf("BGR\n");
      }
    } else if (a3 == 0) {
      if (a1 == 0)
        printf("G\n");
      else if (a2 == 0)
        printf("B\n");
      else {
        if (a1 == 1 && a2 == 1)
          printf("R\n");
        else if (a1 == 1 && a2 > 1)
          printf("BR\n");
        else if (a1 > 1 && a2 == 1)
          printf("GR\n");
        else
          printf("BGR\n");
      }
    }
  }
  return 0;
}
