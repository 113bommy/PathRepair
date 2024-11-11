#include <bits/stdc++.h>
long long a[1050000], b[1050000], B[1050000], p, t;
int n, m;
int read() {
  int ans = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  return ans;
}
int count(int x) {
  int ans = 0;
  while (x) {
    ans += (x & 1);
    x >>= 1;
  }
  return ans;
}
long long ADD(long long x) {
  if (x >= p)
    return x - p;
  else if (x < 0)
    return x + p;
  else
    return x;
}
void FWT(long long *a, int flag) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += (i << 1))
      for (int k = 0; k < i; k++) {
        long long x = a[j + k], y = a[j + k + i];
        a[j + k] = ADD(x + y);
        a[j + k + i] = ADD(x - y);
      }
  if (flag == -1)
    for (int i = 0; i < n; i++) a[i] /= n;
}
long long Mod(long long a, long long b, long long mod) {
  return ((a * b - (long long)((long double)a / mod * b) * mod) % mod + mod) %
         mod;
}
long long calc(long long a, long long b, long long mod) {
  long long ans = 1, t = a;
  for (; b; b >>= 1) {
    if (b & 1) ans = Mod(ans, t, mod);
    t = Mod(t, t, mod);
  }
  return ans;
}
int main() {
  scanf("%d%lld%lld", &m, &t, &p);
  n = (1 << m);
  p <<= m;
  for (int i = 0; i < n; i++) a[i] = read();
  for (int i = 0; i <= m; i++) B[i] = read();
  for (int i = 0; i < n; i++) b[i] = B[count(i)];
  FWT(a, 1);
  FWT(b, 1);
  for (int i = 0; i < n; i++) a[i] = Mod(calc(b[i], t, p), a[i], p);
  FWT(a, -1);
  p >>= m;
  for (int i = 0; i < n; i++) printf("%lld\n", a[i] % p);
  return 0;
}
