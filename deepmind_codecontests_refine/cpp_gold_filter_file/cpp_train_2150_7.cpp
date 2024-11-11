#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, cnt1, cnt2, sd = 2e5, inf = 1e9;
long long ans;
struct node {
  int x, y;
  node(int _x = 0, int _y = 0) { x = _x, y = _y; }
  bool operator<(node const &a) const { return x < a.x; }
} p1[100010], p2[100010];
struct seg {
  int mx[4 * 100010], mn[4 * 100010];
  void bu(int i, int l, int r, int p) {
    if (l == r) {
      if (p == 1)
        mn[i] = mx[i] = p1[l].y;
      else
        mn[i] = mx[i] = p2[l].y;
      return;
    }
    bu(i * 2, l, (l + r) / 2, p);
    bu(i * 2 + 1, (l + r) / 2 + 1, r, p);
    mn[i] = min(mn[i * 2], mn[i * 2 + 1]);
    mx[i] = max(mx[i * 2], mx[i * 2 + 1]);
  }
  int qyx(int i, int l, int r, int ql, int qr) {
    if (ql > r || l > qr) return -inf;
    if (ql <= l && r <= qr) return mx[i];
    return max(qyx(i * 2, l, (l + r) / 2, ql, qr),
               qyx(i * 2 + 1, (l + r) / 2 + 1, r, ql, qr));
  }
  int qyn(int i, int l, int r, int ql, int qr) {
    if (ql > r || l > qr) return inf;
    if (ql <= l && r <= qr) return mn[i];
    return min(qyn(i * 2, l, (l + r) / 2, ql, qr),
               qyn(i * 2 + 1, (l + r) / 2 + 1, r, ql, qr));
  }
} tr;
int work1(int a, int b) {
  if ((a & 1) ^ (b & 1)) return b + 1;
  return b;
}
int work2(int a, int b) {
  if ((a & 1) ^ (b & 1)) return b - 1;
  return b;
}
int main() {
  int i, s, a, b, j, k, s1, s2;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    if ((a + b) & 1)
      p1[++cnt1] = node(a + b, a - b);
    else
      p2[++cnt2] = node(a + b, a - b);
  }
  sort(p1 + 1, p1 + 1 + cnt1);
  sort(p2 + 1, p2 + 1 + cnt2);
  if (cnt1) {
    tr.bu(1, 1, cnt1, 1);
    for (i = -2e5, s1 = 0, s2 = 1; i <= 2e5; i++) {
      if (i & 1) continue;
      while (s1 < cnt1 && p1[s1 + 1].x < i) s1++;
      while (s2 <= cnt1 && p1[s2].x <= i) s2++;
      a = work1(i,
                max(tr.qyn(1, 1, cnt1, 1, s1), tr.qyn(1, 1, cnt1, s2, n)) + 1);
      b = work2(i,
                min(tr.qyx(1, 1, cnt1, 1, s1), tr.qyx(1, 1, cnt1, s2, n)) - 1);
      if (a <= b) ans += 1 + (b - a) / 2;
    }
  }
  if (cnt2) {
    tr.bu(1, 1, cnt2, 2);
    for (i = -2e5, s1 = 0, s2 = 1; i <= 2e5; i++) {
      if (!(i & 1)) continue;
      while (s1 < cnt2 && p2[s1 + 1].x < i) s1++;
      while (s2 <= cnt2 && p2[s2].x <= i) s2++;
      a = work1(i,
                max(tr.qyn(1, 1, cnt2, 1, s1), tr.qyn(1, 1, cnt2, s2, n)) + 1);
      b = work2(i,
                min(tr.qyx(1, 1, cnt2, 1, s1), tr.qyx(1, 1, cnt2, s2, n)) - 1);
      if (a <= b) ans += 1 + (b - a) / 2;
    }
  }
  printf("%I64d", ans);
  return 0;
}
