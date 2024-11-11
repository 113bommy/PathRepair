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
  pf(x.F);
  putchar(' ');
  pf(x.S);
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
const int maxn = 1e6 + 10;
struct exKMP {
  int next[maxn];
  void getnext(char *s) {
    int i, j, pos, len;
    next[i = 0] = len = strlen(s);
    while (s[i] == s[i + 1] && i + 1 < len) i++;
    next[1] = i;
    pos = 1;
    for (i = 2; i < len; i++) {
      if (next[i - pos] + i < next[pos] + pos)
        next[i] = next[i - pos];
      else {
        j = max(0, next[pos] + pos - i);
        while (i + j < len && s[j] == s[j + i]) j++;
        next[i] = j;
        pos = i;
      }
    }
  }
  void work(char *a, char *b, int *ex) {
    int i = 0, j, pos, lena, lenb;
    getnext(b);
    lena = strlen(a);
    lenb = strlen(b);
    i = 0;
    while (a[i] == b[i] && i < lenb && i < lena) i++;
    ex[0] = i;
    pos = 0;
    for (i = 1; i < lena; i++) {
      if (next[i - pos] + i < ex[pos] + pos)
        ex[i] = next[i - pos];
      else {
        j = max(0, ex[pos] + pos - i);
        while (i + j < lena && j < lenb && a[j + i] == b[j]) j++;
        ex[i] = j;
        pos = i;
      }
    }
  }
} eka, ekb;
char a[maxn], b[maxn], c[maxn];
int ex1[maxn], ex2[maxn];
int st[maxn][2], m;
void add(int x, int k) {
  if (!x) return;
  while (x <= m) {
    st[x][0] += k;
    st[x][1] += ((k > 0) ? 1 : -1);
    x += ((x) & (-x));
  }
}
pair<long long, long long> ask(int x) {
  long long k = 0, p = 0;
  while (x) {
    k += st[x][0];
    p += st[x][1];
    x -= ((x) & (-x));
  }
  return make_pair(k, p);
}
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
  int n;
  sf(n, m);
  scanf("%s%s%s", a + 1, b + 1, c + 1);
  eka.work(a + 1, c + 1, ex1 + 1);
  reverse(b + 1, b + 1 + n);
  reverse(c + 1, c + m + 1);
  ekb.work(b + 1, c + 1, ex2 + 1);
  reverse(ex2 + 1, ex2 + n + 1);
  long long ans = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    ((void)0);
    ;
    while (j + 1 <= n && j + 1 < i + m - 1) {
      if (ex2[++j] == m) --ex2[j];
      add(ex2[j], ex2[j]);
    }
    if (ex1[i] == m) --ex1[i];
    pair<long long, long long> x = ask(m), y = ask(m - ex1[i] - 1);
    ((void)0);
    ;
    ans += x.first - y.first - 1ll * (x.second - y.second) * (m - ex1[i] - 1);
    add(ex2[i], -ex2[i]);
  }
  pf(ans);
}
