#include <bits/stdc++.h>
using namespace std;
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
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void c_p_c() {}
class DisjointSet {
  unordered_map<int, int> parent;

 public:
  void makeSet(int N) {
    for (int i = 0; i < N; i++) parent[i] = i;
  }
  int Find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
  }
  void Union(int a, int b) {
    int x = Find(a);
    int y = Find(b);
    parent[x] = y;
  }
};
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void PrimeFactors(long long n) {
  while (n % 2 == 0) {
    cout << 2 << " ";
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      cout << i << " ";
      n = n / i;
    }
  }
  if (n > 2) cout << n << " ";
}
template <typename T>
void parray(T a[], T n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
vector<long long> uniqueelement(vector<long long> &a) {
  auto ip = unique((a).begin(), (a).end());
  a.resize(distance(a.begin(), ip));
  return a;
}
bool IsPrime(long long x) {
  if (x == 1) return false;
  for (int i = 2; 1ll * i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void leftrotate(string &s, int d) {
  reverse(s.begin(), s.begin() + d);
  reverse(s.begin() + d, s.end());
  reverse(s.begin(), s.end());
}
void rightrotate(string &s, int d) { leftrotate(s, s.length() - d); }
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<long long> sieve() {
  vector<long long> primes;
  bool a[1000000] = {0};
  int mprimes = 1000000;
  a[0] = a[1] = true;
  for (int i = 2; i * i < mprimes; ++i) {
    if (a[i] == false) {
      for (int j = i * i; j < mprimes; j = j + i) {
        a[j] = true;
      }
    }
  }
  for (int i = 2; i < mprimes; ++i) {
    if (!a[i]) primes.push_back(i);
    ;
  }
  return primes;
}
void Ynot() {
  long long i, n, m, k, c = 0, sum = 0;
  bool flag = false;
  cin >> n;
  int ans = (n + 2) / 2;
  ;
  cout << ans << "\n";
  for (int i = 0; i < n and i < ans; ++i) {
    cout << 1 << " " << i + 1 << "\n";
  }
  for (int i = 1; i < n - ans; ++i) {
    cout << i + 1 << " " << ans << "\n";
  }
}
int main() {
  c_p_c();
  int t = 1;
  for (int i = 0; i < t; i++) {
    Ynot();
  }
  return 0;
}
