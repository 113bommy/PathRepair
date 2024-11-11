#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
const int FFTN = (1 << 17);
const int N = FFTN + 5;
int fac[N], inv[N];
int A[N], B[N], R[N];
int w[N], W[N];
unsigned long long p[N];
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % mo)
    if (y & 1) s = 1ll * s * x % mo;
  return s;
}
void init() {
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = (int)(2); i <= (int)(N - 1); i++)
    inv[i] = 1ll * inv[mo % i] * (mo - mo / i) % mo;
  for (int i = (int)(1); i <= (int)(N - 1); i++)
    inv[i] = 1ll * inv[i - 1] * inv[i] % mo;
  for (int i = (int)(1); i <= (int)(N - 1); i++)
    fac[i] = 1ll * fac[i - 1] * i % mo;
  W[0] = 1;
  W[1] = power(3, (mo - 1) / FFTN + 1);
  for (int i = (int)(2); i <= (int)(N - 1); i++)
    W[i] = 1ll * W[i - 1] * W[1] % mo;
}
int FFTinit(int n) {
  int L = 1;
  for (; L <= n; L <<= 1)
    ;
  for (int i = (int)(0); i <= (int)(L - 1); i++)
    R[i] = (R[i >> 1] >> 1) | ((i & 1) ? (L >> 1) : 0);
  return L;
}
void DFT(int *a, int n) {
  for (int i = (int)(0); i <= (int)(n - 1); i++) p[R[i]] = a[i];
  for (int d = 1; d < n; d <<= 1) {
    int len = FFTN / (d << 1);
    for (int i = 0, j = 0; i < d; i++, j += len) w[i] = W[j];
    for (int i = 0; i < n; i += (d << 1))
      for (int j = 0; j < d; j++) {
        int y = p[i + j + d] * w[j] % mo;
        p[i + j + d] = p[i + j] + mo - y;
        p[i + j] += y;
      }
  }
  for (int i = (int)(0); i <= (int)(n - 1); i++) a[i] = p[i] % mo;
}
void IDFT(int *a, int n) {
  for (int i = (int)(0); i <= (int)(n - 1); i++) p[R[i]] = a[i];
  for (int d = 1; d < n; d <<= 1) {
    int len = FFTN / (d << 1);
    for (int i = 0, j = FFTN; i < d; i++, j -= len) w[i] = W[j];
    for (int i = 0; i < n; i += (d << 1))
      for (int j = 0; j < d; j++) {
        int y = p[i + j + d] * w[j] % mo;
        p[i + j + d] = p[i + j] + mo - y;
        p[i + j] += y;
      }
  }
  int val = 1ll * inv[n] * fac[n - 1] % mo;
  for (int i = (int)(0); i <= (int)(n - 1); i++) a[i] = p[i] * val % mo;
}
vector<int> mult(vector<int> a, vector<int> b) {
  vector<int> ans;
  int sza = a.size() - 1, szb = b.size() - 1;
  ans.resize(sza + szb + 1);
  if (sza + szb <= 100) {
    for (int i = (int)(0); i <= (int)(sza); i++)
      for (int j = (int)(0); j <= (int)(szb); j++)
        ans[i + j] = (ans[i + j] + 1ll * a[i] * b[j]) % mo;
  } else {
    int L = FFTinit(sza + szb);
    for (int i = (int)(0); i <= (int)(L - 1); i++) A[i] = (i <= sza ? a[i] : 0);
    for (int i = (int)(0); i <= (int)(L - 1); i++) B[i] = (i <= szb ? b[i] : 0);
    DFT(A, L);
    DFT(B, L);
    for (int i = (int)(0); i <= (int)(L - 1); i++)
      A[i] = 1ll * A[i] * B[i] % mo;
    IDFT(A, L);
    for (int i = (int)(0); i <= (int)(sza + szb); i++) ans[i] = A[i];
  }
  return ans;
}
vector<int> divide(int l, int r, vector<int> &tmp) {
  if (l == r) {
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(tmp[l]);
    return ans;
  }
  int mid = (l + r) / 2;
  return mult(divide(l, mid, tmp), divide(mid + 1, r, tmp));
}
vector<int> solve(vector<int> tmp) {
  int sz = tmp.size();
  if (!sz) {
    vector<int> ans;
    ans.push_back(1);
    return ans;
  }
  return divide(0, sz - 1, tmp);
}
int sz[N], fa[N];
vector<int> f[N];
int vf[N], vg[N], sf[N];
int n, k, ans, ff[N];
vector<int> e[N];
map<int, int> mp;
void dfs(int x) {
  sz[x] = 1;
  for (auto i : e[x])
    if (i != fa[x]) {
      fa[i] = x;
      dfs(i);
      sz[x] += sz[i];
      sf[x] = (sf[x] + sf[i]) % mo;
    }
  vector<int> tmp;
  for (auto i : e[x])
    if (i != fa[x]) tmp.push_back(sz[i]);
  f[x] = solve(tmp);
  for (int i = (int)(0); i <= (int)(min((int)f[x].size() - 1, k - 1)); i++)
    vf[x] = (vf[x] + 1ll * fac[k] * inv[k - i] % mo * f[x][i]) % mo;
  sf[x] = (sf[x] + vf[x]) % mo;
}
void dfs2(int x) {
  ans = (ans + 1ll * vf[x] * vg[x]) % mo;
  mp.clear();
  if (x != 1) {
    f[x].push_back(0);
    int m = f[x].size();
    for (int i = (int)(m - 2); i >= (int)(0); i--)
      f[x][i + 1] = (f[x][i + 1] + 1ll * f[x][i] * (n - sz[x])) % mo;
  }
  mp.clear();
  for (auto i : e[x])
    if (i != fa[x]) {
      if (!mp[sz[i]]) {
        int m = f[x].size();
        for (int j = (int)(0); j <= (int)(m - 1); j++) ff[j] = f[x][j];
        for (int j = (int)(0); j <= (int)(m - 2); j++)
          ff[j + 1] = (ff[j + 1] + mo - 1ll * ff[j] * sz[i]) % mo;
        int vson = vg[x];
        for (int j = (int)(0); j <= (int)(min(m - 2, k - 1)); j++)
          vson = (vson + 2ll * fac[k] * inv[k - j] % mo * ff[j]) % mo;
        mp[sz[i]] = vson;
      }
      vg[i] = mp[sz[i]];
      vg[i] = (vg[i] + sf[x] + 2ll * mo - sf[i] - vf[x]) % mo;
    }
  for (auto i : e[x])
    if (i != fa[x]) dfs2(i);
}
int main() {
  init();
  scanf("%d%d", &n, &k);
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1);
  dfs2(1);
  ans = 1ll * (mo + 1) / 2 * ans % mo;
  printf("%d\n", ans);
}
