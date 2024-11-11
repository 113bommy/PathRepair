#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e5 + 10;
const long long mo = 1e9 + 7;
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, x, y);
  long long t = x;
  x = y;
  y = t - a / b * y;
  return g;
}
long long mp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2) ans = ans * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return ans;
}
int main() {
  long long i, j, m, n, k, b[10] = {0};
  char a[10];
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", a);
    if (a[0] == 'p') {
      b[0] = 1;
    } else if (a[0] == 'g') {
      b[1] = 1;
    } else if (a[0] == 'b')
      b[2] = 1;
    else if (a[0] == 'o')
      b[3] = 1;
    else if (a[0] == 'r')
      b[4] = 1;
    else if (a[0] == 'y')
      b[5] = 1;
  }
  printf("%lld\n", 6 - n);
  if (b[0] == 0) printf("Power\n");
  if (b[1] == 0) printf("Time\n");
  if (b[2] == 0) printf("Space\n");
  if (b[3] == 0) printf("Sour\n");
  if (b[4] == 0) printf("Reality\n");
  if (b[5] == 0) printf("Mind\n");
  return 0;
}
