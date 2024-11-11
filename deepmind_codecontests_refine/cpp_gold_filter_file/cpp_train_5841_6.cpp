#include <bits/stdc++.h>
using namespace std;
int n;
int ax, ay, bx, by, cx, cy;
int main(void) {
  cin >> n;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  bx -= ax;
  by -= ay;
  cx -= ax;
  cy -= ay;
  if (bx * cx > 0 && by * cy > 0) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
