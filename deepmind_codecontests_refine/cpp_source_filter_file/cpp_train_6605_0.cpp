#include <bits/stdc++.h>
using namespace std;
long long m, t, mod;
long long a[1 << 20], c[30], b[1 << 20];
long long add(long long a, long long b) {
  a += b;
  return a > mod ? a - mod : a;
}
long long sub(long long a, long long b) {
  a -= b;
  return a < 0 ? a + mod : a;
}
void tf(long long a[], int l, int r) {
  if (l + 1 == r) return;
  int len = (r - l) >> 1, mid = l + len;
  tf(a, l, mid);
  tf(a, mid, r);
  for (int i = l; i < mid; i++) {
    long long xx = a[i], yy = a[i + len];
    a[i] = add(xx, yy);
    a[i + len] = sub(xx, yy);
  }
}
void utf(long long a[], int l, int r) {
  if (l + 1 == r) return;
  int len = (r - l) >> 1, mid = l + len;
  for (int i = l; i < mid; i++) {
    long long xx = add(a[i], a[i + len]), yy = sub(a[i], a[i + len]);
    a[i] = xx, a[i + len] = yy;
  }
  utf(a, l, mid);
  utf(a, mid, r);
}
long long mul(long long a, long long b) {
  return ((a * b - (long long)((long double)a * b / mod) * mod) % mod + mod) %
         mod;
}
long long f(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) {
      ret = mul(ret, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}
int main() {
  cin >> m >> t >> mod;
  for (int i = 0; i < (1 << m); i++) {
    scanf("%I64d", &a[i]);
  }
  for (int i = 0; i <= m; i++) {
    scanf("%I64d", &c[i]);
  }
  for (int i = 0; i < (1 << m); i++) {
    b[i] = c[__builtin_popcount(i)];
  }
  m = (1 << m);
  mod = mod * m;
  for (int i = 0; i < m; i++) {
    a[i] %= mod, c[i] %= mod;
  }
  tf(a, 0, m);
  tf(b, 0, m);
  for (int i = 0; i < m; i++) {
    b[i] = f(b[i], t);
  }
  for (int i = 0; i < m; i++) {
    a[i] = mul(a[i], b[i]);
  }
  utf(a, 0, m);
  for (int i = 0; i < m; i++) {
    printf("%I64d\n", a[i] / m);
  }
  return 0;
}
