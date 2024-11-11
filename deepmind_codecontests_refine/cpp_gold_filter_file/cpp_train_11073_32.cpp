#include <bits/stdc++.h>
using namespace std;
template <class A>
void read(vector<A>& v);
template <class A, size_t S>
void read(array<A, S>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t S>
void read(array<A, S>& x) {
  for (auto& a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (int i = (0); (1) > 0 ? i < ((int)v.size()) : i > ((int)v.size());
       i += (1))
    res += char('0' + v[i]);
  return res;
}
template <size_t S>
string to_string(bitset<S> b) {
  string res;
  for (int i = (0); (1) > 0 ? i < (S) : i > (S); i += (1))
    res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto& x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void write(A x) {
  cout << to_string(x);
}
template <class H, class... T>
void write(const H& h, const T&... t) {
  write(h);
  write(t...);
}
void print() { write("\n"); }
template <class H, class... T>
void print(const H& h, const T&... t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
void printGrid(vector<vector<int>> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = 0; j < (int)v[0].size(); j++) cout << v[i][j] << " ";
    cout << "\n";
  }
}
void SET(vector<int>& v, int c) {
  for (int i = 0; i < (int)v.size(); i++) v[i] = c;
}
void SET(vector<vector<int>>& v, int c) {
  for (int i = 0; i < (int)v.size(); i++)
    for (int j = 0; j < (int)v[0].size(); j++) v[i][j] = c;
}
vector<long long> primes;
vector<long long> PL;
long long pw(long long a, long long b, long long m) {
  a %= m;
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = (r * a) % m;
    a = (a * a) % m;
    b /= 2;
  }
  return r;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long fact(long long n, long long mod) {
  long long ret = 1;
  for (long long i = 1; i <= n; i++) ret = (ret * i) % mod;
  return ret;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void sieve(int M) {
  PL.assign(M + 1, 0);
  for (long long i = 2; i <= M; i++) {
    if (PL[i]) continue;
    PL[i] = i;
    primes.push_back(i);
    for (long long j = i * i; j <= M; j += i) PL[j] = i;
  }
}
vector<long long> prime_factors(long long n) {
  vector<long long> p;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      p.push_back(i);
      n /= i;
    }
  }
  if (n > 1) {
    p.push_back(n);
  }
  return p;
}
map<long long, long long> pf(long long n) {
  map<long long, long long> p;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      p[i]++;
      n /= i;
    }
  }
  if (n > 1) {
    p[n]++;
  }
  return p;
}
vector<long long> prime_factors_small(long long n) {
  vector<long long> p;
  while (n > 1) {
    long long now = PL[n];
    while (n % now == 0) {
      n /= now;
      p.push_back(now);
    }
  }
  return p;
}
map<long long, long long> pf_small(long long n) {
  map<long long, long long> p;
  while (n > 1) {
    long long now = PL[n];
    while (n % now == 0) {
      n /= now;
      p[now]++;
    }
  }
  return p;
}
void solve() {
  int n;
  read(n);
  if (n < 3) {
    cout << -1;
  } else {
    for (int i = 0; i < n; i++) {
      cout << n - i << " ";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
}
