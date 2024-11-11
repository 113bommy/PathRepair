#include <bits/stdc++.h>
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return ((a * b) / gcd(a, b)); }
using namespace std;
int main() {
  int a, b, c, i, j, k, tc, t;
  int n, m, cnt = 0;
  printf("2000\n");
  for (i = 1; i <= 1000; i++) {
    printf("%d %d %d %d\n", i, 1, i, 2);
  }
  for (i = 1000; i >= 1; i--) {
    printf("%d %d %d %d\n", i, 1, i, 2);
  }
  return 0;
}
