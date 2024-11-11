#include <bits/stdc++.h>
using namespace std;
long long int n, m, c;
int d1[1111111][30], i, g, x, y;
char a[1111111], b[1111111];
int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }
int main() {
  scanf("%I64d%I64d%s%s", &n, &m, &a, &b);
  x = strlen(a);
  y = strlen(b);
  g = gcd(x, y);
  long long int l = 1LL * x * y / g;
  for (i = 0; i < x; i++) d1[i % g][a[i] - 'a']++;
  for (i = 0; i < y; i++) c += d1[i % g][b[i] - 'a'];
  printf("%I64d", n * x - c * (n * x / l));
  return 0;
}
