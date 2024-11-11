#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;
bool fl[N];
map<int, int> s;
int n, q, k, lt, p[N], w[N], ft[N], gt[N], st[N], pos[N];
long long sum, vq, ans[N], v[N << 2], f[N << 2], tg[N << 2];
struct query {
  long long x, k, t, g;
} e[N];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline void build(int l, int r, int t) {
  tg[t] = 0;
  if (l == r) {
    v[t] = l + 1000000000000000ll, f[t] = v[t], pos[l] = t, ft[t] = l;
    return;
  }
  int d = (l + r) >> 1;
  build(l, d, t << 1), build(d + 1, r, t << 1 | 1),
      v[t] = min(v[t << 1], v[t << 1 | 1]),
      f[t] = max(f[t << 1], f[t << 1 | 1]);
}
inline void addx(int l, int r, int t, int ql, int qr, long long c) {
  if (tg[t]) {
    v[t << 1] += tg[t], v[t << 1 | 1] += tg[t];
    f[t << 1] += tg[t], f[t << 1 | 1] += tg[t];
    tg[t << 1] += tg[t], tg[t << 1 | 1] += tg[t], tg[t] = 0;
  }
  if (l == ql && r == qr) {
    if (c >= 1000000000000000ll)
      f[t] = 0;
    else
      f[t] += c;
    v[t] += c, tg[t] += c;
    return;
  }
  int d = (l + r) >> 1;
  if (ql <= d) addx(l, d, t << 1, ql, min(qr, d), c);
  if (d + 1 <= qr) addx(d + 1, r, t << 1 | 1, max(d + 1, ql), qr, c);
  v[t] = min(v[t << 1], v[t << 1 | 1]);
  f[t] = max(f[t << 1], f[t << 1 | 1]);
}
inline void update(int u) { addx(1, n, 1, u, u, 10000000000000000ll); }
inline int getpos(int t, long long c) {
  if (tg[t]) {
    v[t << 1] += tg[t], v[t << 1 | 1] += tg[t];
    f[t << 1] += tg[t], f[t << 1 | 1] += tg[t];
    tg[t << 1] += tg[t], tg[t << 1 | 1] += tg[t], tg[t] = 0;
  }
  if (ft[t]) {
    if (v[t] == c) return ft[t];
    return -1;
  }
  if (v[t << 1] <= c && c <= f[t << 1])
    return getpos(t << 1, c);
  else
    return getpos(t << 1 | 1, c);
}
inline void updatex() {
  vq = min(vq, v[1]);
  while (e[lt].x >= vq && lt > 0) {
    if (p[s[e[lt].x]])
      e[lt].x = p[s[e[lt].x]], e[lt].k = sum - e[lt].k;
    else {
      int z = getpos(1, e[lt].x);
      if (z > 0)
        e[lt].x = z, e[lt].k = sum - e[lt].k;
      else {
        long long c = (e[lt].x - vq) / k, z = e[lt].x - c * k;
        while (z < vq) c--, z += k;
        while (z >= vq + lt) z -= k, c++;
        e[lt].x = getpos(1, z), e[lt].k = sum - c - e[lt].k;
      }
    }
    lt--;
  }
}
inline int getpos(int l, int r, int t, int x) {
  if (tg[t]) {
    v[t << 1] += tg[t], v[t << 1 | 1] += tg[t];
    f[t << 1] += tg[t], f[t << 1 | 1] += tg[t];
    tg[t << 1] += tg[t], tg[t << 1 | 1] += tg[t], tg[t] = 0;
  }
  if (l == r) return v[t];
  int d = (l + r) >> 1;
  if (x <= d) return getpos(l, d, t << 1, x);
  return getpos(d + 1, r, t << 1 | 1, x);
}
inline void updatey() {
  while (e[lt].k <= sum && lt > 0) {
    if (e[lt].g) {
      lt--;
      continue;
    }
    if (gt[e[lt].x])
      ans[e[lt].t] = gt[e[lt].x];
    else {
      long long c = getpos(1, n, 1, e[lt].x);
      ans[e[lt].t] = c + (sum - e[lt].k) * k;
    }
    lt--;
  }
}
inline bool tmp(query a, query b) { return a.x < b.x; }
inline bool cmp(query a, query b) { return a.k > b.k; }
int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) w[i] = read() + 1, s[w[i]] = i;
  for (int i = 1; i <= q; i++) {
    e[i].x = read() + 1, e[i].k = read(), e[i].t = i;
    if (e[i].x < w[1]) ans[i] = e[i].x, e[i].g = 1;
  }
  sort(e + 1, e + q + 1, tmp), lt = q;
  build(1, n, 1), sum = 0, vq = v[1];
  for (int i = n; i >= 1; i--) {
    if (fl[i]) continue;
    k = i;
    long long c = v[1], t = (c - w[i]) / i, s = c - t * i;
    while (s > w[i]) s -= i, t++;
    while (s + i < w[i]) s += i, t--;
    addx(1, n, 1, 1, n, -t * i), sum += t;
    updatex();
    int j = i;
    st[0] = 0;
    while (v[1] <= w[j - 1] && j - 1 > 0) j--;
    for (int x = j; x <= i; x++)
      st[++st[0]] = getpos(1, w[x]), update(st[st[0]]), p[x] = st[st[0]];
    vq = min(vq, 1ll * w[j]);
    addx(1, n, 1, 1, n, -(j - 1)), sum++;
    for (int x = 1; x <= st[0]; x++) addx(1, n, 1, st[x], n, -1);
    updatex();
    i = j;
  }
  sort(e + 1, e + q + 1, cmp), lt = q;
  build(1, n, 1), sum = 0;
  for (int i = n; i >= 1; i--) {
    if (fl[i]) continue;
    k = i;
    long long c = v[1], t = (c - w[i]) / i, s = c - t * i;
    while (s > w[i]) s -= i, t++;
    while (s + i < w[i]) s += i, t--;
    addx(1, n, 1, 1, n, -t * i), sum += t;
    updatey();
    int j = i;
    while (v[1] <= w[j - 1] && j - 1 > 0) j--;
    st[0] = 0;
    for (int x = j; x <= i; x++)
      st[++st[0]] = getpos(1, w[x]), update(st[st[0]]), p[x] = st[st[0]];
    addx(1, n, 1, 1, n, -(j - 1)), sum++;
    for (int x = 1; x <= st[0]; x++) addx(1, n, 1, st[x], n, -1);
    i = j;
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i] - 1);
}
