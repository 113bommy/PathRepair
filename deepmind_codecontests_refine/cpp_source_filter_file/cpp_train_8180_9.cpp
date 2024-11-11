#include <bits/stdc++.h>
using namespace std;
int n, a[6], b[6], i, j, k, m;
void sol(int x, int X, int y, int Y) {
  printf("%d %d\n", x, y);
  printf("%d %d\n", X, Y);
  printf("%d %d\n", x, Y);
  printf("%d %d\n", X, y);
}
int main() {
  scanf("%d", &n);
  if ((n & 3) == 2 || (n & 3) == 3) {
    puts("NO");
    return 0;
  }
  puts("YES");
  m = n - (n & 3);
  for (i = 1; i <= m; i += 4) {
    for (j = 0; j < 4; ++j) a[j] = i + j;
    if (n & 3) {
      printf("%d %d\n", a[2], n);
      printf("%d %d\n", a[3], n);
      printf("%d %d\n", a[1], a[3]);
      printf("%d %d\n", a[0], a[2]);
      printf("%d %d\n", a[1], n);
      printf("%d %d\n", a[0], n);
      printf("%d %d\n", a[1], a[2]);
      printf("%d %d\n", a[0], a[3]);
      printf("%d %d\n", a[2], a[3]);
      printf("%d %d\n", a[0], a[1]);
    } else {
      printf("%d %d\n", a[0], a[1]);
      printf("%d %d\n", a[2], a[3]);
      printf("%d %d\n", a[0], a[3]);
      printf("%d %d\n", a[1], a[2]);
      printf("%d %d\n", a[0], a[2]);
      printf("%d %d\n", a[1], a[3]);
    }
  }
  for (i = 1; i <= m; i += 4)
    for (j = i + 5; j <= m; j += 4) {
      sol(i, i + 1, j, j + 1);
      sol(i, i + 1, j + 2, j + 3);
      sol(i + 2, i + 3, j, j + 1);
      sol(i + 2, i + 3, j + 2, j + 3);
    }
  return 0;
}
