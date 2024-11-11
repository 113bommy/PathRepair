#include <bits/stdc++.h>
using namespace std;
template <class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 998244353;
const int g = 3;
namespace ntt {
int root = -1;
int root_1 = -1;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  long long pow_a = a;
  while (b) {
    if (b & 1) {
      res = res * pow_a % mod;
    }
    b >>= 1;
    pow_a = pow_a * pow_a % mod;
  }
  return res;
}
long long fix(long long x) {
  if (x < 0) x += mod;
  if (x >= mod) x -= mod;
  return x;
}
void ntt(vector<long long> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n / 2;
    for (; j >= bit; bit /= 2) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len *= 2) {
    long long wlen = invert ? root_1 : root;
    for (int i = len; i < n; i *= 2) wlen = wlen * wlen % mod;
    for (int i = 0; i < n; i += len) {
      for (int j = 0, w = 1; j < len / 2; j++, w = (w * wlen) % mod) {
        long long u = a[i + j];
        long long v = a[i + j + len / 2] * w % mod;
        a[i + j] = fix(u + v);
        a[i + j + len / 2] = fix(u - v);
      }
    }
  }
  if (invert) {
    long long inv_n = powmod(n, mod - 2, mod);
    for (int i = 0; i < n; i++) a[i] = a[i] * inv_n % mod;
  }
}
void clamp(vector<long long> &a) {
  while (a.size() > 1 && a.back() == 0) a.pop_back();
}
vector<long long> naive_multiply(vector<long long> &a, vector<long long> &b) {
  int n = a.size();
  int m = b.size();
  vector<long long> c(n + m - 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i + j] += a[i] * b[j] % mod;
      c[i + j] %= mod;
    }
  }
  return c;
}
vector<long long> multiply(vector<long long> &a, vector<long long> &b) {
  clamp(a);
  clamp(b);
  int n = a.size() + b.size();
  if (n <= 200) {
    return naive_multiply(a, b);
  }
  while (n & (n - 1)) n += n & -n;
  a.resize(n);
  b.resize(n);
  root = powmod(g, (mod - 1) / n, mod);
  root_1 = powmod(root, mod - 2, mod);
  ntt(a, false);
  ntt(b, false);
  for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % mod;
  ntt(a, true);
  clamp(a);
  return a;
}
vector<long long> powmod(vector<long long> a, long long b) {
  int n = a.size();
  while (n & (n - 1)) n += n & -n;
  a.resize(n);
  root = powmod(g, (mod - 1) / n, mod);
  root_1 = powmod(root, mod - 2, mod);
  ntt(a, false);
  for (int i = 0; i < n; i++)
    if (a[i] != 0) a[i] = powmod(a[i], b, mod);
  ntt(a, true);
  return a;
}
}  // namespace ntt
int n;
vector<int> values;
vector<long long> solve(int l, int r) {
  if (l == r) {
    return vector<long long>(values[l] + 1, 1);
  }
  int m = (l + r) / 2;
  vector<long long> u = solve(l, m);
  vector<long long> v = solve(m + 1, r);
  return ntt::multiply(u, v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  map<int, int> c;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    c[x]++;
  }
  for (auto &[a, cnt] : c) {
    values.push_back(cnt);
  }
  sort(values.begin(), values.end());
  cout << solve(0, values.size() - 1)[n / 2] << '\n';
  return 0;
}
