#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int dir[8][2] = {-1, 0, 1, 0, 0, -1, 0, 1, -1, -1, -1, 1, 1 - 1, 1, 1};
int sgn(double x) {
  if (fabs(x) < 1e-8) return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <typename S, typename T>
inline bool Min(S &a, const T &b) {
  return a > b ? a = b, true : false;
}
template <typename S, typename T>
inline bool Max(S &a, const T &b) {
  return a < b ? a = b, true : false;
}
template <typename T>
inline bool IsPri(T x) {
  if (x < 2) return false;
  for (T i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
template <typename T>
inline int BitCnt(T x) {
  int cnt = 0;
  while (x) ++cnt, x &= x - 1;
  return cnt;
}
template <typename T>
inline int BitNum(T x) {
  int cnt = 0;
  while (x) ++cnt, x >>= 1;
  return cnt;
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
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
int p[maxn];
vector<int> e[maxn];
int disa[maxn], disb[maxn], disc[maxn];
bool vis[maxn];
int n, m;
void bfs(int st, int *dis) {
  for (int i = 1; i <= n; ++i) vis[i] = 0, dis[i] = 0;
  queue<int> q;
  q.push(st);
  vis[st] = 1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto it : e[now]) {
      if (!vis[it]) {
        dis[it] = dis[now] + 1;
        vis[it] = 1;
        q.push(it);
      }
    }
  }
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
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    sf(n, m, a, b, c);
    for (int i = 1; i <= n; ++i) e[i].clear();
    for (int i = 1; i <= m; ++i) sf(p[i]);
    sort(p + 1, p + 1 + m);
    for (int i = 1; i <= m; ++i) p[i] = p[i - 1] + p[i];
    for (int i = 1; i <= m; ++i) {
      int u, v;
      sf(u, v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    bfs(a, disa);
    bfs(b, disb);
    bfs(c, disc);
    long long ans = linf;
    for (int i = 1; i <= n; ++i) {
      if (disa[i] + disb[i] + disc[i] > m) continue;
      Min(ans, p[disa[i] + disb[i] + disc[i]] + p[disb[i]]);
    }
    pf(ans);
  }
}
