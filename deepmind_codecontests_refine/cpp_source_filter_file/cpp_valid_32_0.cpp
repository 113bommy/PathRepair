#include <bits/stdc++.h>
using namespace std;
template <const int &MOD>
struct _m_int {
  int val;
  _m_int(int64_t v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = int(v);
  }
  _m_int(uint64_t v) {
    if (v >= MOD) v %= MOD;
    val = int(v);
  }
  _m_int(int v) : _m_int(int64_t(v)) {}
  _m_int(unsigned v) : _m_int(uint64_t(v)) {}
  static int inv_mod(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }
    return x < 0 ? x + m : x;
  }
  explicit operator int() const { return val; }
  explicit operator unsigned() const { return val; }
  explicit operator int64_t() const { return val; }
  explicit operator uint64_t() const { return val; }
  explicit operator double() const { return val; }
  explicit operator long double() const { return val; }
  _m_int &operator+=(const _m_int &other) {
    val -= MOD - other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  _m_int &operator-=(const _m_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    return unsigned(x % m);
    unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  _m_int &operator*=(const _m_int &other) {
    val = fast_mod(uint64_t(val) * other.val);
    return *this;
  }
  _m_int &operator/=(const _m_int &other) { return *this *= other.inv(); }
  friend _m_int operator+(const _m_int &a, const _m_int &b) {
    return _m_int(a) += b;
  }
  friend _m_int operator-(const _m_int &a, const _m_int &b) {
    return _m_int(a) -= b;
  }
  friend _m_int operator*(const _m_int &a, const _m_int &b) {
    return _m_int(a) *= b;
  }
  friend _m_int operator/(const _m_int &a, const _m_int &b) {
    return _m_int(a) /= b;
  }
  _m_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  _m_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  _m_int operator++(int) {
    _m_int before = *this;
    ++*this;
    return before;
  }
  _m_int operator--(int) {
    _m_int before = *this;
    --*this;
    return before;
  }
  _m_int operator-() const { return val == 0 ? 0 : MOD - val; }
  friend bool operator==(const _m_int &a, const _m_int &b) {
    return a.val == b.val;
  }
  friend bool operator!=(const _m_int &a, const _m_int &b) {
    return a.val != b.val;
  }
  friend bool operator<(const _m_int &a, const _m_int &b) {
    return a.val < b.val;
  }
  friend bool operator>(const _m_int &a, const _m_int &b) {
    return a.val > b.val;
  }
  friend bool operator<=(const _m_int &a, const _m_int &b) {
    return a.val <= b.val;
  }
  friend bool operator>=(const _m_int &a, const _m_int &b) {
    return a.val >= b.val;
  }
  _m_int inv() const { return inv_mod(val); }
  _m_int pow(int64_t p) const {
    if (p < 0) return inv().pow(-p);
    _m_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &os, const _m_int &m) {
    return os << m.val;
  }
};
extern const int MOD = 998244353;
using Mint = _m_int<MOD>;
const int LOGN = 19;
const int N = (1 << LOGN);
const int T = 2;
Mint g = 3;
vector<Mint> w[LOGN];
vector<int> rv[LOGN];
void precalc() {
  Mint wb = Mint(g).pow((MOD - 1) / (1 << LOGN));
  for (int st = 0; st < int(LOGN - 1); st++) {
    w[st].assign(1 << st, 1);
    Mint bw = wb.pow(1 << (LOGN - st - 1));
    Mint cw = 1;
    for (int k = 0; k < int(1 << st); k++) {
      w[st][k] = cw;
      cw *= bw;
    }
  }
  for (int st = 0; st < int(LOGN); st++) {
    rv[st].assign(1 << st, 0);
    if (st == 0) {
      rv[st][0] = 0;
      continue;
    }
    int h = (1 << (st - 1));
    for (int k = 0; k < int(1 << st); k++)
      rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
  }
}
void ntt(vector<Mint> &a, bool inv) {
  int n = ((int)((a).size()));
  int ln = __builtin_ctz(n);
  for (int i = 0; i < int(n); i++) {
    int ni = rv[ln][i];
    if (i < ni) swap(a[i], a[ni]);
  }
  for (int st = 0; st < int(ln); st++) {
    int len = 1 << st;
    for (int k = 0; k < n; k += (len << 1)) {
      for (int pos = int(k); pos < int(k + len); pos++) {
        Mint l = a[pos];
        Mint r = a[pos + len] * w[st][pos - k];
        a[pos] = l + r;
        a[pos + len] = l - r;
      }
    }
  }
  if (inv) {
    Mint rn = Mint(n).inv();
    for (int i = 0; i < int(n); i++) a[i] *= rn;
    reverse(a.begin() + 1, a.end());
  }
}
vector<Mint> mul(vector<Mint> a, vector<Mint> b) {
  int cnt =
      1 << (32 - __builtin_clz(((int)((a).size())) + ((int)((b).size())) - 1));
  a.resize(cnt);
  b.resize(cnt);
  ntt(a, false);
  ntt(b, false);
  vector<Mint> c(cnt);
  for (int i = 0; i < int(cnt); i++) c[i] = a[i] * b[i];
  ntt(c, true);
  while (c.size() > 1 && c.back() == 0) c.pop_back();
  return c;
}
struct dp {
  vector<Mint> val[T][T];
  bool is_unit;
  dp(){};
  dp(int len) {
    is_unit = len == 1;
    for (int j = 0; j < T; j++)
      for (int k = 0; k < T; k++) val[j][k] = {0};
    if (len == 1)
      val[0][0][0] = 1;
    else
      val[1][1][0] = 2;
  }
  dp(const dp &a, const dp &b) {
    is_unit = false;
    for (int l1 = 0; l1 < T; l1++)
      for (int r1 = 0; r1 < T; r1++)
        for (int l2 = 0; l2 < T; l2++)
          for (int r2 = 0; r2 < T; r2++) {
            vector<Mint> cur = mul(a.val[l1][r1], b.val[l2][r2]);
            if (val[l1][r2].size() < cur.size()) val[l1][r2].resize(cur.size());
            for (int i = 0; i < cur.size(); i++) val[l1][r2][i] += cur[i];
            Mint merge_coeff = 2;
            if (r1 == 1) merge_coeff /= 2;
            if (l2 == 1) merge_coeff /= 2;
            cur.insert(cur.begin(), 0);
            for (int i = 0; i < cur.size(); i++) cur[i] *= merge_coeff;
            int L1 = 1;
            int R2 = 1;
            if (a.is_unit) L1 = 1;
            if (b.is_unit) R2 = 1;
            if (val[L1][R2].size() < cur.size()) val[L1][R2].resize(cur.size());
            for (int i = 0; i < cur.size(); i++) {
              val[L1][R2][i] += cur[i];
            }
          }
  }
};
ostream &operator<<(ostream &out, const dp &a) {
  for (int i = 0; i < T; i++)
    for (int j = 0; j < T; j++) {
      out << "[" << i << "][" << j << "]";
      for (auto x : a.val[i][j]) out << " " << x;
      out << endl;
    }
  return out;
}
int a[N];
int len[N];
Mint fact[N];
int n;
int s;
dp build(int l, int r) {
  if (l == r - 1) {
    dp res(len[l]);
    return res;
  } else {
    int m = (l + r) / 2;
    dp res(build(l, m), build(m, r));
    return res;
  }
}
int main() {
  precalc();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int cur = 0;
  while (cur != n) {
    if (cur + a[cur] > n) {
      cout << 0 << endl;
      return 0;
    }
    for (int l = cur; l < cur + a[cur]; l++)
      if (a[l] != a[cur]) {
        cout << 0 << endl;
        return 0;
      }
    len[s++] = a[cur];
    cur += a[cur];
  }
  fact[0] = 1;
  for (int i = 1; i <= s; i++) fact[i] = i * fact[i - 1];
  dp res = build(0, s);
  Mint ans = 0;
  for (int i = 0; i < s; i++)
    for (int j = 0; j < T; j++)
      for (int k = 0; k < T; k++)
        if (res.val[j][k].size() > i)
          ans += fact[s - i] * res.val[j][k][i] * (i % 2 == 0 ? 1 : MOD - 1);
  cout << ans << endl;
}
