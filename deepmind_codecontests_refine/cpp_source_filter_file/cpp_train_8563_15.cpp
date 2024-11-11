#include <bits/stdc++.h>
using namespace std;
int a;
int main() {
  scanf("%d", &a);
  long long q = 0;
  for (int s = (2); s < (a); s++) {
    int x = a;
    while (x) {
      q += x % s;
      x /= s;
    }
  }
  long long x = q, y = a - 2;
  if (x < y) swap(x, y);
  while (y) {
    x %= y;
    swap(x, y);
  }
  printf("%Ld/%d", q / x, (a - 2) / x);
}
