#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int MAXI = 2 << 29;
int n, m, a[2];
int gcd(int a, int b) {
  if (a < 0) gcd(-a, b);
  if (b < 0) gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
int main() {
  scanf("%d%d%d", &a[0], &a[1], &n);
  while (n -= gcd(a[m], n)) m ^= 1;
  printf("%d", m);
}
