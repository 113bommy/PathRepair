#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5, L = 1e6;
long long n, m, p, X, Y, s;
long long prime[L], pb[L];
long long a[N], b[20][3], c[N], d[N];
long long cal(long long x, long long y) {
  long long c = 0;
  while (x % y == 0) {
    c++;
    x /= y;
  }
  return c;
}
void get_Prime() {
  long long i = 2, j;
  while (i < L) {
    if (!pb[i]) {
      prime[p++] = i;
      for (j = 2 * i; j < L; j += i) pb[j] = 1;
    }
    i++;
  }
}
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
void add_prime(long long v, long long &ty) {
  long long c1 = 0, c2 = 0;
  long long tx = X;
  while (tx % v == 0) {
    c1++;
    tx /= v;
  }
  while (ty % v == 0) {
    c2++;
    ty /= v;
  }
  if (c1 == c2) return;
  b[m][0] = v;
  b[m][1] = c1;
  b[m][2] = c2;
  m++;
}
void factorial() {
  long long i, ty = Y;
  for (i = 0; i < p; i++)
    if (ty % prime[i] == 0) add_prime(prime[i], ty);
  if (ty > 1) {
    long long t;
    for (i = 0; i < n; i++) {
      t = gcd(a[i], ty);
      if (t > 1 && t < ty) {
        add_prime(t, ty);
        break;
      }
    }
    if (ty > 1) add_prime(ty, ty);
  }
}
int main() {
  long long i, j, z;
  get_Prime();
  scanf("%I64d%I64d%I64d", &n, &X, &Y);
  for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
  factorial();
  for (i = 0; i < n; i++) {
    if (a[i] % X > 0) continue;
    z = 0;
    for (j = 0; j < m; j++)
      if (cal(a[i], b[j][0]) == b[j][1]) z += (1 << j);
    c[z]++;
  }
  for (i = 0; i < m; i++)
    for (z = 0; z < (1 << m); z++)
      if ((z >> i) & 1) c[z] += c[z - (1 << i)];
  if (Y % X == 0)
    for (i = 0; i < n; i++) {
      if (Y % a[i] > 0) continue;
      z = 0;
      for (j = 0; j < m; j++)
        if (cal(a[i], b[j][0]) == b[j][2]) z += (1 << j);
      s += c[z];
    }
  printf("%I64d\n", s);
  return 0;
}
