#include <bits/stdc++.h>
using namespace std;
const int a[10][10] = {{0},
                       {1},
                       {1},
                       {1},
                       {0, 0, 2, 1, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                       {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 3, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 1, 2, 0, 0, 0, 1, 0, 0}};
int n, b[10];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char c;
    while ((c = getchar()) && (c < '0'))
      ;
    c -= '0';
    if (c == 0) continue;
    if (c == 1) continue;
    if (c == 2) {
      b[2]++;
      continue;
    }
    if (c == 3) {
      b[3]++;
      continue;
    } else {
      for (int i = 0; i <= 9; i++) b[i] += a[c][i];
    }
  }
  for (int i = 9; i >= 2; i--) {
    while (b[i] > 0) {
      b[i]--;
      printf("%d", i);
    }
  }
  printf("\n");
  return 0;
}
