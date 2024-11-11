#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
int K;
struct uz {
  int x, l, r, v;
  bool operator<(const uz &o) const { return x < o.x; }
} q[100005];
int lb(int l, int r) {
  int ans = 0;
  l--;
  for (int i = 1; i <= k; i <<= 1) {
    int x =
        (r / i - l / i) - (((i << 1) > k) ? 0 : (r / (i << 1) - l / (i << 1)));
    if (x & 1) ans |= i;
  }
  return ans;
}
struct node {
  int ls, rs, w, la, fi;
} T[100005 * 30];
int cnt;
void up(int rt) {
  if (T[rt].la != 0)
    T[rt].w = T[rt].fi;
  else
    T[rt].w = T[T[rt].ls].w ^ T[T[rt].rs].w;
}
void upt(int &rt, int l, int r, int L, int R, int v) {
  if (r < L || R < l) return;
  if (!rt) rt = ++cnt;
  T[rt].fi = lb(l, r);
  if (L <= l && r <= R) {
    T[rt].la += v;
    up(rt);
    return;
  }
  int mid = (l + r) >> 1;
  upt(T[rt].ls, l, mid, L, R, v);
  upt(T[rt].rs, mid + 1, r, L, R, v);
  up(rt);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (K = 1; K <= k; K <<= 1)
    ;
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    q[i].x = a;
    q[i].l = b;
    q[i].r = d;
    q[i].v = 1;
    q[i + m].x = c + 1;
    q[i + m].l = b;
    q[i + m].r = d;
    q[i + m].v = -1;
  }
  sort(q + 1, q + 1 + m + m);
  int ans = 0, rt = 0;
  for (int(i) = 1; (i) <= (int)(m + m + 1); (i)++) {
    if (q[i].x != q[i - 1].x) {
      int x = lb(q[i - 1].x, q[i].x - 1);
      int y = T[1].w;
      int xl = 0, yl = 0;
      for (int j = K >> 1; j; j >>= 1) {
        xl += (x & j) > 0;
        yl += (y & j) > 0;
        long long tmp = xl * yl;
        if (tmp & 1) {
          ans ^= j;
        }
      }
    }
    upt(rt, 1, n, q[i].l, q[i].r, q[i].v);
  }
  puts(ans ? "Hamed" : "Malek");
  return 0;
}
