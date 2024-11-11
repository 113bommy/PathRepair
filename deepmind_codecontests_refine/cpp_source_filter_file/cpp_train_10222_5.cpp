#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
bool dbg = 0;
clock_t start_time = clock();
void bad(string mes = "Impossible") {
  cout << mes;
  exit(0);
}
void bad(int mes) {
  cout << mes;
  exit(0);
}
template <typename T>
string bin(T x, int st = 2) {
  string ans = "";
  while (x > 0) {
    ans += char('0' + x % st);
    x /= st;
  }
  reverse(ans.begin(), ans.end());
  return ans.empty() ? "0" : ans;
}
mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());
template <typename T1, typename T2>
inline bool upmax(T1& a, T2 b) {
  return (a < b ? (a = b, true) : false);
}
template <typename T1, typename T2>
inline bool upmin(T1& a, T2 b) {
  return (b < a ? (a = b, true) : false);
}
template <typename T>
T input() {
  T ans = 0, m = 1;
  char c = ' ';
  while (!((c >= '0' && c <= '9') || c == '-')) {
    c = getchar();
  }
  if (c == '-') m = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + (c - '0'), c = getchar();
  }
  return ans * m;
}
template <typename T>
T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <typename T>
void read(T& a) {
  a = input<T>();
}
template <typename T>
void read(T& a, T& b) {
  read(a), read(b);
}
template <typename T>
void read(T& a, T& b, T& c) {
  read(a, b), read(c);
}
template <typename T>
void read(T& a, T& b, T& c, T& d) {
  read(a, b), read(c, d);
}
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e4 + 1, base = 998244353;
const long long llinf = 2e18 + 5;
int first[maxn];
int a[maxn];
int b[maxn];
int n, k;
inline void add(int& a, int b) {
  a += b;
  if (a >= base) a -= base;
  if (a < 0) a += base;
}
inline int mul(int a, int b) { return 1ll * a * b % base; }
int solve(int q) {
  for (int i = 0; i < n; ++i) a[i] = (q - a[i] + base) % base;
  for (int i = 0; i <= k; ++i) first[i] = 0;
  first[0] = 1;
  for (int i = 0; i < n; ++i) {
    int r = min(i + 1, k);
    int l = max(1, k - n + i);
    int val = a[i];
    for (int j = r; j >= l; --j) {
      add(first[j], mul(first[j - 1], val));
    }
  }
  return first[k];
}
inline int mmin(int a, int b) { return a < b ? a : b; }
inline int mmax(int a, int b) { return a > b ? a : b; }
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    a[i] = b[i];
  }
  int q;
  scanf("%d", &q);
  int tp, qq;
  int i;
  int l, r, d;
  while (q--) {
    copy(b, b + n, a);
    scanf("%d", &tp);
    if (tp == 1) {
      scanf("%d%d%d", &qq, &i, &d);
      i--;
      a[i] = d;
    } else {
      scanf("%d%d%d%d", &qq, &l, &r, &d);
      l--;
      r--;
      for (int i = l; i <= r; i++) {
        add(a[i], d);
      }
    }
    memset(first, 0, sizeof(first));
    first[0] = 1;
    for (int i = 0; i < n; ++i) {
      int val = (qq - a[i] + base) % base;
      for (int j = mmin(i + 1, k); j >= mmax(1, k - n + i); --j) {
        first[j] = (first[j] + 1ll * first[j - 1] * val);
      }
    }
    cout << first[k] << '\n';
  }
  return 0;
}
