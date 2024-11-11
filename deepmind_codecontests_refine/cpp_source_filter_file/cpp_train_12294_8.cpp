#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
const int N = 1 << 19, mod = 998244353;
int Pow(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = (long long)x * x % mod)
    if (y & 1) ans = (long long)ans * x % mod;
  return ans;
}
void Add(int &x, int y) {
  if ((x += y) >= mod) x -= mod;
}
void Del(int &x, int y) {
  if ((x -= y) < 0) x += mod;
}
int Add(int x) { return x >= mod ? x - mod : x; }
int Del(int x) { return x < 0 ? x + mod : x; }
namespace fft {
int w[N], R[N];
void init(int n) {
  int d = 0;
  while (1 << d < n) d++;
  for (int i = (0); i <= (n - 1); i++)
    R[i] = (R[i >> 1] >> 1) | ((i & 1) << (d - 1));
  w[0] = 1, w[1] = Pow(3, (mod - 1) / n);
  for (int i = (2); i <= (n - 1); i++) w[i] = (long long)w[i - 1] * w[1] % mod;
}
void FFT(int *a, int n, int flag) {
  for (int i = (0); i <= (n - 1); i++)
    if (i < R[i]) swap(a[i], a[R[i]]);
  for (int t = n >> 1, d = 1; d < n; d <<= 1, t >>= 1)
    for (int i = 0; i < n; i += d << 1)
      for (int j = 0; j < d; j++) {
        int tmp = (long long)w[t * j] * a[i + j + d] % mod;
        a[i + j + d] = Del(a[i + j] - tmp);
        Add(a[i + j], tmp);
      }
  if (flag < 0) {
    reverse(a + 1, a + n);
    int inv = Pow(n, mod - 2);
    for (int i = (0); i <= (n - 1); i++) a[i] = (long long)a[i] * inv % mod;
  }
}
vector<int> Mul(vector<int> a, vector<int> b) {
  int n = 1, m = max(0, (int)a.size() + (int)b.size() - 1);
  while (n < m) n <<= 1;
  a.resize(n), b.resize(n);
  init(n);
  FFT(&a[0], n, 1), FFT(&b[0], n, 1);
  for (int i = (0); i <= (n - 1); i++) a[i] = (long long)a[i] * b[i] % mod;
  FFT(&a[0], n, -1);
  a.resize(m);
  return a;
}
}  // namespace fft
vector<int> operator+(vector<int> a, vector<int> b) {
  int n = max(a.size(), b.size());
  a.resize(n), b.resize(n);
  for (int i = (0); i <= (n - 1); i++) Add(a[i], b[i]);
  return a;
}
vector<int> operator*(vector<int> a, vector<int> b) { return fft::Mul(a, b); }
int n, m;
vector<int> e[N];
int fa[N], sz[N], son[N], dep[N];
void dfs(int x, int pre, int d) {
  sz[x] = 1, fa[x] = pre, dep[x] = d, son[x] = 0;
  for (auto y : e[x])
    if (y != pre) {
      dfs(y, x, d + 1);
      sz[x] += sz[y];
      if (!son[x] || sz[y] > sz[son[x]]) son[x] = y;
    }
}
vector<vector<int> > Vs;
pair<vector<int>, vector<int> > calc(int L, int R) {
  if (L == R) return make_pair(Vs[L], Vs[L]);
  int mid = (L + R) >> 1;
  pair<vector<int>, vector<int> > lv = calc(L, mid), rv = calc(mid + 1, R);
  return make_pair(lv.first * rv.first, lv.second + lv.first * rv.second);
}
vector<int> Solve(int x) {
  vector<int> id;
  vector<vector<int> > vs;
  while (x) {
    id.push_back(x);
    vs.push_back(vector<int>({0, 1}));
    for (auto y : e[x])
      if (y != fa[x] && y != son[x]) vs.back() = vs.back() * Solve(y);
    x = son[x];
  }
  swap(Vs, vs);
  vector<int> res = calc(0, (int)Vs.size() - 1).second;
  Add(res[0], 1);
  return res;
}
int main() {
  n = read(), m = read() % mod;
  for (int i = (1); i <= (n - 1); i++) {
    int x = read(), y = read();
    e[x].push_back(y), e[y].push_back(x);
  }
  dfs(1, 0, 0);
  vector<int> v = Solve(1);
  int ans = 0, val = 1;
  for (int i = (1); i <= (n); i++) {
    if (i > 1)
      val = (long long)val * (m + i - 1) % mod * Pow(i - 1, mod - 2) % mod;
    Add(ans, (long long)val * v[i]);
  }
  cout << ans << endl;
  return 0;
}
