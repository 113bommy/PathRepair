#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
template <typename S, typename T>
inline bool Min(S &a, const T &b) {
  return a > b ? a = b, true : false;
}
template <typename S, typename T>
inline bool Max(S &a, const T &b) {
  return a < b ? a = b, true : false;
}
template <typename S, typename T>
inline void Adm(S &a, const T &b) {
  a = (a + b) % MOD;
  if (a < 0) a += MOD;
}
template <typename S, typename T>
inline void Mum(S &a, const T &b) {
  a = 1LL * a * b % MOD;
}
template <typename T>
inline bool IsPri(T x) {
  if (x < 2) return false;
  for (T i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
template <typename T>
inline T Gcd(T a, T b) {
  while (b) {
    T t = b;
    b = a % b;
    a = t;
  }
  return a;
}
template <typename T>
inline int BtCnt(T x) {
  int cnt = 0;
  while (x) ++cnt, x &= x - 1;
  return cnt;
}
inline long long Pow(long long a, long long n) {
  long long t = 1;
  while (n) {
    if (n & 1) t = t * a % MOD;
    a = a * a % MOD, n >>= 1;
  }
  return t;
}
inline int read() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  register int x = 0;
  register char ch =
      p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
          ? EOF
          : *p1++;
  ;
  register bool sgn = 0;
  while (ch != '-' && (ch < '0' || ch > '9'))
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  if (ch == '-') sgn = 1;
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48),
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  return sgn ? -x : x;
}
const int N = 5e5 + 100;
struct node {
  int u, v, w;
  bool operator<(const node &o) const { return w < o.w; }
} e[N], p[N];
struct query {
  int a, id;
  bool operator<(const query &o) const {
    if (e[a].w != e[o.a].w) return e[a].w < e[o.a].w;
    return id < o.id;
  }
} q[N];
bool ans[N];
struct dsu {
  int fz[N], sz[N], tot;
  pair<int, int> stk[N];
  void Init() {
    for (int i = 0; i < N; ++i) fz[i] = i, sz[i] = 1;
    tot = 0;
  }
  void Cancel() {
    while (tot) {
      --tot;
      int x = stk[tot].first, y = stk[tot].second;
      sz[y] -= sz[x], fz[x] = x;
    }
  }
  int Find(int x) {
    while (x != fz[x]) x = fz[x];
    return x;
  }
  bool Merge(int x, int y, int c = 0) {
    x = Find(x), y = Find(y);
    if (x == y) return false;
    if (sz[x] > sz[y]) swap(x, y);
    sz[y] += sz[x], fz[x] = y;
    if (c) stk[tot++] = {x, y};
    return true;
  }
} d;
int main() {
  memset((ans), (1), sizeof(ans)), d.Init();
  int n, m, Q, tot = 0;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i)
    scanf("%d%d%d", &p[i].u, &p[i].v, &p[i].w), e[i] = p[i];
  sort(p + 1, p + m + 1);
  cin >> Q;
  for (int i = 1; i <= Q; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) ++tot, scanf("%d", &q[tot].a), q[tot].id = i;
  }
  sort(q + 1, q + Q + 1);
  int k = 1;
  for (int i = 1; i <= tot; ++i) {
    while (k <= m && p[k].w < e[q[i].a].w) d.Merge(p[k].u, p[k].v), ++k;
    int j = i;
    for (; j <= tot; ++j) {
      if (e[q[i].a].w != e[q[j].a].w || q[i].id != q[j].id) break;
      if (!d.Merge(e[q[j].a].u, e[q[j].a].v, 1)) ans[q[j].id] = 0;
    }
    i = j - 1;
    d.Cancel();
  }
  for (int i = 1; i <= Q; ++i) printf("%s\n", ans[i] ? "YES" : "NO");
  return 0;
}
