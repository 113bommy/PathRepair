#include <bits/stdc++.h>
using namespace std;
bool debug;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
long long x1, x2, a, b;
bool odwr;
int main(int argc, char* argv[]) {
  debug = argc > 1;
  scanf("%lld%lld%lld%lld", &x1, &x2, &a, &b);
  if (x1 > x2) {
    odwr = true;
    x1 = -x1;
    x2 = -x2;
    a = -a;
    b = -b;
    swap(a, b);
  }
  if (x1 + b >= x2 && x1 + a <= x2) {
    puts("FIRST");
    if (odwr)
      printf("%lld\n", -x2);
    else
      printf("%lld\n", x2);
    return 0;
  }
  if (a <= 0) {
    puts("DRAW");
    return 0;
  }
  int roz = x2 - x1;
  int mod = (roz - 1) % (a + b);
  if (mod < a - 1) puts("DRAW");
  if (mod >= a - 1 && mod <= b - 1) {
    puts("FIRST");
    if (odwr)
      printf("%lld\n", -(x1 + (roz % (b + a))));
    else
      printf("%lld\n", x1 + (roz % (b + a)));
  }
  if (mod > b && mod < a + b - 1) puts("DRAW");
  if (mod == a + b - 1) puts("SECOND");
  return 0;
}
