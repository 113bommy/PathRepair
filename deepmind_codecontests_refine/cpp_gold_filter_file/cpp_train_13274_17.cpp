#include <bits/stdc++.h>
using namespace std;
int a[600][600];
int n;
void build(int x) {
  int y = x >> 1;
  for (int i = 1; i <= y; ++i) {
    for (int j = 1; j <= y; ++j) {
      a[i + y][j] = a[i][j + y] = a[i][j];
      a[i + y][j + y] = -a[i][j];
    }
  }
}
int main() {
  cin >> n;
  if (!n) {
    puts("+");
    return 0;
  }
  a[1][1] = 1;
  build(n);
  for (int i = 1; i <= n; ++i) build(1 << i);
  int x = 1 << n;
  for (int i = 1; i <= x; ++i) {
    for (int j = 1; j <= x; ++j)
      if (a[i][j] > 0)
        putchar('+');
      else
        putchar('*');
    puts("");
  }
}
