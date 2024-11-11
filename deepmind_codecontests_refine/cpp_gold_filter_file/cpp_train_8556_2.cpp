#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 998244353;
const double PI = acos(-1);
const int64_t root = 565042129;
const int64_t root_1 = 950391366;
const int64_t root_pw = 1 << 20;
int64_t fact[310000];
int64_t ifact[310000];
int64_t mpow(int64_t x, int64_t y, int64_t m) {
  if (y == 0) return 1;
  int64_t temp = mpow(x, y / 2, m);
  if (y & 1) {
    temp = temp * temp;
    temp %= m;
    return (temp * x) % m;
  }
  return (temp * temp) % m;
}
int64_t inverse(int64_t a, int64_t mod) { return mpow(a, mod - 2, mod); }
void fft(vector<int64_t>& a, bool invert) {
  int64_t n = a.size();
  for (int64_t i = 1, j = 0; i < n; i++) {
    int64_t bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int64_t len = 2; len <= n; len <<= 1) {
    int64_t wlen = invert ? root_1 : root;
    for (int64_t i = len; i < root_pw; i <<= 1)
      wlen = (int64_t)(1LL * wlen * wlen % MOD);
    for (int64_t i = 0; i < n; i += len) {
      int64_t w = 1;
      for (int64_t j = 0; j < len / 2; j++) {
        int64_t u = a[i + j], v = (int64_t)(1LL * a[i + j + len / 2] * w % MOD);
        a[i + j] = u + v < MOD ? u + v : u + v - MOD;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
        w = (int64_t)(1LL * w * wlen % MOD);
      }
    }
  }
  if (invert) {
    int64_t n_1 = inverse(n, MOD);
    for (int64_t& x : a) x = (int64_t)(1LL * x * n_1 % MOD);
  }
}
int64_t nCr(int64_t n, int64_t r) {
  if (n < 0 || r < 0 || n < r) return 0;
  int64_t ans = 1;
  ans *= fact[n];
  ans *= ifact[r];
  ans %= MOD;
  ans *= ifact[n - r];
  ans %= MOD;
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  ifact[0] = 1;
  for (int64_t i = 1; i < 310000; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    ifact[i] = inverse(fact[i], MOD);
  }
  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> w(n);
  for (int64_t i = 0; i < n; i++) cin >> w[i];
  vector<int64_t> r(k);
  for (int64_t i = 0; i < k; i++) cin >> r[i];
  int64_t q;
  cin >> q;
  vector<int64_t> p(q);
  vector<int64_t> qans(q, 0);
  for (int64_t i = 0; i < q; i++) cin >> p[i];
  sort(w.begin(), w.end());
  map<int64_t, int64_t> freq;
  for (int64_t it : w) freq[it]++;
  for (int64_t i = 0; i < k; i++) {
    int64_t cnt1 = 0, cnt2 = 0;
    for (auto it : freq) {
      if (it.first >= r[i]) break;
      if (it.second == 1)
        cnt1++;
      else
        cnt2++;
    }
    vector<int64_t> a;
    vector<int64_t> b;
    for (int64_t i = 0; i <= (2 * cnt2); i++) {
      a.push_back(nCr(2 * cnt2, i));
    }
    for (int64_t i = 0; i <= cnt1; i++) {
      b.push_back((nCr(cnt1, i) * mpow(2, i, MOD)) % MOD);
    }
    int64_t t = 1;
    while (t < cnt1 + 2 * cnt2 + 2) t <<= 1;
    a.resize(t);
    b.resize(t);
    fft(a, false);
    fft(b, false);
    for (int64_t i = 0; i < t; i++) {
      a[i] = (a[i] * b[i]) % MOD;
    }
    fft(a, true);
    for (int64_t j = 0; j < q; j++) {
      if (p[j] % 2 == 1) continue;
      if (p[j] < 2 * r[i] + 2) {
        continue;
      } else {
        if ((p[j] - 2 * r[i] - 2) / 2 < a.size())
          qans[j] += a[(p[j] - 2 * r[i] - 2) / 2];
        qans[j] %= MOD;
      }
    }
  }
  for (int64_t i = 0; i < q; i++) cout << qans[i] << "\n";
  return 0;
}
