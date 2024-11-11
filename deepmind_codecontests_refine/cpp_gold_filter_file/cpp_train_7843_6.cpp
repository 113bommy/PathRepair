#include <bits/stdc++.h>
using namespace std;
int aaa(int x, int y) {
  int y1, x1;
  while (x != 0) {
    y1 = y;
    x1 = x % 10;
    while (y1 != 0) {
      if (x1 == y1 % 10) return 1;
      y1 /= 10;
    }
    x /= 10;
  }
  return 0;
}
int main() {
  int x, i, o;
  while (~scanf("%d", &x)) {
    o = 0;
    for (i = 1; i <= sqrt(x); i++) {
      if (x % i == 0) {
        o += aaa(x, i);
        if (x / i != i) o += aaa(x, x / i);
      }
    }
    printf("%d\n", o);
  }
  return 0;
}
