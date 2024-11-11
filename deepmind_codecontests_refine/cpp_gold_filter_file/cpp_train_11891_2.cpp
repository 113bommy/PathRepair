#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
int n, m, k, P[1010];
int exgcd(int a, int b, int *x, int *y) {
  if (!a) {
    *x = 0;
    *y = 1;
    return b;
  }
  int x1, y1, gcd = exgcd(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
int cal(int x, int y) {
  if (x > y) return 0;
  int a, b, gcd = exgcd((1LL * P[y - x] * P[x]) % oo, oo, &a, &b);
  int t1 = P[y], t2 = (a + oo) % oo;
  return (1LL * t1 * t2) % oo;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  P[0] = 1;
  for (int i = 1; i <= 1010 - 1; i++) P[i] = (1LL * P[i - 1] * i) % oo;
  printf("%d", (1LL * cal(2 * k, n - 1) * cal(2 * k, m - 1)) % oo);
  return 0;
}
