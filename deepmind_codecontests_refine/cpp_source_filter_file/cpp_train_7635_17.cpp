#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
  cerr << "]" << endl;
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
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long power(long long x, unsigned long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mod_inverse(long long a, long long p) { return power(a, p - 2, p); }
void swap(long long &x, long long &y) {
  long long temp = x;
  x = y;
  y = temp;
}
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mod_inverse(b, m), m) + m) % m;
}
long long modfact(long long n, long long p) {
  if (p <= n) return 0;
  long long res = (p - 1);
  for (long long i = n + 1; i < p; i++) res = (res * mod_inverse(i, p)) % p;
  return res;
}
long long fact(long long n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}
void solve() {
  long long n;
  cin >> n;
  vector<map<long long, long long>> v(n);
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    long long p = 0;
    for (long long j = 0; j < k; j++) {
      long long x;
      cin >> x;
      v[i].insert({x, 1});
    }
    for (auto j : v[i]) {
      v[i][j.first] = p++;
    }
    a[i] = p;
  };
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (auto it = v[i].begin(); it != v[i].end(); it++) {
      auto it2 = it;
      it2++;
      if (it2 == v[i].end()) break;
      long long lef = 0, rig = 0;
      long long l = mod_add(i, -1, n);
      long long r = mod_add(i, 1, n);
      long long v1 = it->first;
      long long v2 = it2->first;
      auto z2 = v[l].lower_bound(v2);
      auto z1 = v[l].lower_bound(v1);
      long long d1 = z1->second, d2 = z2->second;
      if (z1 == v[l].end()) {
        d1 = a[i];
      }
      if (z2 == v[l].end()) {
        d2 = a[i];
      }
      lef = d2 - d1;
      z2 = v[r].lower_bound(v2);
      z1 = v[r].lower_bound(v1);
      d1 = z1->second, d2 = z2->second;
      if (z1 == v[r].end()) {
        d1 = a[i];
      }
      if (z2 == v[r].end()) {
        d2 = a[i];
      }
      rig = d2 - d1;
      if (rig != lef) {
        ans++;
      }
    }
  }
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
