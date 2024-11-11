#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
long long int INF = 9e18;
long long int power(long long int base, long long int exp) {
  long long int res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    base = (base * base);
    exp /= 2;
  }
  return res;
}
long long int bitc(long long int n, long long int x) { return ((n >> x) & 1); }
long long int __gcd(long long int a, long long int b) {
  return b == 0 ? a : __gcd(b, a % b);
}
long long int fsub(long long int a, long long int b, long long int p = MOD) {
  return ((a % p) - (b % p) + p) % p;
}
long long int fmult(long long int a, long long int b, long long int p = MOD) {
  return ((a % p) * (b % p)) % p;
}
long long int fadd(long long int a, long long int b, long long int p = MOD) {
  return (a % p + b % p) % p;
}
long long int fpow(long long int n, long long int k, long long int p = MOD) {
  long long int r = 1;
  while (k > 0) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
    k = k >> 1;
  }
  return r;
}
long long int inv(long long int a, long long int p = MOD) {
  return fpow(a, p - 2, p);
}
long long int fdiv(long long int a, long long int b, long long int p = MOD) {
  long long int yinv = inv(b);
  long long int ans = (a * yinv) % p;
  return ans;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &a) {
  for (auto &item : a) {
    in >> item;
  }
  return in;
}
template <typename T, typename U>
ostream &operator<<(ostream &out, pair<T, U> &a) {
  cout << a.first << " " << a.second;
  return out;
}
template <typename T, typename U>
istream &operator>>(istream &out, pair<T, U> &a) {
  cin >> a.first >> a.second;
  return out;
}
template <typename T, typename U>
ostream &operator<<(ostream &out, map<T, U> &a) {
  for (auto &item : a) {
    out << item << "\n";
  }
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &item : a) {
    out << item << " ";
  }
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &a) {
  for (auto &item : a) {
    out << item << "\n";
  }
  return out;
}
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};
std::vector<bool> is_prime;
std::vector<long long int> primes;
void sieve(long long int n) {
  is_prime.resize(n + 2, true);
  primes.clear();
  long long int p;
  for (p = 2; p * p <= n; p++) {
    if (is_prime[p]) {
      long long int i;
      for (i = p * p; i <= n; i += p) {
        is_prime[i] = false;
      }
    }
  }
  is_prime[0] = is_prime[1] = false;
  long long int i;
  for (i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.emplace_back(i);
    }
  }
}
map<long long int, long long int> prime_factors(long long int n) {
  map<long long int, long long int> s;
  long long int i;
  long long int tc = 0;
  while (n % 2 == 0) {
    tc++;
    n /= 2;
  }
  if (tc > 0) {
    s[2] = tc;
  }
  for (i = 3; i <= sqrt(n); i += 2) {
    tc = 0;
    while (n % i == 0) {
      tc++;
      n /= i;
    }
    if (tc > 0) {
      s[i] = tc;
    }
  }
  if (n > 2) {
    s[n] += 1;
  }
  return s;
}
std::vector<long long int> fact_vec;
void fact_fun(long long int n) {
  fact_vec.resize(n + 10);
  long long int i;
  fact_vec[0] = 1;
  for (i = 1; i <= n + 2; i++) {
    fact_vec[i] = (fact_vec[i - 1] * i) % MOD;
  }
}
std::vector<long long int> p2;
void power_2(long long int n, long long int m = MOD) {
  long long int i;
  MOD = m;
  p2.emplace_back(1);
  for (i = 0; i < n; i++) {
    p2.emplace_back(fmult(p2.back(), 2));
  }
}
long long int ncr(long long int n, long long int r) {
  if (r > n) return 0;
  return fdiv(fact_vec[n], fmult(fact_vec[r], fact_vec[n - r]));
}
std::vector<long long int> spf;
void sieve2(long long int MAXN) {
  MAXN += 10;
  spf.resize(MAXN, 0);
  spf[1] = 1;
  for (long long int i = 2; i < MAXN; i++) spf[i] = i;
  for (long long int i = 4; i < MAXN; i += 2) spf[i] = 2;
  for (long long int i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (long long int j = i * i; j < MAXN; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
}
const int mi[4] = {-1, 0, 1, 0}, mj[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
map<long long int, long long int> getFactorization(long long int x) {
  map<long long int, long long int> ret;
  while (x != 1) {
    ret[spf[x]]++;
    x = x / spf[x];
  }
  return ret;
}
long long int solve(long long int a, long long int b, long long int c,
                    long long int l) {
  long long int i;
  long long int ans = 0;
  for (i = 0; i <= l; i++) {
    long long int na = a + i;
    if (na >= b + c) {
      long long int x = min(l - i, a + i - (b + c));
      ans += ((x + 1) * (x + 2)) / 2;
    }
  }
  return ans;
}
int main() {
  long long int i, j;
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int ti;
  ti = 1;
  while (ti--) {
    long long int a, b, c, l;
    cin >> a >> b >> c >> l;
    long long int ans = ((l + 1) * (l + 2) * (l + 3)) / 6;
    ans -= solve(a, b, c, l);
    ans -= solve(b, a, c, l);
    ans -= solve(c, b, a, l);
    cout << ans << "\n";
  }
}
