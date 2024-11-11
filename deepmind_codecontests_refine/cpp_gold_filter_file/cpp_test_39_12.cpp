#include <bits/stdc++.h>
using namespace std;
int n, d[110], an, maxx;
int main() {
  scanf("%d", &n);
  for (int c = 2; c <= n; c++) {
    printf("? ");
    for (int j = 1; j <= n - 1; j++) printf("%d ", c);
    printf("1");
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == 0) {
      an = c - 1;
      break;
    }
    d[x] = -(c - 1);
  }
  for (int c = 2; c <= n; c++) {
    printf("? ");
    for (int j = 1; j <= n - 1; j++) printf("%d ", 1);
    printf("%d ", c);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == 0) {
      an = n + 2 - c;
      break;
    }
    d[x] = c - 1;
  }
  printf("! ");
  for (int i = 1; i <= n - 1; i++) {
    printf("%d ", an + d[i]);
  }
  printf("%d ", an);
}
