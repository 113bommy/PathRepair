#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int Rlen = 1 << 22 | 1;
inline char gc() {
  static char buf[Rlen], *p1, *p2;
  (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, Rlen, stdin));
  return p1 == p2 ? EOF : *p1++;
}
int read() {
  int x = 0;
  char c = gc();
  bool f = false;
  while (!isdigit(c)) f = c == '-', c = gc();
  while (isdigit(c)) x = (((x << 2) + x) << 1) + (c ^ 48), c = gc();
  return f ? -x : x;
}
int str() {
  char c = gc();
  while (isspace(c)) c = gc();
  return c - 'a';
}
int Str(char *S) {
  char c = gc();
  while (isspace(c)) c = gc();
  int len = 0;
  while ('a' <= c && c <= 'z') S[++len] = c, c = gc();
  return len;
}
}  // namespace IO
using namespace IO;
const int N = 2e5 + 50;
const int M1 = 1e9 + 7, M2 = 998244353;
const int B1 = 19260817, B2 = 17680321;
int add(int a, int b, int mod) { return a + b >= mod ? a + b - mod : a + b; }
int dec(int a, int b, int mod) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b, int mod) { return 1ll * a * b % mod; }
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return make_pair(add(a.first, b.first, M1), add(a.second, b.second, M2));
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return make_pair(dec(a.first, b.first, M1), dec(a.second, b.second, M2));
}
pair<int, int> operator*(pair<int, int> a, pair<int, int> b) {
  return make_pair(mul(a.first, b.first, M1), mul(a.second, b.second, M2));
}
bool operator==(pair<int, int> a, pair<int, int> b) {
  return a.first == b.first && a.second == b.second;
}
pair<int, int> pw[N];
void init_pw(int n) {
  pw[0] = make_pair(1, 1);
  pw[1] = make_pair(B1, B2);
  for (int i = 2; i <= n; i++) pw[i] = pw[i - 1] * pw[1];
}
int n, m, q, len[N], ps[N][2];
char tmp[N];
struct dat {
  int l, r, dt;
};
struct AC_Automaton {
  int ch[N][26], nd, fail[N];
  int ins(char *S, int len) {
    int u = 0;
    for (int i = 1, c; i <= len; i++) {
      c = S[i] - 'a';
      if (!ch[u][c]) ch[u][c] = ++nd;
      u = ch[u][c];
    }
    return u;
  }
  int in[N], out[N], sgn;
  vector<int> G[N];
  void dfs(int u) {
    in[u] = ++sgn;
    for (int e = 0, v; e < (int)G[u].size(); e++) {
      v = G[u][e];
      dfs(v);
    }
    out[u] = sgn;
  }
  void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++)
      if (ch[0][i]) q.push(ch[0][i]);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i = 0; i < 26; i++)
        if (ch[x][i])
          fail[ch[x][i]] = ch[fail[x]][i], q.push(ch[x][i]);
        else
          ch[x][i] = ch[fail[x]][i];
    }
    for (int i = 1; i <= nd; i++) G[fail[i]].push_back(i);
    dfs(0);
  }
} AC[2];
struct BIT {
  int c[N], n;
  void add(int x, int v) {
    for (; x <= n; x += x & -x) c[x] += v;
  }
  int ask(int x) {
    int as = 0;
    for (; x; x -= x & -x) as += c[x];
    return as;
  }
  int ask(int l, int r) { return ask(r) - ask(l - 1); }
} bit[2];
vector<pair<int, int> > G[N];
int an[N][22], o[N], dep[N], lg[N], Ans[N];
pair<int, int> h[N];
pair<int, int> Has(int u, int v) { return h[u] - h[v] * pw[dep[u] - dep[v]]; }
void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  an[u][0] = fa;
  for (int i = 1; i <= lg[dep[u]]; i++) an[u][i] = an[an[u][i - 1]][i - 1];
  for (int e = 0, v, c; e < (int)G[u].size(); e++)
    if ((v = G[u][e].first) != fa) {
      c = G[u][e].second;
      o[v] = c;
      h[v] = h[u] * pw[1] + make_pair(c, c);
      dfs(v, u);
    }
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = lg[dep[x]]; ~i; i--)
    if (dep[an[x][i]] >= dep[y]) x = an[x][i];
  if (x == y) return x;
  for (int i = lg[dep[x]]; ~i; i--)
    if (an[x][i] != an[y][i]) x = an[x][i], y = an[y][i];
  return an[x][0];
}
int jmp(int x, int d) {
  if (!d) return x;
  for (int i = lg[d]; ~i; i--)
    if (d >= (1 << i)) x = an[x][i], d -= 1 << i;
  return x;
}
struct qry {
  int op, p, c;
};
vector<qry> ql[N], qr[N];
void cope(int u, int fa, int nx, int ny) {
  bit[0].add(AC[0].in[nx], 1);
  bit[1].add(AC[1].in[ny], 1);
  for (int i = 0; i < (int)qr[u].size(); i++) {
    qry x = qr[u][i];
    int pt = ps[x.p][0];
    Ans[x.c] += x.op * bit[0].ask(AC[0].in[pt], AC[0].out[pt]);
  }
  for (int i = 0; i < (int)ql[u].size(); i++) {
    qry x = ql[u][i];
    int pt = ps[x.p][1];
    Ans[x.c] += x.op * bit[1].ask(AC[1].in[pt], AC[1].out[pt]);
  }
  for (int e = 0, v; e < (int)G[u].size(); e++)
    if ((v = G[u][e].first) != fa)
      cope(v, u, AC[0].ch[nx][G[u][e].second], AC[1].ch[ny][G[u][e].second]);
  bit[0].add(AC[0].in[nx], -1);
  bit[1].add(AC[1].in[ny], -1);
}
struct Suffix_Array {
  int n, m;
  string S;
  int *SA, *rk, *y, *tmp, *bin;
  pair<int, int> *h;
  int *nxt[22], *trs;
  void copy(char *t, int len) {
    n = len;
    S = ' ';
    for (int i = 1; i <= n; i++) S += t[i];
  }
  void Kmp_work() {
    for (int i = 1; i + i <= n; i++)
      if (i < n - i + 1) swap(S[i], S[n - i + 1]);
    for (int i = 0; i <= lg[n]; i++) nxt[i] = new int[n + 1]();
    for (int i = 2, j = 0; i <= n; i++) {
      while (j && S[j + 1] != S[i]) j = nxt[0][j];
      if (S[j + 1] == S[i]) ++j;
      nxt[0][i] = j;
    }
    for (int j = 1; j <= lg[n]; j++)
      for (int i = 1; i <= n; i++) nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
    trs = new int[n + 1]();
    for (int i = 1; i <= n; i++) {
      if (nxt[0][i] && i - nxt[0][i] == nxt[0][i] - nxt[0][nxt[0][i]])
        trs[i] = trs[nxt[0][i]];
      else
        trs[i] = i;
    }
    for (int i = 1; i + i <= n; i++)
      if (i < n - i + 1) swap(S[i], S[n - i + 1]);
  }
  void Hash_work() {
    h = new pair<int, int>[n + 1]();
    for (int i = 1; i <= n; i++)
      h[i] = h[i - 1] * pw[1] + make_pair(S[i] - 'a', S[i] - 'a');
  }
  void radix_sort() {
    for (int i = 0; i <= m; i++) bin[i] = 0;
    for (int i = 1; i <= n; i++) ++bin[rk[i]];
    for (int i = 1; i <= m; i++) bin[i] += bin[i - 1];
    for (int i = n; i; i--) SA[bin[rk[y[i]]]--] = y[i];
  }
  void build() {
    m = 128;
    SA = new int[n + 1]();
    rk = new int[n + 1]();
    tmp = new int[n + 1]();
    y = new int[n + 1]();
    bin = new int[max(n + 1, 1 << 8)]();
    for (int i = 1; i <= n; i++) rk[i] = S[i], y[i] = i;
    radix_sort();
    for (int k = 1; k <= n; k <<= 1) {
      int ct = 0;
      for (int i = n - k + 1; i <= n; i++) y[++ct] = i;
      for (int i = 1; i <= n; i++)
        if (SA[i] > k) y[++ct] = SA[i] - k;
      radix_sort();
      swap(rk, tmp);
      rk[SA[1]] = 1;
      int num = 1;
      for (int i = 2; i <= n; i++) {
        if (tmp[SA[i]] == tmp[SA[i - 1]] &&
            tmp[SA[i] + k] == tmp[SA[i - 1] + k])
          rk[SA[i]] = num;
        else
          rk[SA[i]] = ++num;
      }
      m = num;
    }
  }
  pair<int, int> Get(int l, int r) { return h[r] - h[l - 1] * pw[r - l + 1]; }
  int lcp(int u, int v, int p) {
    int as = 0, l = 1, r = min(n - p + 1, dep[u] - dep[v]);
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (Has(jmp(u, dep[u] - dep[v] - mid), v) == Get(p, p + mid - 1))
        l = mid + 1, as = mid;
      else
        r = mid - 1;
    }
    return as;
  }
  bool chk(int u, int v, int p) {
    int len = lcp(u, v, SA[p]);
    if (len == dep[u] - dep[v]) return false;
    int nx = jmp(u, dep[u] - dep[v] - len - 1);
    return o[nx] >= S[SA[p] + len] - 'a';
  }
  int fnd(int u, int v) {
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (chk(u, v, mid))
        l = mid;
      else
        r = mid - 1;
    }
    int pt = SA[l], mx = lcp(u, v, pt);
    if (l < n && lcp(u, v, SA[l + 1]) > mx) pt = SA[l + 1], mx = lcp(u, v, pt);
    if (mx == 0) return 0;
    if (mx == n - pt + 1) return n - pt + 1;
    for (int i = lg[n]; ~i; i--) {
      int np = n - nxt[i][n - pt + 1] + 1;
      if (!np) continue;
      if (lcp(u, v, np) != n - np + 1) pt = np;
    }
    return nxt[0][n - pt + 1];
  }
  void fnd_border(int pt, vector<dat> &S) {
    while (pt) {
      int np = trs[pt];
      if (pt == np)
        S.push_back((dat){np, pt, 0});
      else
        S.push_back((dat){np, pt, pt - nxt[0][pt]});
      pt = nxt[0][np];
    }
  }
} My[N][2];
namespace Yolanda {
long long x, y;
int exgcd(int a, int b) {
  if (!b) return x = 1, y = 0, a;
  int gc = exgcd(b, a % b);
  long long tx = y, ty = x - (long long)a / b * y;
  x = tx;
  y = ty;
  return gc;
}
int ex_work(dat a, dat b, int len) {
  int c = b.l + a.r - len;
  int u1 = (a.r - a.l) / a.dt, u2 = (b.r - b.l) / b.dt;
  int gc = exgcd(a.dt, b.dt);
  if (abs(c) % gc) return 0;
  x = x * c / gc;
  y = y * c / gc;
  y = -y;
  int t1 = b.dt / gc, t2 = a.dt / gc;
  long long dl = max((-x) / t1, (-y) / t2),
            dr = min((u1 - x) / t1, (u2 - y) / t2);
  if (x > u1) dr = min(dr, (u1 - x + 1) / t1 - 1);
  if (y > u2) dr = min(dr, (u2 - x + 1) / t2 - 1);
  if (x < 0) dl = max(dl, (-x - 1) / t1 + 1);
  if (y < 0) dl = max(dl, (-y - 1) / t2 + 1);
  return max(0ll, dr - dl + 1);
}
int work(int u, int v, int l, int p) {
  int len = My[p][0].n;
  int up = My[p][1].fnd(u, l);
  int vp = My[p][0].fnd(v, l);
  if (!up || !vp) return 0;
  vector<dat> S, T;
  int as = 0;
  My[p][1].fnd_border(up, S);
  My[p][0].fnd_border(vp, T);
  for (int i = 0; i < S.size(); i++)
    for (int j = 0; j < T.size(); j++) {
      dat a = S[i], b = T[j];
      if (a.r + b.r < len) break;
      if (a.dt == 0 && b.dt == 0) {
        if (a.l + b.l == len) ++as;
        continue;
      }
      if (a.dt == 0) {
        int c = len - a.l;
        if (b.l <= c && c <= b.r && (c - b.l) % b.dt == 0) ++as;
        continue;
      }
      if (b.dt == 0) {
        int c = len - b.r;
        if (a.l <= c && c <= a.r && (c - a.l) % a.dt == 0) ++as;
        continue;
      }
      if (a.dt == b.dt) {
        int c = len - a.r;
        if (abs(b.l - c) % a.dt == 0) {
          int tl = max(c, b.l), tr = min(len - a.l, b.r);
          if (tl <= tr) as += (tr - tl) / a.dt + 1;
        }
      } else
        as += ex_work(a, b, len);
    }
  return as;
}
}  // namespace Yolanda
int main() {
  n = read(), m = read(), q = read();
  init_pw(n);
  for (int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1, u, v, c; i < n; i++)
    u = read(), v = read(), c = str(), G[u].push_back(make_pair(v, c)),
    G[v].push_back(make_pair(u, c));
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    len[i] = Str(tmp);
    My[i][0].copy(tmp, len[i]);
    ps[i][0] = AC[0].ins(tmp, len[i]);
    reverse(tmp + 1, tmp + len[i] + 1);
    My[i][1].copy(tmp, len[i]);
    ps[i][1] = AC[1].ins(tmp, len[i]);
  }
  AC[0].build();
  AC[1].build();
  bit[0].n = AC[0].sgn;
  bit[1].n = AC[1].sgn;
  for (int i = 1; i <= m; i++)
    My[i][0].build(), My[i][1].build(), My[i][0].Hash_work(),
        My[i][1].Hash_work(), My[i][0].Kmp_work(), My[i][1].Kmp_work();
  for (int i = 1, u, v, p, x; i <= q; i++) {
    u = read(), v = read(), p = read();
    int l = LCA(u, v);
    if (dep[u] - dep[l] >= len[p]) {
      x = jmp(u, dep[u] - dep[l] - len[p] + 1);
      ql[u].push_back((qry){1, p, i});
      ql[x].push_back((qry){-1, p, i});
    }
    if (dep[v] - dep[l] >= len[p]) {
      x = jmp(v, dep[v] - dep[l] - len[p] + 1);
      qr[v].push_back((qry){1, p, i});
      qr[x].push_back((qry){-1, p, i});
    }
    if (u != l && v != l) Ans[i] += Yolanda ::work(u, v, l, p);
    assert(Ans[i] >= 0);
  }
  cope(1, 0, 0, 0);
  for (int i = 1; i <= q; i++) cout << Ans[i] << '\n', assert(Ans[i] >= 0);
  return 0;
}
