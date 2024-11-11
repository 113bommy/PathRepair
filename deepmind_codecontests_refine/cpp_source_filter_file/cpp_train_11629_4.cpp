#include <bits/stdc++.h>
using namespace std;
int n, k;
const int Q = 1 << 17;
vector<int> g[Q];
int si[Q], f[Q], sm[Q];
const int MOD = 998244353;
inline int add(int a, int b) {
  a += b;
  return a >= MOD ? a - MOD : a;
}
inline int sub(int a, int b) {
  a -= b;
  return a < 0 ? a + MOD : a;
}
inline int mul(int a, int b) { return 1LL * a * b % MOD; }
inline void Add(int &a, int b) {
  a += b;
  a >= MOD ? a -= MOD : 1;
}
inline void Sub(int &a, int b) {
  a -= b;
  a < 0 ? a += MOD : 1;
}
inline void Mul(int &a, int b) { a = 1LL * a * b % MOD; }
int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, Mul(a, a))
    if (b & 1) Mul(ans, a);
  return ans;
}
int w[Q];
void NTT(int a[], int n, int ty) {
  for (int i = 0, j = 0; i < n; i++) {
    if (i < j) swap(a[i], a[j]);
    for (int l = n >> 1; (j ^= l) < l; l >>= 1)
      ;
  }
  w[0] = 1;
  for (int m = 1; m < n; m <<= 1) {
    int owo = ksm(3, (MOD - 1) / (m << 1) * ty + MOD - 1);
    for (int i = 1; i < m; i++) w[i] = mul(w[i - 1], owo);
    for (int i = 0; i < n; i += (m << 1))
      for (int j = 0; j < m; j++) {
        int p = a[i + j], q = mul(w[j], a[i + j + m]);
        a[i + j] = add(p, q), a[i + j + m] = sub(p, q);
      }
  }
  if (ty < 0) {
    int inv = ksm(n, MOD - 2);
    for (int i = 0; i < n; i++) Mul(a[i], inv);
  }
}
int als = 0;
int lim[Q];
int ta[Q], tb[Q];
int tc[Q], td[Q];
int buf1[Q], buf2[Q];
void Pi(int l, int len) {
  if (len == 1) return;
  int mid = len >> 1, med = len - mid, r = l + (mid << 1);
  Pi(l, mid), Pi(r, med);
  for (int i = 0; i <= mid; i++) ta[i] = buf1[i + l], tc[i] = buf2[i + l];
  for (int i = 0; i <= med; i++) tb[i] = buf1[i + r], td[i] = buf2[i + r];
  int maxn = lim[len];
  if (mid < maxn) fill(ta + mid + 1, ta + maxn, 0);
  if (med < maxn) fill(tb + med + 1, tb + maxn, 0);
  if (mid >= maxn) printf("%d %d WDNMD\n", mid, maxn);
  if (mid < maxn) fill(tc + mid, tc + maxn, 0);
  if (med < maxn) fill(td + med, td + maxn, 0);
  NTT(ta, maxn, 1), NTT(tb, maxn, 1);
  NTT(tc, maxn, 1), NTT(td, maxn, 1);
  if (maxn > (len << 1)) cerr << "WCNMCNCMNCM\n";
  for (int i = 0; i < maxn; i++)
    buf1[i + l] = mul(ta[i], tb[i]),
             buf2[i + l] = add(mul(ta[i], td[i]), mul(tb[i], tc[i]));
  NTT(buf1 + l, maxn, -1);
  NTT(buf2 + l, maxn, -1);
}
int fac[Q], ifac[Q];
void dfs(int x, int last) {
  si[x] = 1;
  for (int y : g[x]) {
    if (y == last) continue;
    dfs(y, x);
    Add(als, mul(sm[x], sm[y]));
    Add(sm[x], sm[y]);
    si[x] += si[y];
  }
  int maxn = 0;
  for (int y : g[x]) {
    if (y == last) continue;
    buf1[maxn << 1 | 1] = si[y];
    buf1[maxn << 1] = 1;
    buf2[maxn << 1 | 1] = 0;
    buf2[maxn << 1] = sm[y];
    ++maxn;
  }
  if (!maxn) {
    sm[x] = f[x] = 1;
    return;
  }
  Pi(0, maxn);
  buf2[maxn] = 0;
  for (int i = maxn; i; --i) Add(buf2[i], mul(buf2[i - 1], n - si[x]));
  for (int i = 0; i <= k && i <= maxn; i++) {
    int val = mul(fac[k], ifac[k - i]);
    Add(f[x], mul(val, buf1[i]));
    Add(als, mul(val, buf2[i]));
  }
  Add(sm[x], f[x]);
}
int main() {
  lim[1] = 2;
  for (int i = 2; i < Q; i++) {
    lim[i] = lim[i - 1];
    if (lim[i] == i) lim[i] <<= 1;
  }
  scanf("%d%d", &n, &k);
  if (k == 1) return 0 & printf("%lld\n", 1LL * n * (n - 1) / 2LL % MOD);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  ifac[n] = ksm(fac[n], MOD - 2);
  for (int i = n; i; --i) ifac[i - 1] = mul(ifac[i], i);
  for (int i = 1, x, y; i < n; i++)
    scanf("%d%d", &x, &y), g[x].push_back(y), g[y].push_back(x);
  dfs(1, 0);
  printf("%d\n", als);
  return 0;
}
