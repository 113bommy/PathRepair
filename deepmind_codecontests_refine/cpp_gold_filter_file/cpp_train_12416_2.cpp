#include <bits/stdc++.h>
using namespace std;
using INT = long long;
namespace fft {
const int mod = 998244353;
const int root = 31;
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
const int root_1 = power(root, mod - 2, mod);
void fft(vector<int>& a, bool invert) {
  int n = a.size();
  int PW = power(invert ? root_1 : root, (mod - 1) / n, mod);
  for (int m = n, h; h = m / 2, m >= 2; PW = 1LL * PW * PW % mod, m = h) {
    for (int i = 0, w = 1; i < h; ++i, w = 1LL * w * PW % mod)
      for (int j = i; j < n; j += m) {
        int k = j + h, x = (a[j] - a[k] + mod) % mod;
        a[j] += a[k];
        a[j] %= mod;
        a[k] = 1LL * w * x % mod;
      }
  }
  for (int i = 0, j = 1; j < n - 1; ++j) {
    for (int k = n / 2; k > (i ^= k); k /= 2)
      ;
    if (j < i) swap(a[i], a[j]);
  }
  if (invert) {
    int rev = power(n, mod - 2, mod);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * rev % mod;
  }
}
vector<int> multiply(const vector<int>& a, const vector<int>& b, int ok = 0) {
  int n = 1, mx = a.size() + b.size() - 1;
  while (n < mx) n <<= 1;
  if (mx < 256) {
    vector<int> c(mx);
    for (int i = 0; i < a.size(); i++)
      for (int j = 0; j < b.size(); j++) {
        c[i + j] = (c[i + j] + 1ll * a[i] * b[j]) % mod;
      }
    return c;
  }
  vector<int> na = a, nb = b;
  na.resize(n);
  nb.resize(n);
  fft(na, false);
  if (ok)
    nb = na;
  else
    fft(nb, false);
  for (int i = 0; i < n; ++i) na[i] = 1LL * na[i] * nb[i] % mod;
  fft(na, true);
  na.resize(mx);
  return na;
}
vector<int> findInverse(const vector<int>& ff) {
  int nn = ff.size();
  int n = 1;
  while (n < nn) n <<= 1;
  vector<int> f = ff;
  f.resize(n);
  vector<int> r(1, power(f[0], mod - 2, mod));
  for (int it = 2; it <= n; it <<= 1) {
    vector<int> nr =
        multiply(multiply(r, r), vector<int>(f.begin(), f.begin() + it));
    nr.resize(it);
    for (int i = 0; i < nr.size(); ++i)
      if (nr[i]) nr[i] = mod - nr[i];
    for (int i = 0; i < it / 2; ++i) nr[i] = (2LL * r[i] + nr[i]) % mod;
    r = nr;
  }
  r.resize(nn);
  return r;
}
bool checkInverse(const vector<int>& a, const vector<int>& b) {
  for (int i = 0; i < a.size(); i++) {
    int val = 0;
    for (int j = 0; j <= i; j++) {
      val = (val + 1LL * a[i - j] * b[j]) % mod;
    }
    if (val != (i == 0)) return false;
  }
  return true;
}
vector<int> squareRoot(const vector<int>& ff) {
  int nn = ff.size();
  int n = 1;
  while (n < nn) n <<= 1;
  vector<int> f = ff;
  f.resize(n);
  vector<int> r(1, 1);
  int inv2 = power(2, mod - 2, mod);
  for (int it = 2; it <= n; it <<= 1) {
    r.resize(it);
    vector<int> res =
        multiply(findInverse(r), vector<int>(f.begin(), f.begin() + it));
    res.resize(it);
    for (int i = 0; i < r.size(); ++i) {
      res[i] += r[i];
      if (res[i] >= mod) res[i] -= mod;
    }
    for (int i = 0; i < res.size(); ++i) res[i] = 1LL * res[i] * inv2 % mod;
    r = res;
  }
  r.resize(nn);
  return r;
}
};  // namespace fft
int a[410000], l[410000], flag[410000];
vector<int> A, B;
int ans[1000100];
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) scanf("%d", &l[i]);
  for (int i = 0; i < n; i++) {
    A.push_back(1);
    for (int j = a[i] + 1; j < a[i + 1]; j++) A.push_back(0);
  }
  A.push_back(1);
  for (int i = n; i > 0; i--) {
    B.push_back(1);
    for (int j = x - a[i] + 1; j < x - a[i - 1]; j++) B.push_back(0);
  }
  B.push_back(1);
  vector<int> c = fft ::multiply(A, B);
  for (int i = x; i < c.size(); i++) {
    if (c[i]) flag[i - x] = 1;
  }
  memset(ans, -1, sizeof ans);
  for (int i = 1; i <= x; i++) {
    if (flag[i]) {
      int tmp = 2 * i + 2 * y;
      for (int j = tmp; j < 1000100; j += tmp) ans[j] = max(ans[j], tmp);
    }
  }
  for (int i = 1; i <= q; i++) printf("%d ", ans[l[i]]);
  cout << endl;
  return 0;
}
