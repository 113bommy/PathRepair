#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, f1, f2, q;
  scanf("%d%d", &a, &b);
  if (a == b) {
    f1 = a;
    f2 = 0;
  }
  if (a > b) {
    q = a;
    a = b;
    b = q;
  }
  f1 = a;
  f2 = (b - a) / 2;
  printf("%d %d\n", f1, f2);
}
