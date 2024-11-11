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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1e18L;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
const long long nax = 1e6 + 5;
const long long prime = 31;
vector<long long> pi(nax), h(nax), p(nax);
string s;
void prf() {
  long long n = (long long)s.size();
  for (long long i = 1; i < n; i++) {
    long long l = pi[i - 1];
    while (l && s[i] != s[l]) {
      l = pi[l - 1];
    }
    if (s[i] == s[l]) l++;
    pi[i] = l;
  }
}
void init() {
  prf();
  long long n = (long long)s.size();
  p[0] = 1;
  for (long long i = 1; i < n; i++) {
    (p[i] = p[i - 1] * prime) %= mod;
  }
  for (long long i = 0; i < n; i++) {
    (h[i + 1] = h[i] + (s[i] - 'a' + 1) * p[i] % mod) %= mod;
  }
}
bool search(long long len) {
  long long x = h[len], n = (long long)s.size(), cnt = 0;
  for (long long i = 0; i + len - 1 < n; i++) {
    long long cur = (h[i + len] - h[i] + mod) % mod;
    if (cur == x * p[i] % mod) cnt++;
  }
  if (cnt == 3) return true;
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> s;
  init();
  long long n = (long long)s.size(), len;
  len = pi[n - 1];
  while (len) {
    if (search(len)) {
      break;
    } else {
      len = pi[len - 1];
    }
  }
  if (len) {
    cout << s.substr(0, len) << "\n";
  } else {
    cout << "Just a legend\n";
  }
  return 0;
}
