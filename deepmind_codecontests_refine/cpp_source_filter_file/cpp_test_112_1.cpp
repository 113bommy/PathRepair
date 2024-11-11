#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Read(T &x) {
  int c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar())
    if (c == '-') f = true;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  if (f) x = -x;
}
inline int read() {
  int s = 0, ch = getchar(), w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
inline long long Read() {
  long long s = 0;
  int ch = getchar(), w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
const int kcz = 998244353;
const int G = 3, GI = 332748118;
inline void add(int &x, const int &y) { x += y, x >= kcz ? x -= kcz : 1; }
inline int Add(const int &x, const int &y) {
  return x + y >= kcz ? x + y - kcz : x + y;
}
inline int qpow(int x, int y = kcz - 2) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = int((long long)(ret) * (x) % kcz);
    x = int((long long)(x) * (x) % kcz), y >>= 1;
  }
  return ret;
}
inline int qpow(int x, int y, const int &ljc) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = int(1ll * ret * x % ljc);
    x = int(1ll * x * x % ljc), y >>= 1;
  }
  return ret;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int N = 4e5 + 10;
namespace MAIN {
int sit[N], sitr[N];
int pos[N];
char str[N];
pair<int, int> chain[N], Chain[N];
int cx;
namespace Tr {
vector<pair<int, int> > G[N];
int sz[N], son[N], dep[N], fa[N], ch[N];
void dfs(int x, int fax, int depx) {
  sz[x] = 1, fa[x] = fax, dep[x] = depx;
  for (auto [tox, c] : G[x]) {
    if (tox == fax) continue;
    dfs(tox, x, depx + 1), ch[tox] = c, sz[x] += sz[tox];
    if (sz[tox] > sz[son[x]]) son[x] = tox;
  }
}
int top[N], dfn[N], idx, pos[N];
void dfs(int x, int topx) {
  top[pos[dfn[x] = ++idx] = x] = topx;
  if (son[x]) dfs(son[x], topx);
  for (auto [tox, c] : G[x]) {
    if (tox == fa[x] || tox == son[x]) continue;
    dfs(tox, tox);
  }
}
inline void gchain(int u, int v) {
  int A = 0, B = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]])
      chain[++A] = make_pair(sitr[u], sitr[top[u]]), u = fa[top[u]];
    else
      Chain[++B] = make_pair(sit[top[v]], sit[v]), v = fa[top[v]];
  }
  if (dep[u] < dep[v]) chain[++A] = make_pair(sit[u] + 1, sit[v]);
  if (dep[u] > dep[v]) chain[++A] = make_pair(sitr[u], sitr[v] - 1);
  for (int i = B; i >= 1; i--) chain[++A] = Chain[i];
  cx = A;
}
}  // namespace Tr
namespace SA {
int str[N];
int rnk[N], buc[N], sa[N], hei[N], fr[N], sc[N], n, m;
inline void get_SA() {
  m = 10000;
  for (int i = 1; i <= n; i++) buc[fr[i] = str[i]]++;
  for (int i = 2; i <= m; i++) buc[i] += buc[i - 1];
  for (int i = n; i; i--) sa[buc[fr[i]]--] = i;
  for (int k = 1; k <= n; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; i++) sc[++num] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > k) sc[++num] = sa[i] - k;
    memset(buc, 0, sizeof(buc));
    for (int i = 1; i <= n; i++) buc[fr[i]]++;
    for (int i = 2; i <= m; i++) buc[i] += buc[i - 1];
    for (int i = n; i; i--) sa[buc[fr[sc[i]]]--] = sc[i], sc[i] = 0;
    swap(fr, sc);
    fr[sa[1]] = 1;
    num = 1;
    for (int i = 2; i <= n; i++)
      fr[sa[i]] =
          (sc[sa[i]] == sc[sa[i - 1]] && sc[sa[i] + k] == sc[sa[i - 1] + k])
              ? num
              : ++num;
    if (num == n) break;
    m = num;
  }
}
inline void get_hei() {
  int k = 0;
  rnk[sa[1]] = 1;
  for (int i = 2; i <= n; i++)
    rnk[sa[i]] = rnk[sa[i - 1]] +
                 (fr[sa[i]] != fr[sa[i - 1]] || sc[sa[i]] != sc[sa[i - 1]]);
  for (int i = 1; i <= n; i++) {
    if (rnk[i] == 1) continue;
    if (k) k--;
    int j = sa[rnk[i] - 1];
    while (j + k <= n && i + k <= n && str[i + k] == str[j + k]) k++;
    hei[rnk[i]] = k;
  }
}
int st[N][21];
inline void PRE() {
  for (int i = 1; i <= n; i++) st[i][0] = hei[i];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int Lg[N];
inline int query_min(int l, int r) {
  int k = Lg[r - l];
  return min(st[l][k], st[r - (1 << k) + 1][k]);
}
inline int LCP(const int &l, const int &r) {
  if (l == r) return n - l + 1;
  int x = rnk[l], y = rnk[r];
  if (x > y) swap(x, y);
  return query_min(x + 1, y);
}
inline void pre() {
  for (int i = 2; i <= n; i++) Lg[i] = Lg[i >> 1] + 1;
  str[n + 1] = 26, get_SA(), get_hei(), PRE();
}
inline bool small(int p) {
  p = sa[p];
  for (int i = 1; i <= cx; i++) {
    int s = n - p, t = chain[i].second - chain[i].first + 1,
        _ = min({s, t, LCP(p, chain[i].first)});
    if (_ != min(s, t)) return str[p + _] < str[chain[i].first + _];
    if (_ == s && _ == t) return i != cx;
    if (_ < t) return 1;
    p += t;
  }
  return 0;
}
inline bool match(int p) {
  p = sa[p];
  for (int i = 1; i <= cx; i++) {
    int s = n - p, t = chain[i].second - chain[i].first + 1,
        _ = min({s, t, LCP(p, chain[i].first)});
    if (_ < t) return 0;
    if (_ == s) return i == cx;
    p += t;
  }
  return 1;
}
inline int gpos() {
  int l = 1, r = n, ret = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (small(mid))
      l = mid + 1, ret = mid;
    else
      r = mid - 1;
  }
  return ret;
}
inline int findl(int r) {
  int l = 1, ret = r + 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (match(mid))
      r = mid - 1, ret = mid;
    else
      l = mid + 1;
  }
  return ret;
}
inline int findr(int l) {
  int r = n, ret = l - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (match(mid))
      l = mid + 1, ret = mid;
    else
      r = mid - 1;
  }
  return ret;
}
}  // namespace SA
vector<int> Q[N];
int n, m, q;
int tr[N];
inline void modify(const int &x, const int &y) {
  for (int i = x; i <= SA::n; i += ((i) & -(i))) tr[i] += y;
}
inline int query(const int &x) {
  int ret = 0;
  for (int i = x; i; i -= ((i) & -(i))) ret += tr[i];
  return ret;
}
int ans[N];
pair<int, int> que[N];
inline void MAIN() {
  n = read(), m = read(), q = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    char sss[5];
    scanf("%s", sss + 1);
    Tr::G[u].emplace_back(make_pair(v, sss[1])),
        Tr::G[v].emplace_back(make_pair(u, sss[1]));
  }
  for (int i = 1; i <= m; i++) {
    scanf("%s", str + 1);
    int t = int(strlen(str + 1));
    for (int j = 1; j <= t; j++)
      SA::n++, SA::str[SA::n] = str[j], pos[SA::n] = i;
    SA::str[++SA::n] = i + 'z';
  }
  Tr::dfs(1, 0, 1), Tr::dfs(1, 1), Tr::ch[1] = 'a' - 1;
  for (int i = 1; i <= Tr::idx; i++) {
    int p = Tr::pos[i];
    SA::n++, sit[p] = SA::n, SA::str[SA::n] = Tr::ch[p];
  }
  for (int i = Tr::idx; i >= 1; i--) {
    int p = Tr::pos[i];
    SA::n++, sitr[p] = SA::n, SA::str[SA::n] = Tr::ch[p];
  }
  SA::pre();
  for (int T = 1; T <= q; T++) {
    int u = read(), v = read(), L = read(), R = read();
    Tr::gchain(u, v), que[T] = make_pair(L, R);
    int x = SA::gpos();
    int l = SA::findl(x), r = SA::findr(x + 1);
    if (l <= r) Q[l - 1].push_back(-T), Q[r].push_back(T);
  }
  for (int i = 1; i <= SA::n; i++) {
    int p = SA::sa[i];
    if (pos[p]) modify(pos[p], 1);
    for (auto x : Q[i])
      ans[abs(x)] += (x > 0 ? 1 : -1) *
                     (query(que[abs(x)].second) - query(que[abs(x)].first - 1));
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
}  // namespace MAIN
int main() {
  int Case = 1;
  while (Case--) MAIN::MAIN();
  return 0;
}
