#include <bits/stdc++.h>
using namespace std;
void func(void) {
  freopen("input.c", "r", stdin);
  freopen("output.c", "w", stdout);
}
int fg = 0, bd1, bd2, bd3;
void findBond(int x, int y, int z, int &bond1, int &bond2, int &bond3) {
  int y1 = y, z1 = z;
  while (1) {
    if (x == y1 + z1) {
      bond2 = y - y1;
      bond1 = y1;
      bond3 = x - y1;
      fg = 1;
      break;
    }
    y1--;
    z1--;
    if (y1 < 0 || z1 < 0) break;
  }
}
int main() {
  long long n, q, i, j = 0, temp, t, k, ans = 0, sum = 0, cnt = 0, m, x, y,
                     mx = 0, mx1 = 0, mn = 10000000000000000,
                     mn1 = 10000000000000000;
  int a[3];
  for (int i = 0; i < 3; i++) cin >> a[i];
  if (a[0] <= a[1] and a[0] <= a[2]) {
    findBond(a[0], a[1], a[2], bd1, bd2, bd3);
  } else if (a[1] <= a[0] and a[1] <= a[2])
    findBond(a[1], a[0], a[2], bd2, bd1, bd3);
  else
    findBond(a[2], a[1], a[0], bd3, bd2, bd1);
  if (fg)
    cout << bd1 << " " << bd2 << " " << bd3 << endl;
  else
    cout << "Impossible\n";
  return 0;
}
