#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
int q[MAXN + 10], qcnt, r, g, rg, n, Min[MAXN * 4 + 10], l[MAXN + 10];
long long dis[MAXN + 10], dp[MAXN + 10];
void build(int u, int l, int r) {
  Min[u] = n + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
}
void Insert(int u, int l, int r, int pos, int v) {
  Min[u] = v;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (pos <= mid)
    Insert(u << 1, l, mid, pos, v);
  else
    Insert(u << 1 | 1, mid + 1, r, pos, v);
}
int Query(int u, int l, int r, int L, int R) {
  if (L <= l && r <= R) return Min[u];
  int mid = (l + r) >> 1;
  int ret = n + 1;
  if (L <= mid) ret = min(ret, Query(u << 1, l, mid, L, R));
  if (R > mid) ret = min(ret, Query(u << 1 | 1, mid + 1, r, L, R));
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &g, &r), rg = r + g;
  int offset, tmp;
  scanf("%d", &offset);
  for (int i = 2; i <= n; i++)
    scanf("%I64d", &dis[i]), l[i] = (l[i - 1] + dis[i]) % rg,
                             dis[i] += dis[i - 1];
  scanf("%d", &tmp);
  for (int i = 1; i <= n; i++) q[++qcnt] = l[i], q[++qcnt] = (l[i] + g) % rg;
  sort(q + 1, q + 1 + qcnt);
  qcnt = unique(q + 1, q + 1 + qcnt) - q - 1;
  build(1, 1, qcnt);
  Insert(1, 1, qcnt, lower_bound(q + 1, q + 1 + qcnt, l[n]) - q, n);
  for (int i = n - 1; i >= 1; i--) {
    int L = lower_bound(q + 1, q + 1 + qcnt, (l[i] + g) % rg) - q;
    int R = lower_bound(q + 1, q + 1 + qcnt, l[i]) - q;
    int MinPos;
    if (R == 1)
      R = qcnt;
    else
      R = R - 1;
    if (L <= R)
      MinPos = Query(1, 1, qcnt, L, R);
    else {
      MinPos = Query(1, 1, qcnt, L, qcnt);
      MinPos = min(MinPos, Query(1, 1, qcnt, 1, R));
    }
    if (MinPos == n + 1)
      dp[i] = dis[n] - dis[i];
    else
      dp[i] =
          dp[MinPos] + rg - (l[MinPos] - l[i] + rg) % rg + dis[MinPos] - dis[i];
    Insert(1, 1, qcnt, lower_bound(q + 1, q + 1 + qcnt, l[i]) - q, i);
  }
  int qc, t;
  scanf("%d", &qc);
  while (qc--) {
    scanf("%d", &t);
    t += offset;
    int tm_off = t % rg;
    int L = (g - tm_off + rg) % rg;
    int R = (rg - tm_off + rg) % rg;
    long long res = t;
    int bPos = n + 1;
    if (L <= R) {
      L = lower_bound(q + 1, q + 1 + qcnt, L) - q;
      R = lower_bound(q + 1, q + 1 + qcnt, R) - q - 1;
      if (L <= R) bPos = Query(1, 1, qcnt, L, R);
    } else {
      L = lower_bound(q + 1, q + 1 + qcnt, L) - q;
      R = lower_bound(q + 1, q + 1 + qcnt, R) - q - 1;
      if (L <= qcnt) bPos = min(bPos, Query(1, 1, qcnt, L, qcnt));
      if (R) bPos = min(bPos, Query(1, 1, qcnt, 1, R));
    }
    if (bPos <= n)
      res = dp[bPos] + dis[bPos] + rg - (l[bPos] + t) % rg;
    else
      res = dis[n];
    res += tmp + t;
    printf("%I64d\n", res);
  }
  return 0;
}
