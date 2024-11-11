#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int Mod = 998244353, rt = 3;
void add(int &x, int y) {
  x += y;
  if (x >= Mod) x -= Mod;
}
int Pow(int x, int e) {
  int ret = 1;
  while (e) {
    if (e & 1) ret = 1ll * ret * x % Mod;
    x = 1ll * x * x % Mod;
    e >>= 1;
  }
  return ret;
}
int rev[N];
void DFT(int *A, int n, int wn) {
  static int w[N];
  for (int i = 0; i <= n - 1; i++)
    if (i < rev[i]) swap(A[i], A[rev[i]]);
  for (int i = 1; i < n; i <<= 1) {
    w[0] = 1, w[1] = Pow(rt, (Mod - 1) / (i << 1));
    if (wn == -1) w[1] = Pow(w[1], Mod - 2);
    for (int j = 2; j < i; ++j) w[j] = 1ll * w[j - 1] * w[1] % Mod;
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; ++k) {
        int x = A[j + k], y = 1ll * A[i + j + k] * w[k] % Mod;
        A[j + k] = (x + y) % Mod, A[i + j + k] = (x + Mod - y) % Mod;
      }
  }
}
void mul(vector<int> &a, const vector<int> &b) {
  int x = a.size(), y = b.size(), n = 1;
  while (n < x + y) n <<= 1;
  for (int i = 0; i <= n - 1; i++)
    rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? n / 2 : 0);
  static int A[N << 1], B[N << 1];
  for (int i = 0; i <= n - 1; i++) A[i] = i < x ? a[i] : 0;
  for (int i = 0; i <= n - 1; i++) B[i] = i < y ? b[i] : 0;
  DFT(A, n, 1), DFT(B, n, 1);
  for (int i = 0; i <= n - 1; i++) A[i] = 1ll * A[i] * B[i] % Mod;
  DFT(A, n, -1);
  int inv = Pow(n, Mod - 2);
  for (int i = 0; i <= n - 1; i++) A[i] = 1ll * inv * A[i] % Mod;
  a.resize(x + y - 1);
  for (int i = 0; i <= x + y - 2; i++) a[i] = A[i];
}
vector<int> A[N];
void mult(int *f, int *x, int n) {
  for (int i = 1; i <= n; i++)
    A[i].clear(), A[i].push_back(1), A[i].push_back(x[i]);
  for (int i = 1; i < n; i <<= 1)
    for (int j = 1; j + i <= n; j += i << 1) mul(A[j], A[j + i]);
  for (int i = 0; i <= n; i++) f[i] = A[1][i];
}
int Begin[N], Next[N << 1], to[N << 1], e;
void adde(int u, int v) { to[++e] = v, Next[e] = Begin[u], Begin[u] = e; }
int n, m, k;
int fac[N], rfac[N];
int sz[N];
int coe[N], f[N], dp[N];
int P[N], val[N];
int ans;
void DFS_work(int o, int fa = 0) {
  sz[o] = 1;
  for (int i = Begin[o]; i; i = Next[i]) {
    int u = to[i];
    if (u == fa) continue;
    DFS_work(u, o);
    ans = (ans + 1ll * dp[u] * dp[o]) % Mod;
    add(dp[o], dp[u]);
    sz[o] += sz[u];
  }
  m = 0;
  if (fa) coe[m = 1] = n - sz[o];
  for (int i = Begin[o]; i; i = Next[i]) {
    int u = to[i];
    if (u == fa) continue;
    coe[++m] = sz[u];
  }
  sort(coe + 1, coe + m + 1);
  mult(f, coe, m);
  for (int i = 1; i <= m; i++)
    if (coe[i] != coe[i - 1]) {
      for (int j = 0; j <= m; j++) P[j] = f[j];
      for (int j = 0; j <= m; j++)
        P[j + 1] = ((P[j + 1] - 1ll * coe[i] * P[j]) % Mod + Mod) % Mod;
      int r = min(k, m - 1), &w = val[coe[i]];
      w = 0;
      for (int j = 0; j <= r; j++) w = (w + 1ll * P[j] * rfac[k - j]) % Mod;
      w = 1ll * w * fac[k] % Mod;
    }
  for (int i = Begin[o]; i; i = Next[i]) {
    int u = to[i];
    if (u == fa) continue;
    ans = (ans + 1ll * dp[u] * val[sz[u]]) % Mod;
  }
  add(dp[o], val[n - sz[o]]);
}
int main() {
  scanf("%d%d", &n, &k);
  if (n == 1) {
    puts("0");
    return 0;
  }
  if (k == 1) {
    int res = 1ll * n * (n - 1) / 2;
    printf("%d\n", res);
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adde(u, v), adde(v, u);
  }
  int s = max(n, k) + 5;
  fac[0] = 1;
  for (int i = 1; i <= s; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;
  rfac[s] = Pow(fac[s], Mod - 2);
  for (int i = s; i >= 1; i--) rfac[i - 1] = 1ll * rfac[i] * i % Mod;
  DFS_work(1);
  printf("%d\n", ans);
  return 0;
}
