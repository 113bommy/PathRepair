#include <bits/stdc++.h>
using namespace std;
int main() {
  bool a[9][9];
  for (int i = 1; i <= 8; i++) {
    int j;
    if (i % 2 == 0) {
      j = 2;
    } else {
      j = 1;
    }
    for (; j <= 8; j += 2) {
      a[i][j] = true;
    }
  }
  int r1, c1, r2, c2;
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
  if (r1 == r2 || c1 == c2) {
    printf("%d ", 1);
  } else {
    printf("%d ", 2);
  }
  if (a[r1][c1] == a[r2][c2]) {
    if ((r1 + c1) == (r2 + c2) || (r1 - c1) == (r2 - c2)) {
      printf("%d ", 1);
    } else {
      printf("%d ", 2);
    }
  } else {
    printf("%d ", 0);
  }
  int len1 = c2 - c1;
  int len2 = r2 - r1;
  if (len1 < 0) len1 = -len1;
  if (len2 < 0) len2 = -len2;
  int len = len1 > len2 ? len1 : len2;
  printf("%d", len);
  return 0;
}
