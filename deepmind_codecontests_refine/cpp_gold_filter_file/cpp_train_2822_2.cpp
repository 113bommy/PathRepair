#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 500;
inline int read() {
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    ;
  int res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  return res;
}
struct node {
  int x, q, r;
} d[N];
bool cmp(node a, node b) { return a.r > b.r; }
long long ans;
struct que {
  int x, y, w;
  que(int xx = 0, int yy = 0, int ww = 0) { x = xx, y = yy, w = ww; }
} q[N * 5], fz[N * 5];
int n, mq, K, px[N * 3];
struct Tree {
  long long d[N * 3];
  int lowbit(int x) { return x & -x; }
  long long sum(int x) {
    long long res = 0;
    for (int i = x; i; i -= lowbit(i)) res += d[i];
    return res;
  }
  void upt(int x, int v) {
    for (int i = x; i <= mq; i += lowbit(i)) d[i] += v;
  }
} T;
void solve(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  solve(l, mid);
  solve(mid + 1, r);
  int p = l, p1 = l, p2 = mid + 1;
  while (p1 <= mid && p2 <= r) {
    if (q[p1].x <= q[p2].x) {
      if (q[p1].w == 0) T.upt(q[p1].y, 1);
      fz[p++] = q[p1++];
    } else {
      if (q[p2].w != 0) ans += T.sum(q[p2].y) * q[p2].w;
      fz[p++] = q[p2++];
    }
  }
  int pp = p1 - 1;
  while (p1 <= mid) fz[p++] = q[p1++];
  while (p2 <= r) {
    if (q[p2].w != 0) ans += T.sum(q[p2].y) * q[p2].w;
    fz[p++] = q[p2++];
  }
  for (int i = l; i <= pp; i++)
    if (!q[i].w) T.upt(q[i].y, -1);
  for (int i = l; i <= r; i++) q[i] = fz[i];
}
int main() {
  n = read();
  K = read();
  int x, r, zs;
  for (int i = 1; i <= n; i++) {
    x = read();
    r = read();
    zs = read();
    d[i] = (node){x, zs, r};
    px[++px[0]] = zs;
    px[++px[0]] = zs - K - 1;
    px[++px[0]] = zs + K;
  }
  sort(d + 1, d + 1 + n, cmp);
  sort(px + 1, px + 1 + px[0]);
  mq = unique(px + 1, px + 1 + px[0]) - px - 1;
  int qtot = 0;
  for (int i = 1; i <= n; i++) {
    int nq, lq, rq;
    nq = lower_bound(px + 1, px + 1 + mq, d[i].q) - px;
    lq = lower_bound(px + 1, px + 1 + mq, d[i].q - K - 1) - px;
    rq = lower_bound(px + 1, px + 1 + mq, d[i].q + K) - px;
    q[++qtot] = que(d[i].x - d[i].r - 1, rq, -1);
    q[++qtot] = que(d[i].x + d[i].r, lq, -1);
    q[++qtot] = que(d[i].x - d[i].r - 1, lq, 1);
    q[++qtot] = que(d[i].x + d[i].r, rq, 1);
    q[++qtot] = que(d[i].x, nq, 0);
  }
  solve(1, qtot);
  printf("%lld", ans);
  return 0;
}
