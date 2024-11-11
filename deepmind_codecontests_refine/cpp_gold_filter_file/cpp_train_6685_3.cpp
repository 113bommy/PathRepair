#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
long long qpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % m;
    a = a * a % m, b >>= 1;
  }
  return ans;
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a, b >>= 1;
  }
  return ans;
}
long long qmul(long long a, long long b, long long m) {
  long long res = 0;
  while (b > 0) {
    if (b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long inv(long long t, long long p) {
  return t == 1 ? 1 : (p - p / t) * inv(p % t, p) % p;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long r = exgcd(b, a % b, y, x);
  y -= (a / b) * x;
  return r;
}
long long inv1(long long a, long long p) {
  long long d, x, y;
  d = exgcd(a, p, x, y);
  return d == 1 ? (x % p + p) % p : -1;
}
template <typename T, typename B>
T Add(T a, B b, long long m) {
  return a + b >= m ? (a + b) % m : a + b;
}
template <typename T, typename B>
T Sub(T a, B b, long long m) {
  return a - b < 0 ? (a - b + m) % m : a - b;
}
template <class T>
void _sf(T &x) {
  cin >> x;
}
void _sf(int &x) { scanf("%d", &x); }
void _sf(long long &x) { scanf("%lld", &x); }
void _sf(double &x) { scanf("%lf", &x); }
void _sf(char &x) { scanf(" %c", &x); }
void _sf(char *x) { scanf("%s", x); }
void sf() {}
template <class T, class... U>
void sf(T &head, U &...tail) {
  _sf(head);
  sf(tail...);
}
template <class T>
void _pf(const T &x) {
  cout << x;
}
void _pf(const int &x) { printf("%d", x); }
void _pf(const long long &x) { printf("%lld", x); }
void _pf(const double &x) { printf("%.16f", x); }
void _pf(const char &x) { putchar(x); }
void _pf(const char *x) { printf("%s", x); }
template <class T, class U>
void _pf(const pair<T, U> &x) {
  pf(x.first);
  putchar(' ');
  pf(x.second);
}
template <class T>
void _pf(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _pf(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void pf() {}
template <class T, class... U>
void pf(const T &head, const U &...tail) {
  _pf(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  pf(tail...);
}
template <typename T>
inline void read(T &x) {
  x = 0;
  static int p;
  p = 1;
  static char c;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c - 48);
    c = getchar();
  }
  x *= p;
}
const bool IOS = false;
const double PI = acos(-1);
const double eps = 1e-8;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const long long INV2 = 500000004;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 400000 + 10;
PII a[maxn];
int cnt[maxn];
void Main();
int main() {
  if (IOS) std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Main();
  0;
  return 0;
}
void Main() {
  int t;
  sf(t);
  while (t--) {
    int n;
    sf(n);
    int l, r;
    for (int i = 1; i <= n; ++i) {
      sf(l, r);
      a[i * 2 - 1] = make_pair(l, -i);
      a[i * 2] = make_pair(r, i);
      cnt[i] = 0;
    }
    sort(a + 1, a + 1 + 2 * n);
    int ans = 0, mx = -1;
    multiset<int> s;
    for (int i = 1; i <= 2 * n; ++i) {
      if (a[i].second < 0)
        s.insert(-a[i].second);
      else
        s.erase(s.find(a[i].second));
      if (s.size() == 0) ans++;
      if (s.size() == 1 && a[i].second > 0 && a[i + 1].second < 0 &&
          a[i + 1].first > a[i].first)
        cnt[*s.begin()]++;
      if (s.size() == 1 && a[i].second < 0 && a[i + 1].second > 0)
        cnt[*s.begin()]--;
    }
    for (int i = 1; i <= n; ++i) mx = max(mx, cnt[i]);
    pf(ans + mx);
  }
}
