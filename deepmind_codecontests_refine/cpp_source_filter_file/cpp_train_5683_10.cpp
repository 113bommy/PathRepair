#include <bits/stdc++.h>
int n, a[200003];
char s[200003];
int M, t;
int ksm(int p, int x) {
  int s = 1;
  while (x) {
    if (x & 1) s = 1ll * s * p % M;
    p = 1ll * p * p % M;
    x >>= 1;
  }
  return s;
}
int Min(const int p, const int q) { return p < q ? p : q; }
int main() {
  scanf("%s %d", s + 1, &M);
  n = strlen(s + 1);
  int i;
  for (i = 1; i <= n; ++i)
    a[i] = s[i] ^ 48, t = ((t << 3) + (t << 1) + a[i]) % M;
  int mn = t, k = ksm(10, n + 1);
  for (i = 1; i <= n; ++i) {
    t = ((t << 3) + (t << 1)) % M;
    t = (t - 1ll * k * a[i] % M + M) % M;
    t = (t + a[i]) % M;
    if (a[i + 1]) mn = Min(mn, t);
  }
  printf("%d\n", mn);
  return 0;
}
