#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:16777216")
const double EPS = 1e-7;
double iabs(const double a) { return (a < -EPS) ? -a : a; }
double imin(const double a, const double b) { return (a - b > EPS) ? b : a; }
double imax(const double a, const double b) { return (a - b > EPS) ? a : b; }
template <class I>
I iabs(const I a) {
  return (a < 0) ? -a : a;
}
template <class I>
I imin(const I a, const I b) {
  return (a < b) ? a : b;
}
template <class I>
I imax(const I a, const I b) {
  return (a < b) ? b : a;
}
template <class I>
inline I mod_pow(const I& x, const long long p, const I& m) {
  if (p == 0) return 1;
  I mult = (p & 1) ? x : 1;
  I t = mod_pow(x, p / 2, m) % m;
  return (((mult * t) % m) * t) % m;
}
template <class T>
inline T ipow(const T& x, const long long p) {
  if (p == 0) return 1;
  T mult = (p & 1) ? x : 1;
  T h = ipow(x, p / 2);
  return h * h * mult;
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <class T>
T next_power_of_two(T v) {
  if (v < 0) return 0;
  v--;
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v |= v >> 32;
  v++;
  return v;
}
string bin(unsigned int i) {
  string res = "";
  while (i != 0) {
    res += ('0' + (i % 2));
    i = i / 2;
  }
  return string(res.rbegin(), res.rend());
}
template <int SIZE>
class DSU {
 public:
  int parent[SIZE];
  int rank[SIZE];
  int count;
  void clear() {
    for (int i = 0; i < SIZE; i++) {
      this->parent[i] = -1;
      this->rank[i] = 0;
    }
    this->count = 0;
  }
  DSU() { this->clear(); }
  void make(int x) {
    this->parent[x] = x;
    this->rank[x] = 1;
    this->count++;
  }
  bool in_a_set(int x) { return this->parent[x] != -1; }
  int find(int x) {
    if (x == this->parent[x]) return x;
    return this->parent[x] = find(this->parent[x]);
  }
  void combine(int x, int y) {
    x = this->find(x);
    y = this->find(y);
    if (x != y) {
      if (this->rank[x] > this->rank[y])
        this->parent[x] = y;
      else
        this->parent[y] = x;
      this->count--;
    }
  }
};
class BigInt {
 public:
  const static unsigned int N = 1000;
  const static unsigned int base = 10;
  unsigned int len;
  short sign;
  unsigned int digits[N];
  BigInt(const BigInt& bi) {
    this->len = bi.len;
    this->sign = bi.sign;
    for (unsigned int i = 0; i < this->len; ++i) (*this)[i] = bi[i];
  }
  BigInt(long long n) {
    this->len = 0;
    this->sign = (n >= 0) ? 1 : -1;
    this->digits[0] = 0;
    while (n) {
      this->digits[this->len] = n % this->base;
      n /= this->base;
      this->len++;
    }
    if (this->len == 0) this->len = 1;
  }
  BigInt(string s) {
    this->sign = (s[0] == '-') ? 1 : -1;
    this->digits[0] = 0;
    if (s[0] == '-') s = s.substr(1, s.length() - 1);
    this->len = s.length();
    for (unsigned int i = 0; i < this->len; i++)
      (*this)[i] = s[this->len - i - 1] - '0';
  }
  string toString() const {
    stringstream ss;
    for (int i = this->len - 1; i >= 0; --i) ss << (*this)[i];
    return ss.str();
  }
  unsigned int& operator[](const unsigned int i) { return digits[i]; }
  unsigned int operator[](const unsigned int i) const {
    if (i < this->len) return this->digits[i];
    return 0;
  }
  bool iszero() const {
    if (this->len <= 1 && this->digits[0] == 0) return true;
    return false;
  }
  BigInt& operator=(const BigInt& rval) {
    if (this != &rval) {
      this->len = rval.len;
      this->sign = rval.sign;
      for (unsigned int i = 0; i < this->len; ++i) (*this)[i] = rval[i];
    }
    return *this;
  }
  BigInt operator+(const BigInt& rhs) const {
    BigInt s(0);
    unsigned long long r = 0, d, i;
    for (i = 0; i < max(this->len, rhs.len); i++) {
      d = (*this)[i] + rhs[i] + r;
      r = d / this->base;
      s[i] = d % this->base;
    }
    s.len = max(this->len, rhs.len);
    if (r) s[s.len++] = r;
    return s;
  }
  BigInt operator+(unsigned long long rhs) const {
    BigInt s(*this);
    unsigned long long r = 0, d, i = 0;
    while (rhs != 0 || r != 0) {
      d = s[i] + (rhs % s.base) + r;
      rhs /= s.base;
      r = d / s.base;
      s[i] = d % s.base;
      i++;
    }
    if (i > s.len) s.len = i;
    return s;
  }
  BigInt operator*(unsigned long long rhs) const {
    if (rhs == 0) return BigInt(0);
    BigInt s(*this);
    unsigned long long r = 0, d, i;
    for (i = 0; i < s.len; ++i) {
      d = s[i] * rhs + r;
      r = d / this->base;
      s[i] = d % this->base;
    }
    while (r) s[s.len++] = r % this->base, r /= this->base;
    return s;
  }
  BigInt operator*(const BigInt& rhs) const {
    BigInt s(0);
    if (rhs.iszero()) return s;
    unsigned long long r, d, i, j, k;
    for (i = 0; i < this->N; i++) s[i] = 0;
    for (i = 0; i < this->len; i++) {
      r = 0;
      for (j = 0, k = i; j < rhs.len; j++, k++) {
        d = (*this)[i] * rhs[j] + r + s[k];
        r = d / this->base;
        s[k] = d % this->base;
      }
      while (r) s[k++] = r % this->base, r /= this->base;
      if (k > s.len) s.len = k;
    }
    while (s.len > 1 && s[s.len - 1] == 0) s.len--;
    return s;
  }
  unsigned int operator%(unsigned int rhs) {
    BigInt t(*this);
    unsigned long long pow = 1;
    unsigned long long mod = 0;
    for (unsigned int i = 0; i < this->len && pow != 0; i++) {
      mod = (((*this)[i] % rhs) * pow + mod) % rhs;
      pow = (pow * this->base) % rhs;
    }
    return mod;
  }
};
vector<long long> genprimes(const int n) {
  vector<long long> res;
  res.push_back(2);
  long long m, t, j;
  for (int i = 3; i <= n; i++) {
    j = 0;
    m = res.size();
    t = (long long)sqrt(i * 1.0) + 1;
    while (j < m && res[j] < t && i % res[j] != 0) j++;
    if (j == m || res[j] >= t) res.push_back(i);
  }
  return res;
}
long long reverse_intereger(long long a) {
  int res = 0;
  while (a != 0) res = 10 * res + (a % 10), a /= 10;
  return res;
}
const long long INF = 1000 * 1000 * 1000 + 100;
const long long N = 1000 + 10;
const long long M = 1000 + 10;
int n, i, j, k, h;
int a[N];
int main(int argc, char* argv[]) {
  cin >> n >> k;
  for (i = 0; i < n; ++i) cin >> a[i + 1];
  int minsteps = INF;
  int goodheight = 0;
  for (h = 1; h <= 1000; ++h) {
    int steps = 0;
    for (i = 1; i <= n; ++i)
      if (a[i] != a[1] + (i - 1) * k) steps++;
    if (steps < minsteps) {
      minsteps = steps;
      goodheight = h;
    }
  }
  cout << minsteps << endl;
  for (i = 1; i <= n; ++i) {
    if (a[i] > goodheight + (i - 1) * k) {
      cout << "- " << i << " " << a[i] - goodheight - (i - 1) * k << endl;
    } else if (a[i] < goodheight + (i - 1) * k) {
      cout << "+ " << i << " " << goodheight + (i - 1) * k - a[i] << endl;
    }
  }
}
