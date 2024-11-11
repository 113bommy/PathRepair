#include <bits/stdc++.h>
using namespace std;
map<int, int> b;
int n, k, tot, inv[2100000], fac[2100000], l[2100000], r[2100000], a[2100000],
    c[2100000], d[2100000];
long long quick(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return ret;
}
long long C(int n, int m) {
  return 1ll * fac[n] * inv[m] % 1000000007 * inv[n - m] % 1000000007;
}
int main() {
  inv[0] = 1;
  fac[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    fac[i] = 1ll * fac[i - 1] * i % 1000000007;
    inv[i] = quick(fac[i], 1000000007 - 2);
  }
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    a[++a[0]] = l[i];
    a[++a[0]] = r[i];
  }
  sort(a + 1, a + a[0] + 1);
  a[0] = unique(a + 1, a + a[0] + 1) - (a + 1);
  for (int i = 1; i <= a[0]; i++) {
    if (i > 1 && a[i] - a[i - 1] - 1 > 0) {
      ++tot;
      c[tot] = a[i] - a[i - 1] - 1;
    }
    b[a[i]] = ++tot;
    c[tot] = 1;
  }
  for (int i = 1; i <= n; i++) {
    d[b[l[i]]]++;
    d[b[r[i]] + 1]--;
  }
  long long ans = 0;
  int ret = 0;
  for (int i = 1; i <= tot; i++) {
    ret += d[i];
    if (ret >= k)
      ans = (ans + 1ll * c[i] * C(ret, k) % 1000000007) % 1000000007;
  }
  cout << ans;
  return 0;
}
