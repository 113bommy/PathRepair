#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(T a[], V sz);
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
template <class T, class V>
void _print(T a[], V sz) {
  for (V i = 0; i < sz; i++) {
    _print(a[i]);
    cerr << " ";
  }
  cerr << "\n";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr << "\n";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr << "\n";
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
long long mod = LONG_MAX;
long long add(long long a, long long b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long sub(long long a, long long b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
long long fe(long long base, long long exp) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = mul(ans, base);
    base = mul(base, base);
    exp >>= 1;
  }
  return ans;
}
long long fact(long long n) {
  long long res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}
long long modin(long long a) { return fe(a, mod - 2); }
long long nCr(long long a, long long b) {
  if (a < b) return 0;
  return mul(fact(a), mul(modin(fact(b)), modin(fact(a - b))));
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> eve, odd;
  for (int i = 1; i < 2 * n + 1; i++) {
    long long x;
    cin >> x;
    if (x % 2)
      odd.push_back(i);
    else
      eve.push_back(i);
  }
  for (int i = 0; i < n - 1; i++) {
    if (eve.size() > 1) {
      cout << eve[eve.size() - 1] << " ";
      eve.pop_back();
      cout << eve[eve.size() - 1] << "\n";
      eve.pop_back();
    } else {
      cout << odd[odd.size() - 1] << " ";
      odd.pop_back();
      cout << odd[odd.size() - 1] << "\n";
      odd.pop_back();
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
