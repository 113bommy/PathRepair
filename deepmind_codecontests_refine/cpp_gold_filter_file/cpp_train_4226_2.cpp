#include <bits/stdc++.h>
using namespace std;
namespace IO {
char buf_[1 << 21], *p1_ = buf_, *p2_ = buf_;
inline long long in() {
  long long s = 0, f = 1;
  char x = (p1_ == p2_ && (p2_ = (p1_ = buf_) + fread(buf_, 1, 1 << 21, stdin),
                           p1_ == p2_)
                ? EOF
                : *p1_++);
  for (; x < '0' || x > '9';
       x = (p1_ == p2_ && (p2_ = (p1_ = buf_) + fread(buf_, 1, 1 << 21, stdin),
                          p1_ == p2_)
                ? EOF
                : *p1_++))
    if (x == '-') f = -1;
  for (; x >= '0' && x <= '9';
       x = (p1_ == p2_ && (p2_ = (p1_ = buf_) + fread(buf_, 1, 1 << 21, stdin),
                          p1_ == p2_)
                ? EOF
                : *p1_++))
    s = (s * 10) + (x & 15);
  return f == 1 ? s : -s;
}
char _buf[1 << 21];
long long _pos = -1;
inline void flush() { fwrite(_buf, 1, _pos + 1, stdout), _pos = -1; }
inline void pc(char x) {
  if (_pos == (1 << 21) - 1) flush();
  _buf[++_pos] = x;
}
inline void out(long long x) {
  char k[30];
  long long pos = 0;
  if (!x) return pc('0');
  if (x < 0) pc('-'), x = -x;
  while (x) k[++pos] = (x % 10) | 48, x /= 10;
  for (register long long i = pos; i; i--) pc(k[i]);
}
inline void out(string x) {
  long long len = x.size();
  for (register long long i = 0; i < len; ++i) pc(x[i]);
}
}  // namespace IO
using namespace IO;
const long long A = 5e5 + 5;
const long long INF = 3e18;
long long n, m;
long long G, S;
long long ans = INF;
struct Road {
  long long x, y, g, s;
  inline friend bool operator<(Road u, Road v) { return u.g < v.g; }
} p[A];
struct LCT {
  long long ch[A][2], f[A], rev[A], mxg[A], mxs[A], xg[A], xs[A];
  struct MG {
    long long x;
    MG(long long _x = 0) { x = _x; }
    inline friend bool operator<(MG u, MG v) { return p[u.x].g > p[v.x].g; }
  };
  struct MS {
    long long x;
    MS(long long _x = 0) { x = _x; }
    inline friend bool operator<(MS u, MS v) { return p[u.x].s > p[v.x].s; }
  };
  multiset<MG> mg[A];
  multiset<MS> ms[A];
  inline long long isroot(long long x) {
    return ch[f[x]][0] != x && ch[f[x]][1] != x;
  }
  inline long long Maxg(long long x, long long y) {
    return p[x].g > p[y].g ? x : y;
  }
  inline long long Maxs(long long x, long long y) {
    return p[x].s > p[y].s ? x : y;
  }
  inline void pushup(long long x) {
    mxg[x] =
        Maxg(Maxg(x, (*mg[x].begin()).x), Maxg(mxg[ch[x][0]], mxg[ch[x][1]]));
    mxs[x] =
        Maxs(Maxs(x, (*ms[x].begin()).x), Maxs(mxs[ch[x][0]], mxs[ch[x][1]]));
    xg[x] = Maxg(x, Maxg(xg[ch[x][0]], xg[ch[x][1]]));
    xs[x] = Maxs(x, Maxs(xs[ch[x][0]], xs[ch[x][1]]));
  }
  inline void reverse(long long x) {
    if (x) swap(ch[x][0], ch[x][1]), rev[x] ^= 1;
  }
  inline void pushdown(long long x) {
    if (rev[x]) reverse(ch[x][0]), reverse(ch[x][1]), rev[x] ^= 1;
  }
  inline void rotate(long long x) {
    long long y = f[x], z = f[y];
    long long k = (ch[y][1] == x);
    if (!isroot(y)) ch[z][(ch[z][1] == y)] = x;
    f[x] = z, ch[y][k] = ch[x][k ^ 1];
    if (ch[x][k ^ 1]) f[ch[x][k ^ 1]] = y;
    ch[x][k ^ 1] = y, f[y] = x;
    pushup(y);
    return;
  }
  long long st[A], top;
  inline void pushpath(long long x) {
    top = 0;
    st[++top] = x;
    for (long long i = x; !isroot(i); i = f[i]) st[++top] = f[i];
    for (long long i = top; i; i--) pushdown(st[i]);
    return;
  }
  inline void splay(long long x) {
    pushpath(x);
    while (!isroot(x)) {
      long long y = f[x], z = f[y];
      if (!isroot(y)) {
        if ((ch[y][1] == x) == (ch[z][1] == y))
          rotate(y);
        else
          rotate(x);
      }
      rotate(x);
    }
    pushup(x);
    return;
  }
  inline void access(long long x) {
    for (long long y = 0; x; y = x, x = f[x]) {
      splay(x);
      if (y) {
        mg[x].erase(mg[x].find(MG(mxg[y])));
        ms[x].erase(ms[x].find(MS(mxs[y])));
      }
      if (ch[x][1]) {
        mg[x].insert(MG(mxg[ch[x][1]]));
        ms[x].insert(MS(mxs[ch[x][1]]));
      }
      ch[x][1] = y;
      pushup(x);
    }
  }
  inline void makeroot(long long x) { access(x), splay(x), reverse(x); }
  inline long long findroot(long long x) {
    access(x), splay(x);
    while (ch[x][0]) pushdown(x), x = ch[x][0];
    return x;
  }
  inline void split(long long x, long long y) {
    makeroot(x);
    access(y);
    splay(y);
  }
  inline void link(long long x, long long y) {
    makeroot(x);
    if (findroot(y) != x)
      f[x] = y, mg[y].insert(MG(mxg[x])), ms[y].insert(MS(mxs[x]));
    pushup(y);
  }
  inline void cut(long long x, long long y) {
    makeroot(x);
    if (findroot(y) == x && f[x] == y && ch[y][0] == x) f[x] = 0, ch[y][0] = 0;
    pushup(y);
  }
  struct DSU {
    long long f[A], num[A];
    inline long long find(long long x) {
      return f[x] == x ? f[x] : f[x] = find(f[x]);
    }
    inline void merge(long long x, long long y) {
      if (find(x) != find(y))
        num[find(y)] += num[find(x)], f[find(x)] = find(y);
    }
  } D;
  inline void work(long long now) {
    if (D.find(p[now].x) != D.find(p[now].y)) {
      link(p[now].x + m, now);
      link(p[now].y + m, now);
      D.merge(p[now].x, p[now].y);
    } else {
      split(p[now].x + m, p[now].y + m);
      if (p[xs[p[now].y + m]].s > p[now].s) {
        long long t = xs[p[now].y + m];
        cut(p[t].x + m, t), cut(p[t].y + m, t);
        link(p[now].x + m, now), link(p[now].y + m, now);
      }
    }
    if (D.num[D.find(1)] == n) {
      makeroot(m + 1);
      ans = min(ans, p[mxg[m + 1]].g * G + p[mxs[m + 1]].s * S);
    }
    return;
  }
} T;
signed main() {
  n = in(), m = in(), G = in(), S = in();
  for (long long i = 1; i <= m; i++)
    p[i].x = in(), p[i].y = in(), p[i].g = in(), p[i].s = in();
  sort(p + 1, p + 1 + m);
  for (long long i = 1; i <= n; i++) T.D.f[i] = i, T.D.num[i] = 1;
  for (long long i = 1; i <= m; i++) T.mxg[i] = T.mxs[i] = i;
  for (long long i = 1; i <= m; i++) T.work(i);
  out(ans == INF ? -1 : ans), pc('\n');
  flush();
  return 0;
}
