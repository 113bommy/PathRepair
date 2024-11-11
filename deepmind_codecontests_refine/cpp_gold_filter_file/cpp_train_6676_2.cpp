#include <bits/stdc++.h>
#pragma compile "03"
using namespace std;
const long long int g = 3, mod = 998244353, p = 998244353;
const long long int N = 2000005;
long long int pp[10];
vector<long long int> a;
vector<long long int> ans;
vector<long long int> b;
inline long long int add(long long int x, long long int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline long long int sub(long long int x, long long int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline long long int mul(long long int x, long long int y) {
  return (x * 1ll * y) % mod;
}
inline long long int powr(long long int a, long long int b) {
  long long int x = 1 % mod;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline long long int inv(long long int a) { return powr(a, mod - 2); }
const long long int MX = 21;
long long int W[1 << MX], invW[1 << MX];
long long int maxn;
void precompute_powers() {
  long long int p2 = p - 1, MAXN = 0;
  while (p2 % 2 == 0) {
    p2 >>= 1;
    MAXN++;
  }
  MAXN = min(MAXN, MX);
  long long int g1 = powr(g, (p - 1) >> MAXN);
  maxn = 1 << MAXN;
  long long int st = 1;
  for (long long int i = 0; i < maxn; i++) {
    W[i] = st;
    st = mul(st, g1);
  }
  for (long long int i = 0; i < maxn; i++) {
    invW[i] = (i == 0) ? 1 : W[maxn - i];
  }
}
void fft(vector<long long int>& a, bool invert) {
  long long int n = (long long int)a.size();
  for (long long int i = 1, j = 0; i < n; ++i) {
    long long int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (long long int len = 2; len <= n; len <<= 1) {
    for (long long int i = 0; i < n; i += len) {
      long long int ind = 0, ADD = maxn / len;
      for (long long int j = 0; j < len / 2; ++j) {
        long long int u = a[i + j], v = mul(a[i + j + len / 2],
                                            (invert ? invW[ind] : W[ind]));
        a[i + j] = add(u, v);
        a[i + j + len / 2] = sub(u, v);
        ind += ADD;
      }
    }
  }
  if (invert) {
    long long int invn = inv(n);
    for (long long int i = 0; i < n; ++i) a[i] = mul(a[i], invn);
  }
}
vector<long long int> add(vector<long long int> a, vector<long long int> b) {
  vector<long long int> ret(max(a.size(), b.size()));
  for (long long int i = 0; i < ret.size(); i++) {
    ret[i] = add(i < a.size() ? a[i] : 0, i < b.size() ? b[i] : 0);
  }
  return ret;
}
vector<long long int> sub(vector<long long int> a, vector<long long int> b) {
  vector<long long int> ret(max(a.size(), b.size()));
  for (long long int i = 0; i < ret.size(); i++) {
    ret[i] = sub(i < a.size() ? a[i] : 0, i < b.size() ? b[i] : 0);
  }
  return ret;
}
vector<long long int> mul(vector<long long int> a, vector<long long int> b) {
  long long int sz = a.size() + b.size() - 1;
  long long int k = 0;
  while ((1 << k) < sz) k++;
  a.resize(1 << k);
  b.resize(1 << k);
  fft(a, 0);
  fft(b, 0);
  for (long long int i = 0; i < (1 << k); i++) a[i] = mul(a[i], b[i]);
  fft(a, 1);
  a.resize(sz);
  return a;
}
vector<long long int> inverse(vector<long long int> a, long long int sz) {
  assert(a[0] != 0);
  vector<long long int> x = {inv(a[0])};
  while (x.size() < sz) {
    vector<long long int> temp(a.begin(),
                               a.begin() + min(a.size(), 2 * x.size()));
    vector<long long int> nx = mul(mul(x, x), temp);
    x.resize(2 * x.size());
    for (long long int i = 0; i < x.size(); i++)
      x[i] = sub(add(x[i], x[i]), nx[i]);
  }
  x.resize(sz);
  return x;
}
vector<long long int> truncate_end(vector<long long int> v) {
  while (!v.empty() && v.back() == 0) v.pop_back();
  if (v.empty()) v = {0};
  return v;
}
void print(vector<long long int> v) {
  cerr << "[";
  for (long long int i = 0; i < v.size(); i++) {
    cerr << v[i];
    if (i + 1 != v.size())
      cerr << " ";
    else
      cerr << "]";
  }
  cerr << '\n';
}
vector<long long int> divmod(vector<long long int> f, vector<long long int> g) {
  if (f.size() < g.size()) return f;
  long long int sz = f.size() - g.size() + 1;
  reverse(f.begin(), f.end());
  reverse(g.begin(), g.end());
  vector<long long int> inv2 = inverse(g, g.size());
  inv2.resize(sz);
  vector<long long int> _p = f;
  _p.resize(sz);
  vector<long long int> q = mul(inv2, _p);
  q.resize(sz);
  reverse(q.begin(), q.end());
  reverse(f.begin(), f.end());
  reverse(g.begin(), g.end());
  return truncate_end(sub(f, mul(g, q)));
}
vector<long long int> go(long long int fuck) {
  vector<long long int> ret;
  if (fuck == 1) {
    ret.resize(10, 0);
    for (long long int i = 0; i < 10; i++) {
      ret[i] = b[i];
    }
    return ret;
  }
  vector<long long int> v1 = go(fuck / 2);
  ret = mul(v1, v1);
  ret.resize((long long int)v1.size() + (long long int)v1.size() - 1, 0);
  if (fuck % 2) {
    ret = mul(ret, b);
    ret.resize((long long int)v1.size() + (long long int)v1.size() - 1 + 10, 0);
  }
  return ret;
}
signed main() {
  precompute_powers();
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int n, k;
  cin >> n >> k;
  for (long long int i = 0; i < k; i++) {
    long long int x;
    cin >> x;
    pp[x]++;
  }
  for (long long int i = 0; i < 10; i++) {
    if (pp[i]) {
      a.push_back(1);
      b.push_back(1);
    } else {
      a.push_back(0);
      b.push_back(0);
    }
  }
  ans = go(n / 2);
  long long int val = 0;
  long long int bak = 0;
  for (auto i : ans) {
    bak++;
    val = val + ((i * i) % mod);
    val %= mod;
  }
  cout << val << '\n';
  return 0;
}
