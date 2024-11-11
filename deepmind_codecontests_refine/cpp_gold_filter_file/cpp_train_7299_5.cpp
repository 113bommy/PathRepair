#include <bits/stdc++.h>
using namespace std;
bool cur1;
int n, m, K;
int L[100005 * 120], R[100005 * 120], res[100005 * 120], tt, rt[100005 * 3];
int update(int p, int l, int r, int x, int v) {
  int c = ++tt;
  L[c] = L[p], R[c] = R[p];
  if (l == r) {
    res[c] = min((p ? res[p] : 0x3f3f3f3f), v);
    return c;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    L[c] = update(L[p], l, mid, x, v);
  else
    R[c] = update(R[p], mid + 1, r, x, v);
  res[c] = max(res[L[c]], res[R[c]]);
  return c;
}
int query(int p, int u, int v, int l, int r) {
  if (u <= l && r <= v) {
    return res[p];
  }
  int mid = (l + r) >> 1;
  int ans = 0;
  if (u <= mid) ans = max(ans, query(L[p], u, v, l, mid));
  if (v > mid) ans = max(ans, query(R[p], u, v, mid + 1, r));
  return ans;
}
struct seg {
  int a, b, c;
  bool operator<(const seg &_) const {
    if (a != _.a) return a < _.a;
    if (c != _.c) return c < _.c;
    if (b != _.b) return b > _.b;
  }
} Sg[100005 * 3];
int B[100005 * 3];
void solve() {
  tt = 0;
  int tot = 0;
  scanf("%d %d %d", &n, &m, &K);
  for (int a, b, c, i = 1; i <= K; i++) {
    scanf("%d %d %d", &a, &b, &c);
    B[i] = a;
    Sg[i] = (seg){a, b, c};
  }
  sort(B + 1, B + K + 1);
  sort(Sg + 1, Sg + K + 1);
  tot = unique(B + 1, B + 1 + K) - B - 1;
  for (int i = 1; i <= n; i++)
    rt[tot + 1] = update(rt[tot + 1], 1, n, i, 0x3f3f3f3f);
  Sg[K + 1].a = 0x3f3f3f3f;
  for (int i = K; i >= 1; i--) {
    int t = lower_bound(B + 1, B + 1 + tot, Sg[i].a) - B;
    if (Sg[i].a != Sg[i + 1].a) {
      rt[t] = update(rt[t + 1], 1, n, Sg[i].c, Sg[i].b);
    } else
      rt[t] = update(rt[t], 1, n, Sg[i].c, Sg[i].b);
  }
  while (m--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (c > B[tot]) {
      puts("no");
      fflush(stdout);
      continue;
    } else {
      int t = lower_bound(B + 1, B + 1 + tot, c) - B;
      if (query(rt[t], a, b, 1, n) <= d)
        puts("yes");
      else
        puts("no");
    }
    fflush(stdout);
  }
}
bool cur2;
int main() {
  solve();
  return 0;
}
