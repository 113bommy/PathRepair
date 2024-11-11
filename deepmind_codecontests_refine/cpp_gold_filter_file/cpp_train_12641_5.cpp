#include <bits/stdc++.h>
using namespace std;
void rot(int &a, int &b, int n, int m) {
  int x = b, y = n - a + 1;
  a = x, b = y;
}
void rot(int &a, int &b, int n, int m, int flag) {
  int x = m - b + 1, y = a;
  a = x, b = y;
}
int main() {
  int n, m, x, y, z, p, i, j, k;
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);
  x %= 4, y %= 2, z %= 4;
  int f1 = n, f2 = m;
  for (i = 1; i <= p; i++) {
    int a, b;
    n = f1, m = f2;
    scanf("%d%d", &a, &b);
    for (j = 1; j <= x; j++) {
      rot(a, b, n, m);
      swap(n, m);
    }
    if (y) b = m - b + 1;
    for (j = 1; j <= z; j++) {
      rot(a, b, n, m, 1);
      swap(n, m);
    }
    printf("%d %d\n", a, b);
  }
  return 0;
}
