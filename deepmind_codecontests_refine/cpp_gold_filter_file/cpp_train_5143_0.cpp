#include <bits/stdc++.h>
using namespace std;
bool judge(double a, double b) {
  if (abs(a - b) < 1e-9) return true;
  return false;
}
int main() {
  int a, b, c, d;
  double f;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if ((b - a == c - b && d - c == c - b))
    printf("%d\n", d * 2 - c);
  else {
    if (a == 0 || a == b) {
      printf("42\n");
      return 0;
    }
    f = double(b) / double(a);
    if (judge((f * double(b)), c) & judge(f * double(c), d)) {
      if (judge(double(int(f * double(d))), f * double(d)))
        printf("%d\n", int(f * double(d)));
      else
        printf("42\n");
    } else
      printf("42\n");
  }
}
