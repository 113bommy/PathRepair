#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  string sep;
  for (const auto& x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <class T, class U>
ostream& operator<<(ostream& os, const set<T, U>& v) {
  os << "{";
  string sep;
  for (const auto& x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <class T, class U>
ostream& operator<<(ostream& os, const multiset<T, U>& v) {
  os << "{";
  string sep;
  for (const auto& x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <class T, class... U>
void pr(T&& a, U&&... b) {
  cout << forward<T>(a);
  (int[]){(cout << " " << forward<U>(b), 0)...};
  cout << "\n";
}
template <class T, class... U>
void re(T&& a, U&&... b) {
  cin >> forward<T>(a);
  (int[]){(cin >> forward<U>(b), 0)...};
}
template <class T>
inline bool ckmin(T& a, const T& b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
using PR_queue = priority_queue<T, vector<T>, greater<T>>;
pair<int, int> DR8[] = {{-1, 0}, {0, 1},   {1, 0}, {0, -1},
                        {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
pair<int, int> DR4[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b > a) swap(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
void extgcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = a;
    y = b;
    return;
  }
  extgcd(b % a, a, x, y);
  long long y1 = y, x1 = x;
  x = y1 - (b / a) * x1;
  y = x1;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long bexp(long long num, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) {
      ans *= num;
    }
    num *= num;
    e >>= 1;
  }
  return ans;
}
long long mexp(long long num, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) {
      ans = (ans * num) % mod;
    }
    num = (num * num) % mod;
    e >>= 1;
  }
  return ans % mod;
}
long long modinv(long long a) { return mexp(a, mod - 2); }
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
  };
  int MAXN = (1 << 20);
  vector<long long> dp(MAXN, 0);
  for (int i = 0; i < (n); i++) {
    dp[a[i]]++;
  }
  for (int i = 0; i < (20); i++) {
    for (int mask = 0; mask < (MAXN); mask++) {
      if (!(mask & (1LL << (i)))) dp[mask] += dp[mask | (1 << i)];
    }
  }
  long long ans = 0;
  for (int i = 0; i < (MAXN); i++) {
    int sgn = (__builtin_popcount(i) % 2) ? -1 : 1;
    ans = (((ans + sgn * mexp(2, dp[i])) % mod) + mod) % mod;
  }
  pr(ans);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen("test"
            ".in",
            "r"))
    freopen(
        "test"
        ".in",
        "r", stdin),
        freopen(
            "test"
            ".out",
            "w", stdout);
  ;
  int t = 1;
  for (int T = 1; T <= (t); T++) {
    solve();
  }
  return 0;
}
