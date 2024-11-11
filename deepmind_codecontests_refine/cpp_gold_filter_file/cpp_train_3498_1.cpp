#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int in() {
  int x;
  cin >> x;
  return x;
}
long long lin() {
  long long x;
  cin >> x;
  return x;
}
string stin() {
  string s;
  cin >> s;
  return s;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
void print() { putchar(' '); }
void print(bool a) { cout << a; }
void print(int a) { cout << a; }
void print(long long a) { cout << a; }
void print(char a) { cout << a; }
void print(string& a) { cout << a; }
void print(double a) { cout << a; }
template <class T>
void print(const vector<T>&);
template <class T, size_t size>
void print(const array<T, size>&);
template <class T, class L>
void print(const pair<T, L>& p);
template <class T, size_t size>
void print(const T (&)[size]);
template <class T>
void print(const vector<T>& a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    putchar(' ');
    print(*i);
  }
}
template <class T>
void print(const deque<T>& a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    putchar(' ');
    print(*i);
  }
}
template <class T, size_t size>
void print(const array<T, size>& a) {
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    putchar(' ');
    print(*i);
  }
}
template <class T, class L>
void print(const pair<T, L>& p) {
  cout << '(';
  print(p.first);
  putchar(' ');
  print(p.second);
  cout << ')';
}
template <class T, size_t size>
void print(const T (&a)[size]) {
  print(a[0]);
  for (auto i = a; ++i != end(a);) {
    putchar(' ');
    print(*i);
  }
}
template <class T>
void print(const T& a) {
  cout << a;
}
int out() {
  putchar('\n');
  return 0;
}
template <class T>
int out(const T& t) {
  print(t);
  putchar('\n');
  return 0;
}
template <class Head, class... Tail>
int out(const Head& head, const Tail&... tail) {
  print(head);
  putchar(' ');
  out(tail...);
  return 0;
}
long long gcd(long long a, long long b) {
  while (b) {
    long long c = b;
    b = a % b;
    a = c;
  }
  return a;
}
long long lcm(long long a, long long b) {
  if (!a || !b) return 0;
  return a * b / gcd(a, b);
}
template <class... T>
void err(const T&...) {}
template <unsigned mod>
struct RollingHash {
  vector<unsigned> hashed, power;
  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long)a * b;
    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod));
    return m;
  }
  RollingHash(const string& s, unsigned base = 10007) {
    int sz = (int)s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for (int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }
  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if (ret >= mod) ret -= mod;
    return ret;
  }
  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if (ret >= mod) ret -= mod;
    return ret;
  }
  int LCP(const RollingHash<mod>& b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while (high - low > 1) {
      int mid = (low + high) / 2;
      if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
        low = mid;
      else
        high = mid;
    }
    return (low);
  }
};
using RH = RollingHash<1000000007>;
using RH2 = RollingHash<998244353>;
int dp[8100];
int ln[8100];
int same[8100][8100];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  string s;
  cin >> s;
  RH rh1(s);
  for (long long i = 0; i < 8100; i++) dp[i] = INT_MAX;
  for (long long i = 1; i <= 9; ++i) ln[i] = 1;
  for (long long i = 10; i <= 99; ++i) ln[i] = 2;
  for (long long i = 100; i <= 999; ++i) ln[i] = 3;
  for (long long i = 1000; i <= 8000; ++i) ln[i] = 4;
  int n = s.size();
  for (long long i = n - 1; i >= 0; i--) {
    for (long long j = i; j <= n - 1; ++j) {
      if (s[i] == s[j]) same[i][j] = same[i + 1][j + 1] + 1;
    }
  }
  dp[0] = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j <= n - i; ++j) {
      int cnt = 0;
      for (int k = i; k + j <= n; k += j) {
        cnt++;
        if (same[i][k] >= j) {
          chmin(dp[k + j], dp[i] + (int)j + ln[cnt]);
        } else
          break;
      }
    }
  }
  cout << dp[n] << "\n";
}
