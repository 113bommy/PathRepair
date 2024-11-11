#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
template <typename T>
inline void read(T &x) {
  x = 0;
  T fl = 1;
  char ch = 0;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') fl = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + (ch ^ 48);
  x *= fl;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
const int N = 1e5 + 5;
struct data {
  int s, m, r, t;
  data(int x = 0) { t = x; }
  bool operator<(const data &b) const { return t < b.t; }
  long long calc(long long tim) { return min(s + tim * r, m * 1ll); }
} a[18][N];
struct seg {
  int trt[N << 2];
  long long trm[18][N << 2], trr[18][N << 2];
  void pushdown(int nod) {
    if (trt[nod] >= 0) trt[(nod << 1)] = trt[(nod << 1 | 1)] = trt[nod];
  }
  void pushup(int nod) {
    if (trt[(nod << 1)] != trt[(nod << 1 | 1)])
      trt[nod] = -1;
    else
      trt[nod] = trt[(nod << 1)];
  }
  void build(int nod, int l, int r, int dep) {
    trt[nod] = -2;
    if (l == r) {
      read(a[dep][l].s, a[dep][l].m, a[dep][l].r);
      if (a[dep][l].r == 0)
        a[dep][l].t = inf;
      else
        a[dep][l].t = a[dep][l].m % a[dep][l].r == 0
                          ? a[dep][l].m / a[dep][l].r
                          : a[dep][l].m / a[dep][l].r + 1;
      trm[dep][l] = trm[dep][l - 1] + a[dep][l].m;
      trr[dep][l] = trr[dep][l - 1] + a[dep][l].r;
      return;
    }
    int mid = (l + r) >> 1;
    build((nod << 1), l, mid, dep + 1);
    build((nod << 1 | 1), mid + 1, r, dep + 1);
    for (int i = (l); i <= (r); i++) a[dep][i] = a[dep + 1][i];
    sort(a[dep] + l, a[dep] + r + 1);
    for (int i = (l); i <= (r); i++) {
      trm[dep][i] = trm[dep][i - 1] + a[dep][i].m;
      trr[dep][i] = trr[dep][i - 1] + a[dep][i].r;
    }
  }
  long long query(int tim, int nod, int l, int r, int ql, int qr, int dep) {
    long long res = 0;
    if (ql <= l && r <= qr && trt[nod] != -1) {
      if (trt[nod] == -2)
        for (int i = (l); i <= (r); i++) res += a[dep][i].calc(tim);
      else {
        int i = upper_bound(a[dep] + l, a[dep] + 1 + r, data(tim - trt[nod])) -
                a[dep] - 1;
        res = (tim - trt[nod]) * (trr[dep][r] - trr[dep][i]) + trm[dep][i] -
              trm[dep][l - 1];
      }
      trt[nod] = tim;
      return res;
    }
    pushdown(nod);
    int mid = (l + r) >> 1;
    if (ql <= mid) res += query(tim, (nod << 1), l, mid, ql, qr, dep + 1);
    if (qr > mid)
      res += query(tim, (nod << 1 | 1), mid + 1, r, ql, qr, dep + 1);
    pushup(nod);
    return res;
  }
} sgt;
int n, m;
int main() {
  read(n);
  sgt.build(1, 1, n, 0);
  read(m);
  for (int _ = (1); _ <= (m); _++) {
    int t, l, r;
    read(t);
    read(l);
    read(r);
    printf("%lld\n", sgt.query(t, 1, 1, n, l, r, 0));
  }
  return 0;
}
