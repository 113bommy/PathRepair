#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0 || b == 0) {
    return a + b;
  }
  if (a > b) {
    return gcd(a % b, b);
  }
  return gcd(a, b % a);
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%d\n", (5 + (n - 1) * 6) * k);
  for (int i = 0; i < n; ++i) {
    printf("%d %d %d %d\n", 6 * i * k + k, 6 * i * k + 2 * k, 6 * i * k + 3 * k,
           6 * i * k + 5 * k);
  }
  return 0;
}
