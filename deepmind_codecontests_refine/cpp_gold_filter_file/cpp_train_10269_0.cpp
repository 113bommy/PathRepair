#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 99;
int n, m, a[N], phi[35];
int getphi(int x) {
  int ret = x;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      ret = ret / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  if (x > 1) ret = ret / x * (x - 1);
  return ret;
}
int qpow(long long a, int b, int mod) {
  long long ret = 1;
  while (b) {
    if (b % 2) {
      ret = ret * a;
      if (ret >= mod) ret = ret % mod + mod;
    }
    a = a * a;
    if (a >= mod) a = a % mod + mod;
    b /= 2;
  }
  return ret;
}
int dfs(int l, int r, int i) {
  if (l == r || phi[i] == 1)
    return a[l] >= phi[i] ? a[l] % phi[i] + phi[i] : a[l];
  return qpow(a[l], dfs(l + 1, r, i + 1), phi[i]);
}
int main() {
  scanf("%d%d", &n, &m);
  phi[0] = m;
  for (int i = 1; i < 30; i++) phi[i] = getphi(phi[i - 1]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int Q, l, r;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d", &l, &r);
    printf("%lld\n", dfs(l, r, 0) % m);
  }
}
