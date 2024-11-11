#include <bits/stdc++.h>
using namespace std;
int a[3], b[3], c[3];
int check(int i, int j, int k) {
  int hpy = a[0] + i, hpm = b[0];
  int aty = a[1] + j, atm = b[1];
  int dey = a[2] + k, dem = b[2];
  int decm = aty - dem;
  if (decm <= 0) return -1;
  int decy = atm - dey;
  if (decy < 0) decy = 0;
  int steps = (hpm + decm - 1) / decm;
  if (hpy - steps * decy <= 0) return -1;
  return i * c[0] + j * c[1] + k * c[2];
}
int main() {
  for (int i = 0; i < 3; ++i) scanf("%d", a + i);
  for (int i = 0; i < 3; ++i) scanf("%d", b + i);
  for (int i = 0; i < 3; ++i) scanf("%d", c + i);
  int ans = -1;
  for (int i = 0; i <= 1000; ++i) {
    for (int j = 0; j <= 1000; ++j) {
      int ll = 0, rr = 0;
      while (ll < rr) {
        int k = (ll + rr) >> 1;
        int c = check(i, j, k);
        if (c == -1)
          ll = k + 1;
        else
          rr = k;
      }
      int cost = check(i, j, ll);
      if (cost == -1) continue;
      if (ans == -1 || ans > cost) ans = cost;
    }
  }
  printf("%d\n", ans);
  return 0;
}
