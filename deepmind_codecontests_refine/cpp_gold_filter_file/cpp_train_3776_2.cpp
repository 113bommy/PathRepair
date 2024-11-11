#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& x) {
  T res = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    res = (res << 3) + (res << 1) + c - '0';
    c = getchar();
  }
  x = res * f;
}
const long long N = 300000 + 10;
long long n, m, mod = 998244353, fac[N], inv[N], mx = 300000;
long long sum[N][55];
int L[N], R[N], cnt[N];
long long fpow(long long x, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return ans;
}
long long C(int x, int y) {
  if (y < 0 || x < y) return 0;
  return (fac[x] * inv[y] % mod) * inv[x - y] % mod;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  inv[n] = fpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1) % mod;
  }
}
struct node {
  int a, b;
} nod[50];
int main() {
  read(n), read(m);
  init();
  for (int i = 1; i <= n; i++)
    read(L[i]), read(R[i]), cnt[L[i]]++, cnt[R[i] + 1]--;
  for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
  for (int i = 0; i < m; i++) {
    read(nod[i].a), read(nod[i].b);
  }
  for (int i = 0; i <= 2 * m; i++)
    for (int j = 1; j <= n; j++)
      sum[j][i] = (sum[j - 1][i] + C(cnt[j] - i, j - i)) % mod;
  int mx = (1 << m) - 1;
  long long ans = 0;
  for (int i = 0; i <= mx; i++) {
    int l = 1, r = n;
    set<int> in;
    for (int j = 0; j < m; j++) {
      if ((i >> j) & 1) {
        in.insert(nod[j].a);
        in.insert(nod[j].b);
        l = max(l, L[nod[j].a]);
        l = max(l, L[nod[j].b]);
        r = min(r, R[nod[j].a]);
        r = min(r, R[nod[j].b]);
      }
    }
    int num = in.size();
    long long temp = 0;
    if (l <= r) temp = (sum[r][num] - sum[l - 1][num]) % mod;
    if (__builtin_popcount(i) & 1) {
      ans = (ans - temp) % mod;
    } else {
      ans = (ans + temp) % mod;
    }
  }
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}
