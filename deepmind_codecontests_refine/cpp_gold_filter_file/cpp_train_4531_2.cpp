#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const double PI = 3.1415926535897932384626433832795;
const double eps = 1e-5;
long long int n;
void sol() {
  long long int i = 0, j, l, r, m, x, y, t;
  scanf("%I64d", &n);
  l = 0;
  r = 1e9;
  while (r - l > 1) {
    m = (r + l) / 2;
    if (3 * m * (m + 1) > n) {
      r = m;
    } else {
      l = m;
    }
  }
  i = i;
  if (n == l * (l + 1) * 3) {
    printf("%I64d 0", (long long int)2 * (r - 1));
    return;
  }
  x = 2 * (r - 1);
  y = 0;
  n -= r * (r - 1) * 3;
  i = i;
  t = min((long long int)1, n);
  n -= t;
  x += t;
  y += 2 * t;
  t = min((long long int)r - 1, n);
  n -= t;
  x -= t;
  y += 2 * t;
  t = min((long long int)r, n);
  n -= t;
  x -= 2 * t;
  t = min((long long int)r, n);
  n -= t;
  x -= t;
  y -= 2 * t;
  t = min((long long int)r, n);
  n -= t;
  x += t;
  y -= 2 * t;
  t = min((long long int)r, n);
  n -= t;
  x += 2 * t;
  t = min((long long int)r, n);
  n -= t;
  x += t;
  y += 2 * t;
  printf("%I64d %I64d", x, y);
}
int main() {
#pragma comment(linker, "/STACK:268435456")
  sol();
  return 0;
}
