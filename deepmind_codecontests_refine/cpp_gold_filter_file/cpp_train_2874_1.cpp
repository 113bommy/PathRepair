#include <bits/stdc++.h>
using namespace std;
const int Imx = 2147483647;
const long long Lbig = 2e18;
const int mod = 1e9 + 7;
struct fastio {
  char s[100000];
  int it, len;
  fastio() { it = len = 0; }
  inline char get() {
    if (it < len) return s[it++];
    it = 0;
    len = fread(s, 1, 100000, stdin);
    if (len == 0)
      return EOF;
    else
      return s[it++];
  }
  bool notend() {
    char c = get();
    while (c == ' ' || c == '\n') c = get();
    if (it > 0) it--;
    return c != EOF;
  }
} _buff;
inline long long getnum() {
  long long r = 0;
  bool ng = 0;
  char c;
  c = _buff.get();
  while (c != '-' && (c < '0' || c > '9')) c = _buff.get();
  if (c == '-') ng = 1, c = _buff.get();
  while (c >= '0' && c <= '9') r = r * 10 + c - '0', c = _buff.get();
  return ng ? -r : r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline char getreal() {
  char c = _buff.get();
  while (c == ' ' || c == '\n') c = _buff.get();
  return c;
}
struct twodquery {
  vector<pair<pair<int, int>, pair<bool, int> > > v;
  int cnt[400111], tag[400111], curtag;
  void add(int x) {
    for (int i = x; i <= 400005; i += i & (-i)) {
      if (tag[i] != curtag) cnt[i] = 0, tag[i] = curtag;
      cnt[i]++;
    }
  }
  int query(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & (-i)) {
      if (tag[i] != curtag) cnt[i] = 0, tag[i] = curtag;
      ret += cnt[i];
    }
    return ret;
  }
  twodquery() {
    memset(tag, 0, sizeof(tag));
    curtag = 0;
  }
  void init() { v.clear(); }
  void addpt(int x, int y, bool t, int id) {
    x = -x + 200001;
    y = -y + 200001;
    v.push_back(make_pair(make_pair(x, y), make_pair(t, id)));
  }
  void solve(int ans[], int coef) {
    sort((v).begin(), (v).end());
    curtag++;
    for (int i = 0; i < v.size();) {
      int r = i;
      while (r < v.size() && v[r].first.first == v[i].first.first) r++;
      for (int j = i; j < r; j++)
        if (v[j].second.first == 0) add(v[j].first.second);
      for (int j = i; j < r; j++)
        if (v[j].second.first == 1)
          ans[v[j].second.second] += coef * query(v[j].first.second);
      i = r;
    }
  }
} kotori;
int n;
int head[100111], nxt[200111], to[200111], col[200111], w[200111], tot = 1;
void addedge(int x, int y, int cost, int c) {
  nxt[++tot] = head[x];
  head[x] = tot;
  to[tot] = y;
  w[tot] = cost;
  col[tot] = c;
}
int a[100111], asz, sz[100111];
bool ban[100111];
void dfs(int x, int pre = -1) {
  a[asz++] = x;
  sz[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == pre || ban[to[i]]) continue;
    dfs(to[i], x);
    sz[x] += sz[to[i]];
  }
}
long long kissme(long long x, long long k) {
  long long ret = 1;
  while (k) {
    if (k & 1) ret = ret * x % mod;
    x = x * x % mod;
    k >>= 1;
  }
  return ret;
}
long long ans, pro[100111];
int ans0[100111];
bool tmp;
void dfs2(int x, int pre = -1, long long prod = 1, int cnt0 = 0, int cnt1 = 0) {
  pro[x] = prod;
  int tx = 2 * cnt0 - cnt1;
  int ty = 2 * cnt1 - cnt0;
  if (tx >= 0 && ty >= 0 && tmp) ans = ans * prod % mod;
  kotori.addpt(tx, ty, 0, x);
  kotori.addpt(-tx, -ty, 1, x);
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == pre || ban[to[i]]) continue;
    dfs2(to[i], x, prod * w[i] % mod, cnt0 + (col[i] == 0),
         cnt1 + (col[i] == 1));
  }
}
void solve(int x) {
  asz = 0;
  dfs(x);
  if (asz == 1) return;
  int rt = x;
  for (int i = 0; i < asz; i++) {
    ans0[a[i]] = 0;
    if (sz[a[i]] >= sz[x] / 2 && sz[a[i]] < sz[rt]) {
      rt = a[i];
    }
  }
  kotori.init();
  pro[rt] = 1;
  tmp = 1;
  for (int i = head[rt]; i; i = nxt[i]) {
    if (!ban[to[i]]) {
      dfs2(to[i], rt, w[i], col[i] == 0, col[i] == 1);
    }
  }
  tmp = 0;
  kotori.solve(ans0, 1);
  for (int i = head[rt]; i; i = nxt[i]) {
    if (!ban[to[i]]) {
      kotori.init();
      dfs2(to[i], rt, w[i], col[i] == 0, col[i] == 1);
      kotori.solve(ans0, -1);
    }
  }
  for (int i = 0; i < asz; i++)
    ans = 1ll * ans * kissme(pro[a[i]], ans0[a[i]]) % mod;
  ban[rt] = 1;
  for (int i = head[rt]; i; i = nxt[i])
    if (!ban[to[i]]) solve(to[i]);
}
int main() {
  ans = 1;
  n = getnum();
  for (int i = 1; i < n; i++) {
    int x, y;
    x = getnum(), y = getnum();
    int cost, c;
    cost = getnum(), c = getnum();
    addedge(x, y, cost, c);
    addedge(y, x, cost, c);
  }
  solve(1);
  cout << ans << endl;
  return 0;
}
