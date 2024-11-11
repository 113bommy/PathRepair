#include <bits/stdc++.h>
using namespace std;
const long long inf = (1LL << 62) - 1 + (1LL << 62);
int x, y, d, n, m, b, g, by[110000], gl[110000], k, kiss[210000], dk[210000],
    tot;
bool vis[220000];
struct segment {
  int l, r;
  bool operator<(const segment &temp) const {
    if (l == temp.l) return r < temp.r;
    return l < temp.l;
  }
};
segment sg[210000], now[2], nw[210000];
set<segment> hs;
set<segment>::iterator it;
int num_sg, num_nw, grp[210000];
struct group {
  int by;
  bool operator<(const group &temp) const { return by % d < temp.by % d; }
};
group gp[210000];
void gcd(int n, int m) {
  int temp;
  if (m == 0) {
    d = n;
    x = 1;
    y = 0;
    return;
  }
  gcd(m, n % m);
  temp = x;
  x = y;
  y = temp - (n / m) * y;
}
bool binary(int left, int right, int by[], int x) {
  int mid;
  while (left <= right) {
    mid = (left + right) >> 1;
    if (by[mid] < x)
      left = mid + 1;
    else if (by[mid] > x)
      right = mid - 1;
    else
      return true;
  }
  return false;
}
bool check(double mid, int by[], int b, int n, int gl[], int g, int m) {
  int i, j, s, p, q, st;
  long long v;
  st = 0;
  for (i = 0; i <= tot; i++) {
    if (i == tot || gp[st] < gp[i]) {
      int now_l = 0, now_r = m / d - 1;
      num_nw = 0;
      for (j = st; j < i; j++) {
        kiss[j] = ((long long)mid - gp[j].by + n - 1) / n;
        kiss[j] = max(0, kiss[j]);
        if (kiss[j] >= m / d) break;
        v = (long long)((gp[st].by - gp[j].by) % m + m) % m;
        dk[j] = (int)((long long)k * (long long)v / d % (m / d));
        if (kiss[j] - dk[j] >= 0) {
          now_l = max(now_l, kiss[j] - dk[j]);
          now_r = min(now_r, m / d - 1 - dk[j]);
        } else {
          nw[num_nw].l = m / d - 1 - dk[j] + 1;
          nw[num_nw].r = m / d + kiss[j] - dk[j] - 1;
          if (nw[num_nw].l <= nw[num_nw].r) num_nw++;
        }
      }
      if (j < i || now_l > now_r) {
        st = i;
        continue;
      }
      nw[num_nw].l = 0;
      nw[num_nw].r = now_l - 1;
      if (nw[num_nw].l <= nw[num_nw].r) num_nw++;
      nw[num_nw].l = now_r + 1;
      nw[num_nw].r = m / d - 1;
      if (nw[num_nw].l <= nw[num_nw].r) num_nw++;
      sort(nw, nw + num_nw);
      num_sg = 1;
      for (j = 1; j < num_nw; j++) {
        if (nw[j].l > nw[num_sg - 1].r)
          nw[num_sg++] = nw[j];
        else
          nw[num_sg - 1].r = max(nw[num_sg - 1].r, nw[j].r);
      }
      num_sg = 0;
      for (j = 0; j <= num_nw; j++) {
        if (j == 0)
          sg[num_sg].l = 0;
        else
          sg[num_sg].l = nw[j - 1].r + 1;
        if (j == num_nw)
          sg[num_sg].r = m / d - 1;
        else
          sg[num_sg].r = nw[j].l - 1;
        if (sg[num_sg].l <= sg[num_sg].r) num_sg++;
      }
      for (j = 0; j < num_sg; j++)
        for (s = sg[j].l; s <= sg[j].r; s++) {
          int v = (int)((long long)s * (long long)n % m);
          v = (v + gp[st].by) % m;
          if (!binary(0, g - 1, gl, v)) return false;
        }
      st = i;
    }
  }
  return true;
}
long long solve(int by[], int b, int n, int gl[], int g, int m) {
  int i, j, s, p, q, num, st;
  long long low, high, mid;
  gcd(n, m);
  k = (x % m + m) % m;
  tot = 0;
  for (i = 0; i < b; i++) gp[tot++].by = by[i];
  for (i = 0; i < g; i++) gp[tot++].by = gl[i];
  for (i = 0; i < tot; i++) grp[i] = gp[i].by;
  sort(grp, grp + tot);
  sort(gp, gp + tot);
  if (d > tot) return inf;
  memset(vis, false, sizeof(vis));
  for (i = 0; i < tot; i++) vis[grp[i] % d] = true;
  for (i = 0; i < d; i++) {
    if (!vis[i]) return inf;
  }
  low = 0;
  high = (long long)n * (long long)m / d + max(n, m);
  while (low <= high) {
    mid = (low + high) >> 1;
    if (check(mid, by, b, n, gl, g, m))
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (high == (long long)n * (long long)m / d + max(m, n)) high = inf;
  return high;
}
int main() {
  int i, j, s, p, q;
  long long res;
  scanf("%d%d", &n, &m);
  scanf("%d", &b);
  for (i = 0; i < b; i++) scanf("%d", &by[i]);
  sort(by, by + b);
  scanf("%d", &g);
  for (i = 0; i < g; i++) scanf("%d", &gl[i]);
  sort(gl, gl + g);
  res = max(solve(by, b, n, gl, g, m), solve(gl, g, m, by, b, n));
  if (res == inf) res = -1;
  printf("%I64d\n", res);
  return 0;
}
