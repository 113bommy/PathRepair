#include <bits/stdc++.h>
using namespace std;
int my_floor(int a, int b) {
  if (b == 0) return 2147483647;
  return (a + b - 1) / b;
}
bool check(int a1, int b1, int c1, int a2, int b2, int c2) {
  int t1, t2;
  t1 = (b1 - c2 > 0 ? b1 - c2 : 0);
  t2 = (b2 - c1 > 0 ? b2 - c1 : 0);
  return my_floor(a2, t1) < my_floor(a1, t2);
}
int main() {
  int a1, b1, c1, a2, b2, c2, h, a, d;
  int i, j, k, ans = 2147483647;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> h >> a >> d;
  for (i = 0; i <= 101; i++) {
    for (j = 0; j <= 201; j++) {
      for (k = 0; k <= 201; k++) {
        if (check(a1 + k, b1 + j, c1 + i, a2, b2, c2)) {
          if (h * k + a * j + d * i < ans) ans = h * k + a * j + d * i;
          break;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
