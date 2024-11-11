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
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(unordered_set<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(long long a, long long b, long long *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mminv(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
bool revsort(long long a, long long b) { return a > b; }
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
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
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
long long phin(long long n) {
  long long number = n;
  if (n % 2 == 0) {
    number /= 2;
    while (n % 2 == 0) n /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1) number = (number / n * (n - 1));
  return number;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int a = s[i] - '0' - 1;
    v[i] = a;
  }
  unordered_map<int, int> m;
  m[0] = 1;
  int curSum = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    curSum += v[i];
    ans += m[curSum];
    m[curSum] += 1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start1 = high_resolution_clock::now();
  long long T = 1;
  cin >> T;
  for (long long t = 1; t <= T; t++) {
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
