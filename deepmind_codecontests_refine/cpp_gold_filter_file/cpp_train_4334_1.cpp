#include <bits/stdc++.h>
using namespace std;
const int N = 55;
struct matrix_t {
  bitset<N> row[N], col[N];
  int n;
  void resize(int _n) {
    n = _n;
    for (int i = 1; i <= n; ++i) {
      row[i].reset();
      col[i].reset();
    }
  }
  void output() {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) printf("%d ", row[i].test(j));
      puts("");
    }
  }
  matrix_t(int _n = 0) { resize(_n); }
  void set(int x, int y, int v) {
    if (x > n || y > n) throw;
    row[x].set(y, v);
    col[y].set(x, v);
  }
  matrix_t &operator=(const matrix_t &b) {
    copy(b.row + 1, b.row + 1 + n, row + 1);
    copy(b.col + 1, b.col + 1 + n, col + 1);
    return *this;
  }
  bool operator==(const matrix_t &b) const {
    for (int i = 1; i <= n; ++i)
      if (row[i] != b.row[i]) return false;
    return true;
  }
  matrix_t operator*(const matrix_t &b) const {
    matrix_t r(n);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) r.set(i, j, (row[i] & b.col[j]).count() & 1);
    return r;
  }
  static matrix_t identity(int n) {
    matrix_t r(n);
    for (int i = 1; i <= n; ++i) r.set(i, i, 1);
    return r;
  }
};
struct fastpow_t {
  matrix_t S, C, R;
  bool check(long long n) {
    C = S;
    R = matrix_t::identity(S.n);
    for (; n; n >>= 1, C = C * C)
      if (n & 1) R = R * C;
    return R == S;
  }
  void resize(int n) {
    S.resize(n);
    C.resize(n);
    R.resize(n);
  }
};
fastpow_t F;
struct seive_t {
  vector<long long> primes, nonpr;
  seive_t(long long lim) {
    nonpr.resize(lim + 1);
    for (long long i = 2; i <= lim; ++i) {
      if (!nonpr[i]) primes.push_back(i);
      for (long long j : primes) {
        if (i * j > lim) break;
        nonpr[i * j] = 1;
        if (i % j == 0) break;
      }
    }
  }
  vector<long long> factorize(long long p) {
    vector<long long> res;
    for (long long j : primes)
      if (p % j == 0) {
        while (p % j == 0 && p) p /= j;
        res.push_back(j);
      }
    if (p > 1) res.push_back(p);
    return res;
  }
} S(int(1e6) + 5);
long long k, period;
vector<long long> pflist;
bool check(bitset<N> &C) {
  C.test(0);
  for (int i = 1; i <= k; ++i) F.S.set(k, i, C[i]);
  if (!F.check(period + 1)) return false;
  for (long long j : pflist)
    if (j != period && F.check(period / j + 1)) return false;
  return true;
}
int main() {
  cin >> k;
  period = (1LL << k) - 1LL;
  pflist = S.factorize(period);
  F.resize(k);
  for (int i = 1; i < k; ++i) F.S.set(i, i + 1, 1);
  while (1) {
    bitset<N> C;
    for (int i = 1; i <= k; ++i) C.set(i, rand() & 1);
    if (check(C)) {
      for (int i = k; i >= 1; --i) cout << C[i] << " \n"[i == 1];
      for (int i = 1; i < k; ++i) cout << "0 ";
      cout << 1 << endl;
      break;
    }
  }
  return 0;
}
