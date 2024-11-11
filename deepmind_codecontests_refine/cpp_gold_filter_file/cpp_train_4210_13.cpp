#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long qp(long long a, long long b) {
  long long x = 1;
  a %= MOD;
  while (b) {
    if (b & 1) x = x * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return x;
}
namespace linear_seq {
inline vector<int> BM(vector<int> x) {
  vector<int> ls, cur;
  int lf, ld;
  for (int i = 0; i < int(x.size()); ++i) {
    long long t = 0;
    for (int j = 0; j < int(cur.size()); ++j)
      t = (t + x[i - j - 1] * (long long)cur[j]) % MOD;
    if ((t - x[i]) % MOD == 0) continue;
    if (!cur.size()) {
      cur.resize(i + 1);
      lf = i;
      ld = (t - x[i]) % MOD;
      continue;
    }
    long long k = -(x[i] - t) * qp(ld, MOD - 2) % MOD;
    vector<int> c(i - lf - 1);
    c.push_back(k);
    for (int j = 0; j < int(ls.size()); ++j) c.push_back(-ls[j] * k % MOD);
    if (c.size() < cur.size()) c.resize(cur.size());
    for (int j = 0; j < int(cur.size()); ++j) c[j] = (c[j] + cur[j]) % MOD;
    if (i - lf + (int)ls.size() >= (int)cur.size())
      ls = cur, lf = i, ld = (t - x[i]) % MOD;
    cur = c;
  }
  for (int i = 0; i < int(cur.size()); ++i) cur[i] = (cur[i] % MOD + MOD) % MOD;
  return cur;
}
int m;
long long a[233333], h[233333], t_[233333], s[233333], t[233333];
inline void mull(long long* p, long long* q) {
  for (int i = 0; i < m + m; ++i) t_[i] = 0;
  for (int i = 0; i < m; ++i)
    if (p[i])
      for (int j = 0; j < m; ++j) t_[i + j] = (t_[i + j] + p[i] * q[j]) % MOD;
  for (int i = m + m - 1; i >= m; --i)
    if (t_[i])
      for (int j = m - 1; ~j; --j)
        t_[i - j - 1] = (t_[i - j - 1] + t_[i] * h[j]) % MOD;
  for (int i = 0; i < m; ++i) p[i] = t_[i];
}
inline long long calc(long long K) {
  for (int i = m; ~i; --i) s[i] = t[i] = 0;
  s[0] = 1;
  if (m != 1)
    t[1] = 1;
  else
    t[0] = h[0];
  while (K) {
    if (K & 1) mull(s, t);
    mull(t, t);
    K >>= 1;
  }
  long long su = 0;
  for (int i = 0; i < m; ++i) su = (su + s[i] * a[i]) % MOD;
  return (su % MOD + MOD) % MOD;
}
inline int work(vector<int> x, long long n) {
  if (n < int(x.size())) return x[n];
  vector<int> v = BM(x);
  m = v.size();
  if (!m) return 0;
  for (int i = 0; i < m; ++i) h[i] = v[i], a[i] = x[i];
  return calc(n);
}
}  // namespace linear_seq
using linear_seq::work;
long long f[2000];
long long a[2000];
long long sum[2000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  f[1] = 1, f[2] = 2;
  for (int i = 3; i <= 1000; i++)
    f[i] = (f[i - 1] % MOD + f[i - 2] % MOD) % MOD;
  long long n, k;
  cin >> n >> k;
  vector<int> V;
  for (int i = 1; i <= 1000; i++) a[i] = (f[i] % MOD * qp(i, k) % MOD) % MOD;
  for (int i = 1; i <= 1000; i++) {
    sum[i] = (sum[i - 1] % MOD + a[i] % MOD) % MOD;
    V.push_back(sum[i]);
  }
  cout << work(V, n - 1) << endl;
  return 0;
}
