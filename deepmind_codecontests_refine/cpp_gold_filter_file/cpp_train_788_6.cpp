#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
inline int power(int a, int b) {
  int out = 1;
  while (b) {
    if (b & 1) out = mult(out, a);
    a = mult(a, a);
    b >>= 1;
  }
  return out;
}
inline int dec(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
int n, a[200010], tmp[200010], fac[200010], ifac[200010];
inline int C(int a, int b) {
  if (a < b) return 0;
  return mult(fac[a], mult(ifac[b], ifac[a - b]));
}
int main() {
  scanf("%d", &n);
  fac[0] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    fac[i + 1] = mult(fac[i], i + 1);
  }
  if (n == 1) {
    printf("%d\n", a[0]);
    return 0;
  }
  ifac[n] = power(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) ifac[i] = mult(ifac[i + 1], i + 1);
  if (n & 1) {
    for (int i = 0; i < n - 1; i++) {
      if (!(i & 1))
        tmp[i] = add(a[i], a[i + 1]);
      else
        tmp[i] = dec(a[i], a[i + 1]);
    }
    for (int i = 0; i < n - 1; i++) a[i] = tmp[i];
    a[n - 1] = 0;
    n--;
  }
  tmp[0] = tmp[1] = 0;
  for (int i = 0; i < n / 2; i++)
    tmp[0] = add(tmp[0], mult(a[i << 1], C(n / 2 - 1, i))),
    tmp[1] = add(tmp[1], mult(a[(i << 1) | 1], C(n / 2 - 1, i)));
  if ((1ll * n * (n - 1) / 2) % 2 == 0)
    printf("%d\n", dec(tmp[0], tmp[1]));
  else
    printf("%d\n", add(tmp[0], tmp[1]));
  return 0;
}
