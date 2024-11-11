#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
long long readint() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct node {
  int lch, rch, val;
} t[5000005];
const int cys = 998244353;
int n, m, rt, cnt, ncnt;
long long ans = 0;
pair<long long, long long> a[100005];
long long pw[65];
void add(int dep, long long l, long long r, long long ql, long long qr,
         long long v) {
  if (l == ql && r == qr) return (void)(a[++cnt] = make_pair(v, dep + 1));
  long long mid = (l + r) / 2;
  if (qr <= mid)
    add(dep - 1, l, mid, ql, qr, v);
  else if (ql > mid)
    add(dep - 1, mid + 1, r, ql, qr, v + (1ll << dep));
  else
    add(dep - 1, l, mid, ql, mid, v),
        add(dep - 1, mid + 1, r, mid + 1, qr, v + (1ll << dep));
}
void ask(int &id, long long l, long long r, long long ql, long long qr, int dep,
         long long v, int sd) {
  if (!id) id = ++ncnt;
  if (t[id].val) return;
  if (dep + 1 == sd || (l == ql && r == qr)) return (void)(t[id].val = 1);
  long long mid = (l + r) / 2;
  if (v & (1ll << dep)) {
    if (qr <= mid)
      ask(t[id].rch, mid + 1, r, ql ^ (1ll << dep), qr ^ (1ll << dep), dep - 1,
          v, sd);
    else if (ql > mid)
      ask(t[id].lch, l, mid, ql ^ (1ll << dep), qr ^ (1ll << dep), dep - 1, v,
          sd);
    else
      ask(t[id].lch, l, mid, l, qr ^ (1ll << dep), dep - 1, v, sd),
          ask(t[id].rch, mid + 1, r, ql ^ (1ll << dep), r, dep - 1, v, sd);
  } else {
    if (qr <= mid)
      ask(t[id].lch, l, mid, ql, qr, dep - 1, v, sd);
    else if (ql > mid)
      ask(t[id].rch, mid + 1, r, ql, qr, dep - 1, v, sd);
    else
      ask(t[id].lch, l, mid, ql, mid, dep - 1, v, sd),
          ask(t[id].rch, mid + 1, r, mid + 1, qr, dep - 1, v, sd);
  }
}
void getans(int id, long long v, int dep) {
  if (!id) return;
  if (t[id].val)
    return (void)(ans =
                      (ans + v * pw[dep + 1] +
                       (dep + 1 == 0 ? 0 : pw[dep] * (pw[dep + 1] - 1) % cys)) %
                      cys);
  getans(t[id].lch, v, dep - 1);
  getans(t[id].rch, v + (1ll << dep), dep - 1);
}
int main() {
  n = readint();
  long long x, y;
  for (int i = 1; i <= n; i++) {
    x = readint();
    y = readint();
    add(59, 0, (1ll << 60) - 1, x, y, 0);
  }
  m = readint();
  for (int i = 1; i <= m; i++) {
    x = readint();
    y = readint();
    for (int j = 1; j <= cnt; j++)
      ask(rt, 0, (1ll << 60) - 1, x, y, 59, a[j].first, a[j].second);
  }
  pw[0] = 1;
  for (int i = 1; i <= 60; i++) pw[i] = pw[i - 1] * 2 % cys;
  getans(rt, 0, 59);
  printf("%lld\n", ans);
  return 0;
}
