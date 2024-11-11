#include <bits/stdc++.h>
using namespace std;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 ran(seed);
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
clock_t start = clock();
int gcd(int a, int b) { return (a == 0) ? b : gcd(b % a, a); }
int power(int a, int n) {
  int p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
int powm(int a, int n, int mod_) {
  int p = 1;
  while (n) {
    if (n % 2) {
      p = (((p % mod_) * 1LL * (a % mod_)) % mod_);
    }
    n >>= 1;
    a = (((a % mod_) * 1LL * (a % mod_)) % mod_);
  }
  return p % mod_;
}
int powi(int a, int mod_) { return powm(a, mod_ - 2, mod_); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int mn, mx;
  int n, m, k, t, i, j, sum = 0, flag = 0, cnt = 0;
  int x = 0, y = 0, z, l = 0, r = 0, q;
  int TC = 1;
  cin >> TC;
  while (TC--) {
    cin >> n;
    m = n;
    string s, t;
    cin >> s >> t;
    vector<int> c(26);
    for (i = 0; i < n; ++i) {
      c[s[i] - 'a']++;
      c[t[i] - 'a']--;
    }
    flag = 0;
    for (i = 0; i < 26; ++i) {
      if (c[i]) {
        flag = 1;
      }
    }
    if (flag) {
      cout << "-1\n";
      continue;
    }
    vector<vector<int> > next(m + 1, vector<int>(26, 1000000007));
    next[m - 1][s[m - 1] - 'a'] = m - 1;
    for (i = m - 2; i >= 0; --i) {
      next[i] = next[i + 1];
      next[i][s[i] - 'a'] = i;
    }
    flag = 1;
    mn = 1000000007;
    for (i = 0; i < n; ++i) {
      j = next[0][t[i] - 'a'];
      k = i;
      cnt = 0;
      while (j < m and k < m) {
        ++cnt;
        ++k;
        if (k == m) break;
        j = next[j + 1][t[k] - 'a'];
      }
      mn = min(mn, n - cnt);
    }
    cout << mn << "\n";
  };
  return 0;
}
