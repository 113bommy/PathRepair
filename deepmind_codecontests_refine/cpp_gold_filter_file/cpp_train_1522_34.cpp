#include <bits/stdc++.h>
using namespace std;
int isprime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
int cal(int x, int p) {
  if (!isprime(p)) return 0;
  if (x < p) return 0;
  int res = x /= p;
  for (int i = 2; i < p && i <= x; i++) {
    res -= cal(x, i);
  }
  return res;
}
int main() {
  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);
  printf("%d", cal(b, k) - cal(a - 1, k));
  return 0;
}
