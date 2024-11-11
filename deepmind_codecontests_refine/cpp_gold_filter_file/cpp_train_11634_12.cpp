#include <bits/stdc++.h>
using namespace std;
bool s1;
char o;
int Read() {
  bool f = 1;
  while (!isdigit(o = getchar()))
    if (o == '-') f = 0;
  int res = o ^ 48;
  while (isdigit(o = getchar())) res = (res << 3) + (res << 1) + (o ^ 48);
  return f ? res : -res;
}
int n, m, dp[100006], sum[100006], sz[100006], Q[100006], W[100006],
    Pow[100006], Pow1[100006], ans;
int rev[(1 << 18) + 2], a[(1 << 18) + 2], b[(1 << 18) + 2], w[(1 << 18) + 2], N;
vector<int> son[100006];
void Mo(int &a) { (a >= 998244353) && (a -= 998244353); }
int fast(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % 998244353;
    y >>= 1;
    x = 1ll * x * x % 998244353;
  }
  return res;
}
void Init() {
  N = 1 << 18;
  w[N >> 1] = 1;
  int t = fast(3, (998244353 - 1) / N);
  for (int i = (N >> 1) + 1; i < N; ++i) w[i] = 1ll * w[i - 1] * t % 998244353;
  for (int i = (N >> 1) - 1; i > 0; --i) w[i] = w[i << 1];
}
void NTT(int *x, int fl) {
  for (int i = 0; i < N; ++i)
    if (rev[i] > i) swap(x[i], x[rev[i]]);
  for (int L = 1, t; L < N; L <<= 1) {
    for (int i = 0; i < N; i += L << 1)
      for (int j = i; j < i + L; ++j) {
        t = 1ll * x[j + L] * w[L + j - i] % 998244353;
        Mo(x[j + L] = x[j] + 998244353 - t);
        Mo(x[j] += t);
      }
  }
  if (fl) {
    reverse(x + 1, x + N);
    int inv = fast(N, 998244353 - 2);
    for (int i = 0; i < N; ++i) x[i] = 1ll * x[i] * inv % 998244353;
  }
}
struct Poly {
  vector<int> f, g;
};
vector<int> operator*(const vector<int> &x, const vector<int> &y) {
  vector<int> res;
  int l = -1;
  for (N = 1; N < x.size() + y.size(); N <<= 1) ++l;
  for (int i = 0; i < x.size(); ++i) a[i] = x[i];
  for (int i = x.size(); i < N; ++i) a[i] = 0;
  for (int i = 0; i < y.size(); ++i) b[i] = y[i];
  for (int i = y.size(); i < N; ++i) b[i] = 0;
  for (int i = 0; i < N; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l);
  NTT(a, 0), NTT(b, 0);
  for (int i = 0; i < N; ++i) a[i] = 1ll * a[i] * b[i] % 998244353;
  NTT(a, 1);
  int len = min(m + 1, (int)(x.size() + y.size()) - 1);
  res.resize(len);
  for (int i = 0; i < len; ++i) res[i] = a[i];
  return res;
}
vector<int> operator+(const vector<int> &x, const vector<int> &y) {
  vector<int> res;
  int len = max(x.size(), y.size());
  res.resize(len);
  for (int i = 0; i < x.size(); ++i) res[i] = x[i];
  for (int i = 0; i < y.size(); ++i) Mo(res[i] += y[i]);
  return res;
}
Poly Solve(int L, int R) {
  Poly res;
  if (L == R) {
    res.f.resize(2), res.g.resize(1);
    res.f[1] = Q[L], res.f[0] = 1;
    res.g[0] = W[L];
    return res;
  }
  int mid = (L + R) >> 1;
  Poly x = Solve(L, mid), y = Solve(mid + 1, R);
  res.f = x.f * y.f;
  res.g = (x.f * y.g + x.g * y.f);
  return res;
}
void dfs(int x, int fa) {
  sz[x] = 1;
  for (int i = 0; i < son[x].size(); ++i) {
    int y = son[x][i];
    if (y == fa) continue;
    dfs(y, x);
    ans = (ans + 1ll * sum[x] * sum[y]) % 998244353;
    Mo(sum[x] += sum[y]);
    sz[x] += sz[y];
  }
  int len = 1;
  Q[len] = W[len] = 0;
  for (int i = 0; i < son[x].size(); ++i) {
    int y = son[x][i];
    if (y == fa) continue;
    Q[++len] = sz[y], W[len] = sum[y];
  }
  Poly Ans = Solve(1, len);
  len = min(m + 1, (int)Ans.f.size());
  for (int i = 0; i < len; ++i)
    dp[x] =
        (dp[x] + 1ll * Pow[m] * Pow1[m - i] % 998244353 * Ans.f[i]) % 998244353;
  Mo(sum[x] += dp[x]);
  vector<int> res;
  res.resize(2), res[0] = 1, res[1] = n - sz[x];
  res = Ans.g * res;
  len = min(m + 1, (int)res.size());
  for (int i = 0; i < len; ++i)
    ans = (ans + 1ll * Pow[m] * Pow1[m - i] % 998244353 * res[i]) % 998244353;
}
bool s2;
int main() {
  n = Read(), m = Read(), Init();
  if (m == 1) {
    printf("%lld\n", 1ll * n * (n - 1) / 2 % 998244353);
    return 0;
  }
  for (int i = 1, u, v; i < n; ++i) {
    u = Read(), v = Read();
    son[u].push_back(v), son[v].push_back(u);
  }
  Pow[0] = Pow1[0] = 1;
  for (int i = 1; i <= m; ++i) Pow[i] = 1ll * Pow[i - 1] * i % 998244353;
  Pow1[m] = fast(Pow[m], 998244353 - 2);
  for (int i = m - 1; i >= 1; --i)
    Pow1[i] = 1ll * Pow1[i + 1] * (i + 1) % 998244353;
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}
