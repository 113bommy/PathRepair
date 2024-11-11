#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b;
int res(long long x, long long y) {
  assert(x <= y);
  if (x == 0) return 0;
  if (!res(y % x, x)) {
    return 1;
  }
  assert(x > 1);
  long long z = y / x, sum = 0;
  if (x & 1)
    return 1 - z % 2;
  else
    return 1 - (z % (x + 1)) % 2;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &a, &b);
    if (a > b) swap(a, b);
    printf("%s\n", res(a, b) ? "First" : "Second");
  }
  return 0;
}
