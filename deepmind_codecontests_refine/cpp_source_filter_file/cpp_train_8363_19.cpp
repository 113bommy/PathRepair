#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
int n, m, c3, c4, c5, ans = inf, s, pos1, pos2, pos3;
void read(int &x) {
  char s = getchar();
  x = 0;
  while (s < '0' || s > '9') s = getchar();
  while (s >= '0' && s <= '9') x = (x << 3) + (x << 1) + s - 48, s = getchar();
}
int f(int a, int b, int c, int x, int y, int z) {
  return abs(a * x - b * y) + abs(b * y - c * z);
}
int main() {
  read(n);
  read(s);
  for (int i = 1; i <= n; i++) {
    int x;
    read(x);
    if (x == 3)
      c3++;
    else if (x == 4)
      c4++;
    else
      c5++;
  }
  for (int k3 = s / n; k3 >= 0; k3--) {
    for (int k4 = (s - k3 * c3) / (n - c3); k4 >= k3; k4--) {
      int k5 = (s - c3 * k3 - c4 * k4) / c5, tmp;
      if (abs(k5 * c5 - k4 * c4) >= ans) break;
      tmp = f(c3, c4, c5, k3, k4, k5);
      if (k3 * c3 + k4 * c4 + k5 * c5 == s && tmp < ans) {
        ans = tmp;
        pos1 = k3;
        pos2 = k4;
        pos3 = k5;
      }
    }
  }
  if (ans != inf)
    printf("%d %d %d", pos1, pos2, pos3);
  else
    printf("-1");
  return 0;
}
