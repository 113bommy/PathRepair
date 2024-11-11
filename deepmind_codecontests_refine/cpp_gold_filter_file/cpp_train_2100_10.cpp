#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
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
  cerr << "]" << endl;
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
  cerr << "]"
       << "]" << endl;
}
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
void print(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << '\n';
}
template <typename T>
void print(vector<vector<T>>& v) {
  for (vector<T>& vv : v) {
    for (T& i : vv) cout << i << " ";
    cout << '\n';
  }
}
template <typename T>
void read(vector<T>& v) {
  for (T& i : v) cin >> i;
}
template <typename T>
void read(T&& t) {
  cin >> t;
}
template <typename T, typename... Args>
void read(T&& t, Args&&... args) {
  cin >> t;
  read(forward<Args>(args)...);
}
template <typename T>
void print(T&& t) {
  cout << t << '\n';
}
template <typename T, typename... Args>
void print(T&& t, Args&&... args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
long double pie = 3.141592653589793238462643383279502884197169399;
bool isprime(long long n) {
  if (n <= 1) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
long long modInverse(long long n, long long mod) {
  return binpow(n, mod - 2, mod);
}
long long comb(long long n, long long r, long long p) {
  if (r == 0 or n == r) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= p;
  }
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
set<long long> divisors(long long n) {
  set<long long> s;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  return s;
}
set<long long> primess;
void seive() {
  vector<int> is_prime(1e6 + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= 1e6; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= 1e6; j += i) is_prime[j] = false;
    }
  }
  for (int i = 2; i <= 1e6; i++) {
    if (is_prime[i]) {
      primess.insert(i);
    }
  }
}
map<long long, long long> primeFactors(long long n) {
  map<long long, long long> m;
  while (n % 2 == 0) {
    m[2]++;
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      m[i]++;
      n = n / i;
    }
  }
  if (n > 2) m[n]++;
  return m;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}
long long C(long long n, long long r) {
  long long res = 1;
  for (long long i = 0; i < r; i++) {
    res = res * (n - i) / (i + 1);
  }
  return res;
}
long long toint(string s) {
  long long num = 0;
  for (long long i = 0; i < s.size(); i++) {
    num = num * 10 + s[i] - '0';
  }
  return num;
}
long long sumstring(string s) {
  long long sum = 0;
  for (long long i = 0; i < s.size(); i++) {
    sum += (s[i] - '0');
  }
  return sum;
}
long long sumdigit(long long n) {
  long long sum = 0;
  while (n) {
    long long rem = n % 10;
    sum += rem;
    n /= 10;
  }
  return sum;
}
string tobinary(long long x) {
  string a;
  while (x > 0) {
    a += (x % 2) + '0';
    x /= 2;
  }
  reverse(begin(a), end(a));
  return a;
}
long long todecimal(string x) {
  long long sum = 0;
  long long n = x.size();
  long long j = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (x[i] == '1') {
      sum += (1LL << j);
    }
    j++;
  }
  return sum;
}
long long ceil(long long n, long long k) { return (n + k - 1) / k; }
bool ispalin(string s) {
  long long n = s.size();
  for (long long i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}
bool ispermutation(vector<long long> p) {
  sort(begin(p), end(p));
  for (long long i = 1; i <= p.size(); i++) {
    if (p[i - 1] != i) return false;
  }
  return true;
}
bool isperfect(long long x) {
  long long a = sqrtl(x);
  return a * a == x;
}
bool issubsequence(string t, string x) {
  long long j = 0;
  for (long long i = 0; i < x.size(); i++) {
    if (x[i] == t[j]) {
      j++;
    }
    if (j == t.size()) break;
  }
  return j == t.size();
}
long long power(long long base, long long exponent) {
  long long res = 1;
  while (exponent) {
    if (exponent & 1) {
      res = res * base;
    }
    base *= base;
    exponent >>= 1;
  }
  return res;
}
bool comp(string a, string b) {
  int aLen = a.length(), bLen = b.length();
  for (int i = 0; i < min(aLen, bLen); i++)
    if (a[i] != b[i]) return a[i] < b[i];
  if (aLen <= bLen) return true;
  return false;
}
void solve() {
  long long n, b;
  cin >> n >> b;
  vector<long long> v(n);
  cin >> v;
  vector<pair<long long, long long>> op;
  for (long long i = 0; i < b; i++) {
    long long d, g;
    cin >> d >> g;
    op.push_back({d, g});
  }
  sort(begin(op), end(op));
  vector<long long> gold(b);
  for (long long i = 0; i < b; i++) {
    gold[i] = op[i].second;
  }
  vector<long long> pre(b);
  pre[0] = gold[0];
  for (long long i = 1; i < b; i++) {
    pre[i] = pre[i - 1] + gold[i];
  }
  long long inf = 1e18;
  for (long long i = 0; i < n; i++) {
    auto it = upper_bound(begin(op), end(op), make_pair(v[i], inf));
    long long ind = it - op.begin() - 1;
    if (ind < 0)
      cout << 0 << ' ';
    else
      cout << pre[ind] << ' ';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
