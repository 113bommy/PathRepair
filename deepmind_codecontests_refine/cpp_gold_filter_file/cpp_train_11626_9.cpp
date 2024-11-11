#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 21 | 1, M = 998244353;
int rev[N], w[N], a[N], fac[N], inv[N], n, m, b[N], val[N], val3[N], num[N],
    Ans, size[N], zz[N], ne[N], tot, x, y, fi[N], c[N];
inline void reduce(int& x) { x += x >> 31 & M; }
inline int ksm(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = (long long)x * x % M)
    if (y & 1) ans = (long long)ans * x % M;
  return ans;
}
inline void init(int len) {
  for (int i = 1; i < len; i++) rev[i] = rev[i >> 1] >> 1 | ((i & 1) * len / 2);
}
inline void INIT(int len) {
  for (int mid = 1; mid < len; mid <<= 1) {
    const int wn = ksm(3, M / mid / 2);
    w[mid] = 1;
    for (int i = 1; i < mid; ++i)
      w[i + mid] = (long long)w[i + mid - 1] * wn % M;
  }
}
inline void ntt(int y[], int len, int opt) {
  for (int i = 1; i < len; i++)
    if (rev[i] > i) swap(y[i], y[rev[i]]);
  for (int h = 1; h < len; h <<= 1)
    for (int j = 0; j < len; j += h + h)
      for (int k = 0; k < h; ++k) {
        const int x = (long long)y[h + j + k] * w[h + k] % M;
        reduce(y[h + j + k] = y[j + k] - x);
        reduce(y[j + k] += x - M);
      }
  if (opt == -1) {
    int temp = ksm(len, M - 2);
    for (int i = 0; i < len; i++) y[i] = (long long)y[i] * temp % M;
    reverse(y + 1, y + len);
  }
}
inline void solve(int l, int r, int Ans[]) {
  if (l == r) {
    Ans[0] = 1;
    Ans[1] = size[a[l]];
    return;
  }
  int len = 1, mid = (l + r) / 2;
  while (len <= r - l + 2) len <<= 1;
  int Ans1[len], Ans2[len];
  memset(Ans1, 0, len << 2);
  memset(Ans2, 0, len << 2);
  memset(Ans, 0, len << 2);
  solve(l, mid, Ans1);
  solve(mid + 1, r, Ans2);
  init(len);
  ntt(Ans1, len, 1);
  ntt(Ans2, len, 1);
  for (int i = 0; i < len; i++) Ans[i] = (long long)Ans1[i] * Ans2[i] % M;
  ntt(Ans, len, -1);
}
void jb(int x, int y) {
  ne[++tot] = fi[x];
  fi[x] = tot;
  zz[tot] = y;
}
int cmp(int x, int y) { return size[x] < size[y]; }
void dfs(int x, int y) {
  size[x] = 1;
  for (int i = fi[x]; i; i = ne[i])
    if (zz[i] != y) {
      dfs(zz[i], x);
      size[x] += size[zz[i]];
    }
  int cnt = 0;
  for (int i = fi[x]; i; i = ne[i])
    if (zz[i] != y) a[cnt++] = zz[i];
  sort(a, a + cnt, cmp);
  if (!cnt) {
    num[x] = 1;
    return;
  }
  int len = 1;
  while (len <= cnt + 2) len <<= 1;
  INIT(len);
  solve(0, cnt - 1, val);
  for (int j = cnt; j >= 0; j--)
    reduce(val3[j + 1] += (long long)val[j] * (n - size[x]) % M - M),
        reduce(val3[j] += val[j] - M);
  for (int i = 0, l = 0; i < cnt; i = l) {
    while (l < cnt && size[a[i]] == size[a[l]]) l++;
    for (int j = cnt + 1; j >= 0; j--) b[j] = val3[j];
    int V = ksm(size[a[i]], M - 2), val2 = 0;
    for (int j = cnt; j >= 0; j--)
      c[j] = (long long)b[j + 1] * V % M, reduce(b[j] -= c[j]);
    for (int j = 0; j <= cnt && j <= m; j++)
      reduce(val2 += (long long)c[j] * inv[m - j] % M - M);
    val2 = (long long)val2 * fac[m] % M;
    for (int k = i; k < l; k++)
      reduce(Ans += (long long)num[a[k]] * val2 % M - M);
  }
  memset(val3, 0, (cnt + 2) << 2);
  for (int i = 0; i < cnt; i++)
    reduce(Ans += (long long)num[a[i]] * num[x] % M - M),
        reduce(num[x] += num[a[i]] - M);
  int ppp = 0;
  for (int i = 0; i <= cnt && i <= m; i++)
    reduce(ppp += (long long)inv[m - i] * val[i] % M - M);
  reduce(num[x] += (long long)ppp * fac[m] % M - M);
}
signed main() {
  scanf("%d%d", &n, &m);
  if (m == 1) {
    printf("%lld\n", (long long)n * (n - 1) / 2 % M);
    return 0;
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    jb(x, y);
    jb(y, x);
  }
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= m; i++)
    fac[i] = (long long)fac[i - 1] * i % M, inv[i] = ksm(fac[i], M - 2);
  dfs(1, 0);
  printf("%d\n", Ans);
  return 0;
}
