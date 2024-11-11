#include <bits/stdc++.h>
using namespace std;
long long MOD;
long long mul(long long a, long long b) {
  if (a < 1024) return a * b % MOD;
  return ((mul(a >> 10, b) << 10) + (a & 1023) * b) % MOD;
}
struct Int {
  long long x;
  Int() : x(0) {}
  Int(long long _x) {
    x = _x % MOD;
    if (x < 0) x += MOD;
  }
  static Int get(long long x) {
    Int a;
    a.x = x;
    return a;
  }
  Int operator+(const Int& o) const {
    long long t = x + o.x;
    if (t >= MOD) t -= MOD;
    return get(t);
  }
  Int operator*(const Int& o) const { return get(mul(x, o.x)); }
  Int operator-(const Int& o) const {
    long long t = x - o.x;
    if (t < 0) t += MOD;
    return get(t);
  }
  Int operator/(const Int& o) const { return (*this) * o.inv(); }
  Int& operator+=(const Int& o) { return (*this) = *this + o; }
  Int& operator-=(const Int& o) { return (*this) = *this - o; }
  Int& operator*=(const Int& o) { return (*this) = *this * o; }
  Int& operator/=(const Int& o) { return (*this) = *this / o; }
  Int power(long long n) const {
    if (!n) return get(1);
    const Int& a = *this;
    if (n & 1)
      return power(n - 1) * a;
    else
      return (a * a).power(n >> 1);
  }
  Int inv() const { return power(MOD - 2); }
  bool operator==(const Int& o) const { return x == o.x; }
  bool operator!=(const Int& o) const { return x != o.x; }
};
vector<vector<Int> > zero(int n) {
  return vector<vector<Int> >(n, vector<Int>(n, 0));
}
vector<vector<Int> > unit(int n) {
  vector<vector<Int> > a = zero(n);
  for (int i = 0; i < n; ++i) {
    a[i][i] = 1;
  }
  return a;
}
vector<vector<Int> > operator*(vector<vector<Int> > a, vector<vector<Int> > b) {
  int n = a.size();
  vector<vector<Int> > c = zero(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}
vector<vector<Int> > operator+(vector<vector<Int> > a, vector<vector<Int> > b) {
  int n = a.size();
  vector<vector<Int> > c = zero(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}
vector<Int> operator*(vector<Int> a, vector<vector<Int> > m) {
  int n = a.size();
  vector<Int> c(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      c[j] += a[i] * m[i][j];
    }
  }
  return c;
}
vector<vector<Int> > matPow(vector<vector<Int> > a, long long e) {
  if (!e) return unit(a.size());
  return (e & 1) ? matPow(a, e - 1) * a : matPow(a * a, e >> 1);
}
Int fib(long long n) {
  vector<vector<Int> > t = zero(2);
  t[1][0] = t[0][1] = t[1][1] = 1;
  return matPow(t, n)[1][0];
}
int main() {
  int f;
  cin >> f;
  vector<long long> id;
  long long cyc = 1;
  id.push_back(0);
  MOD = 1;
  for (int it = 0; it < 26; ++it) {
    int x = it < 13 ? 2 : 5;
    MOD *= x;
    long long ncyc = cyc;
    while (fib(ncyc) != 0 || fib(ncyc + 1) != 1) {
      ncyc += cyc;
    }
    long long period = ncyc / cyc;
    vector<long long> nid;
    for (vector<long long>::iterator e = id.begin(); e != id.end(); ++e) {
      for (int i = 0; i < period; ++i) {
        if (fib(*e + i * cyc) == f) nid.push_back(*e + i * cyc);
      }
    }
    id = nid;
    cyc = ncyc;
  }
  if (id.empty()) {
    puts("-1");
  } else {
    cout << *min_element(id.begin(), id.end()) << endl;
  }
  return 0;
}
