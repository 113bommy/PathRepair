#include <bits/stdc++.h>
using namespace std;
int sure(long long bx, long by, long long cx, long long cy) {
  long long x = bx * cy - by * cx;
  long long y = bx * cx + by * cy;
  long long z = cx * cx + cy * cy;
  if (!z)
    return !bx && !by;
  else
    return (x % z == 0) && (y % z == 0);
}
int main() {
  long long ax, ay, bx, by, cx, cy;
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;
  int flag = 0;
  for (int i = 0; i < 4; i++) {
    swap(ax, ay);
    ax = -ax;
    if (sure(bx - ax, by - ay, cx, cy)) flag = 1;
  }
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
