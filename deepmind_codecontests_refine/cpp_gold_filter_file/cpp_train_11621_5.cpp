#include <bits/stdc++.h>
inline long long read() {
  long long data = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
  return data * w;
}
const long long INF(3e18);
const int N(8e5 + 10);
int n, m, k, cnt, s[N];
long long C, a[N], b[N], c[N], t[N], mx1[N << 2], mx2[N << 2], tag[N << 2];
void Modify(int p, long long v1, long long v2, int x = 1, int l = 1,
            int r = k) {
  if (l == r)
    return (void)(mx1[x] = std::max(mx1[x], v1), mx2[x] = std::max(mx2[x], v2));
  int mid = (l + r) >> 1, ls = x << 1, rs = ls | 1;
  if (tag[x])
    mx1[ls] += tag[x], mx2[ls] += tag[x], tag[ls] += tag[x], mx1[rs] += tag[x],
        mx2[rs] += tag[x], tag[rs] += tag[x], tag[x] = 0;
  if (p <= mid)
    Modify(p, v1, v2, ls, l, mid);
  else
    Modify(p, v1, v2, rs, mid + 1, r);
  mx1[x] = std::max(mx1[ls], mx1[rs]), mx2[x] = std::max(mx2[ls], mx2[rs]);
}
void Add(int ql, int qr, long long v, int x = 1, int l = 1, int r = k) {
  if (ql <= l && r <= qr) return (void)(mx1[x] += v, mx2[x] += v, tag[x] += v);
  int mid = (l + r) >> 1, ls = x << 1, rs = ls | 1;
  if (tag[x])
    mx1[ls] += tag[x], mx2[ls] += tag[x], tag[ls] += tag[x], mx1[rs] += tag[x],
        mx2[rs] += tag[x], tag[rs] += tag[x], tag[x] = 0;
  if (ql <= mid) Add(ql, qr, v, ls, l, mid);
  if (mid < qr) Add(ql, qr, v, rs, mid + 1, r);
  mx1[x] = std::max(mx1[ls], mx1[rs]), mx2[x] = std::max(mx2[ls], mx2[rs]);
}
void Query(int ql, int qr, long long &v1, long long &v2, int x = 1, int l = 1,
           int r = k) {
  if (ql > qr) return;
  if (ql <= l && r <= qr)
    return (void)(v1 = std::max(v1, mx1[x]), v2 = std::max(v2, mx2[x]));
  int mid = (l + r) >> 1, ls = x << 1, rs = ls | 1;
  if (tag[x])
    mx1[ls] += tag[x], mx2[ls] += tag[x], tag[ls] += tag[x], mx1[rs] += tag[x],
        mx2[rs] += tag[x], tag[rs] += tag[x], tag[x] = 0;
  if (ql <= mid) Query(ql, qr, v1, v2, ls, l, mid);
  if (mid < qr) Query(ql, qr, v1, v2, rs, mid + 1, r);
}
int main() {
  n = read() << 1, m = read() << 1, C = read();
  for (int i = 1; i <= n; i += 2) a[i] = read(), a[i + 1] = read();
  for (int i = 1; i <= m; i += 2) b[i] = read(), b[i + 1] = read();
  std::memcpy(c + 1, a + 1, n << 3);
  std::memcpy(c + n + 1, b + 1, m << 3);
  std::sort(c + 1, c + n + m + 1),
      cnt = std::unique(c + 1, c + n + m + 1) - c - 1;
  t[k = 1] = 0;
  long long delt = 0;
  for (int i = 1, u = 1, v = 1; i < cnt; i++) {
    auto len = c[i + 1] - c[i];
    s[i] = s[i - 1];
    if (c[i] == a[u]) s[i] ^= 1, ++u;
    if (c[i] == b[v]) s[i] ^= 2, ++v;
    switch (s[i]) {
      case 1:
        delt -= len;
        break;
      case 2:
        delt += len;
        break;
      case 3:
        t[++k] = delt - C, t[++k] = delt + C;
        break;
    }
  }
  std::sort(t + 1, t + k + 1), k = std::unique(t + 1, t + k + 1) - t - 1;
  Add(1, k, -INF), Modify((std::lower_bound(t + 1, t + k + 1, (0)) - t), 0, 0);
  long long sx = 0, sy = 0;
  for (int i = 1; i < cnt; i++) {
    auto len = c[i + 1] - c[i];
    if (s[i] == 1)
      sx += len;
    else if (s[i] == 2)
      sy += len;
    else if (s[i] == 3) {
      int l = (std::lower_bound(t + 1, t + k + 1, (sy - sx - C)) - t),
          r = (std::lower_bound(t + 1, t + k + 1, (sy - sx + C)) - t);
      auto v1 = -INF, v2 = -INF;
      Query(1, l - 1, v1, v2), Modify(l, v1, v1 - t[l]), v1 = v2 = -INF;
      Query(r + 1, k, v1, v2), Modify(r, v2 + t[r], v2), Add(l, r, len),
          Add(1, k, len);
    }
  }
  printf("%lld\n", mx1[1] + sx);
  return 0;
}
