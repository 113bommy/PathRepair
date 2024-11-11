#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T read() {
  T x = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') w = -w;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * w;
}
template <class T>
inline T read(T& x) {
  return x = read<T>();
}
const int mod = 998244353;
inline int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline int mul(int a, int b) { return (long long)a * b % mod; }
inline int fpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) ans = mul(ans, a);
  return ans;
}
const int N = 262144;
int omg[2][N], rev[N];
int fac[N], inv[N], ifac[N];
void NTT(vector<int>& a, int dir) {
  int lim = a.size(), len = log2(lim);
  for (int i = 0; i < lim; ++i)
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << (len - 1);
  for (int i = 0; i < lim; ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += i << 1)
      for (int k = 0; k < i; ++k) {
        int t = mul(omg[dir][N / (i << 1) * k], a[j + i + k]);
        a[j + i + k] = add(a[j + k], mod - t), a[j + k] = add(a[j + k], t);
      }
  if (dir == 1) {
    int ilim = fpow(lim, mod - 2);
    for (int i = 0; i < lim; ++i) a[i] = mul(a[i], ilim);
  }
}
vector<int> operator*(vector<int> a, vector<int> b) {
  int n = a.size() + b.size() - 1, lim = 1 << (int)ceil(log2(n));
  a.resize(lim), NTT(a, 0);
  b.resize(lim), NTT(b, 0);
  for (int i = 0; i < lim; ++i) a[i] = mul(a[i], b[i]);
  NTT(a, 1), a.resize(n);
  return a;
}
vector<int> operator+(const vector<int>& a, const vector<int>& b) {
  vector<int> ans = a;
  if (a.size() < b.size()) ans.resize(b.size());
  for (int i = 0; i < (int)b.size(); ++i) ans[i] = add(ans[i], b[i]);
  return ans;
}
vector<int> to[N];
int fa[N], siz[N], son[N];
void dfs(int u, int fa) {
  ::fa[u] = fa, siz[u] = 1;
  for (int v : to[u])
    if (v != fa) {
      dfs(v, u);
      siz[u] += siz[v];
      if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
vector<int> a[N], p[N];
pair<vector<int>, vector<int> > solve(int l, int r) {
  if (l == r) return {a[l], a[l]};
  int mid = (l + r) >> 1;
  pair<vector<int>, vector<int> > lans = solve(l, mid);
  pair<vector<int>, vector<int> > rans = solve(mid + 1, r);
  return {lans.first * rans.first, lans.second + lans.first * rans.second};
}
vector<int> divide(int u) {
  for (int i = u; i; i = son[i]) {
    for (int v : to[i])
      if (v != fa[i] and v != son[i]) {
        p[i] = divide(v);
        break;
      }
    if (p[i].empty()) p[i].push_back(0);
    p[i][0] = 1, p[i].insert(p[i].begin(), 0);
  }
  int l = 0;
  for (int i = u; i; i = son[i]) a[++l].swap(p[i]);
  return solve(1, l).second;
}
int main() {
  omg[0][0] = 1, omg[0][1] = fpow(3, (mod - 1) / N);
  omg[1][0] = 1, omg[1][1] = fpow(omg[0][1], mod - 2);
  fac[0] = fac[1] = 1;
  inv[0] = inv[1] = 1;
  ifac[0] = ifac[1] = 1;
  for (int i = 2; i < N; ++i) {
    omg[0][i] = mul(omg[0][i - 1], omg[0][1]);
    omg[1][i] = mul(omg[1][i - 1], omg[1][1]);
    fac[i] = mul(fac[i - 1], i);
    inv[i] = mul(mod - mod / i, inv[mod % i]);
    ifac[i] = mul(ifac[i - 1], inv[i]);
  }
  int n = read<int>(), X = read<int>() % mod;
  for (int i = 1; i < n; ++i) {
    int u = read<int>(), v = read<int>();
    to[u].push_back(v), to[v].push_back(u);
  }
  dfs(1, 0);
  vector<int> cnt = divide(1);
  int ans = 0, binom = 1;
  for (int i = 1; i < (int)cnt.size() and binom; ++i) {
    ans = add(ans, mul(binom, cnt[i]));
    binom = mul(binom, mul(add(X, i), inv[i]));
  }
  printf("%d\n", ans);
  return 0;
}
