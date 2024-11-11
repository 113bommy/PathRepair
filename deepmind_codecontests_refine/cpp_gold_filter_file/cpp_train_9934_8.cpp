#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d:%d", &a, &b);
  scanf("%d:%d", &c, &d);
  if (b < d) {
    b += 60;
    a--;
  }
  b -= d;
  if (a < c) a += 24;
  a -= c;
  printf("%02d:%02d", a, b);
  return 0;
}
