#include <bits/stdc++.h>
using namespace std;
int abs(int x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  int a, b, w1 = 0, d = 0, w2 = 0;
  scanf("%d %d", &a, &b);
  for (int i = 0; i < 6; i++) {
    if (abs(a - i) < abs(b - i))
      w1++;
    else if (abs(a - i) == abs(b - i))
      d++;
  }
  w2 = 6 - w1 - d;
  printf("%d %d %d\n", w1, d, w2);
  return 0;
}
