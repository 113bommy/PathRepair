#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
int mul(int x, int y) {
  long long z = 1LL * x * y;
  return z - z / mod * mod;
}
int powt(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b >>= 1;
  }
  return r;
}
int f[maxn], a[2505];
void pre_do(int n) {
  for (int i = 1, s = 0; i < 100000; i++) {
    s = add(s, powt(n - i + 1, mod - 2));
    f[i] = mul(mul(n - 1, n - i), s);
  }
}
int main() {
  int n, m, i, ans;
  scanf("%d", &n);
  for (i = m = 0; i < n; i++) {
    scanf("%d", &a[i]);
    m += a[i];
  }
  pre_do(m);
  for (i = ans = 0; i < n; i++) ans = add(ans, f[a[i]]);
  printf("%d\n", ans);
  return 0;
}
