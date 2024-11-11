#include <bits/stdc++.h>
using namespace std;
int n, l, r;
bool prime(int x) {
  if (x == 1) {
    return 0;
  }
  if (x == 2) {
    return 1;
  }
  for (int i = 2; i * i <= x; ++i) {
    if ((x % i) == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  l = 2, r = n - 2;
  while (prime(l) || prime(r)) {
    ++l, --r;
  }
  printf("%d %d\n", l, r);
  return 0;
}
