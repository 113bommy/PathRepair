#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int F = 10020;
long long ans;
int n, k, c[F], cnt;
struct node {
  int r, x, f;
  inline bool operator<(const node &a) const { return r > a.r; }
} it[N];
struct dat {
  int op, x, y, w;
  inline bool operator<(const dat &a) const {
    if (x == a.x) return op < a.op;
    return x < a.x;
  }
} Q[N * 5], t[N * 5];
inline int lowbit(int x) { return x & -x; }
inline void add(int x, int d) {
  for (; x < F; x += lowbit(x)) c[x] += d;
}
inline int query(int x) {
  int res = 0;
  for (; x; x -= lowbit(x)) res += c[x];
  return res;
}
inline void clear(int x) {
  for (; x < F; x += lowbit(x)) c[x] = 0;
}
inline void work(int l, int r) {
  if (r - l <= 1) return;
  int mid = (l + r) >> 1;
  work(l, mid), work(mid, r);
  int p = l, q = mid, o = l;
  while (p < mid && q < r)
    if (Q[p] < Q[q]) {
      if (Q[p].op == 0) add(Q[p].y, 1);
      t[o++] = Q[p++];
    } else {
      if (Q[q].op == 1) ans += query(Q[q].y) * Q[q].w;
      t[o++] = Q[q++];
    }
  while (p < mid) t[o++] = Q[p++];
  while (q < r) {
    if (Q[q].op == 1) ans += query(Q[q].y) * Q[q].w;
    t[o++] = Q[q++];
  }
  for (int i = l; i < r; i++) {
    if (Q[i].op == 0) clear(Q[i].y);
    Q[i] = t[i];
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &it[i].x, &it[i].r, &it[i].f);
  sort(it + 1, it + n + 1);
  for (int i = 1; i <= n; i++) {
    node &T = it[i];
    int x1 = T.x - T.r, y1 = max(T.f - k, 1);
    int x2 = T.x + T.r, y2 = T.f + k;
    Q[cnt++] = (dat){1, x1 - 1, y1 - 1, 1};
    Q[cnt++] = (dat){1, x1 - 1, y2, -1};
    Q[cnt++] = (dat){1, x2, y1 - 1, -1};
    Q[cnt++] = (dat){1, x2, y2, 1};
    Q[cnt++] = (dat){0, T.x, T.f, 0};
  }
  work(0, cnt);
  cout << ans << endl;
  return 0;
}
