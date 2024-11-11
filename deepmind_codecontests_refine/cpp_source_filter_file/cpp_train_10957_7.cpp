#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
T lcm(T a, T b) {
  return (a * b) / __gcd(a, b);
}
template <class T>
T ceil(T numerator, T denominator) {
  return (numerator + denominator - 1) / denominator;
}
template <class T>
bool isPrime(T N) {
  for (T i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}
template <class T>
T cbrt(T x) {
  T lo = 1, hi = min(2000000ll, x);
  while (hi - lo > 1) {
    T mid = (lo + hi) / 2;
    if (mid * mid * mid < x) {
      lo = mid;
    } else
      hi = mid;
  }
  if (hi * hi * hi <= x)
    return hi;
  else
    return lo;
}
template <class T>
T sqrt(T target) {
  T l = 1, r = target;
  while (r > l + 1) {
    T m = (l + r) / 2;
    if (m * m <= target)
      l = m;
    else
      r = m;
  }
  return l;
}
template <class T>
T bin_power(T a, T b, T mod) {
  T res = 1;
  while (b > 0) {
    if (b & 1) res = ((res % mod) * (a % mod)) % mod;
    a = ((a % mod) * (a % mod)) % mod;
    b = b >> 1;
  }
  return res;
}
int mod_inv(int a, int b) { return bin_power(a, b - 2, b); }
int mod_add(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
int mod_div(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mod_inv(b, m), m) + m) % m;
}
const long long int mod = 1000000007;
void solve() {
  long long int n;
  string s, t;
  cin >> n >> s >> t;
  vector<long long int> op1, op2;
  for (long long int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) op1.push_back(i);
    if (t[i] != t[i - 1]) op2.push_back(i);
  }
  if (s[n - 1] != t[n - 1]) op1.push_back(n);
  op1.insert(op1.end(), op2.rbegin(), op2.rend());
  cout << op1.size();
  for (auto x : op1) cout << x << " ";
  cout << '\n';
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
