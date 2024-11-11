#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, INF = 233333333;
int n, l, s, num[MAXN], L[MAXN], dp[MAXN];
int mn[MAXN << 2];
void upd(int i) { mn[i] = min(mn[i << 1], mn[i << 1 | 1]); }
void build(int i, int l, int r) {
  mn[i] = INF;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
}
void modify(int i, int l, int r, int pos, int val) {
  if (l == r) {
    mn[i] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    modify(i << 1, l, mid, pos, val);
  else
    modify(i << 1 | 1, mid + 1, r, pos, val);
  upd(i);
}
int query(int i, int l, int r, int x, int y) {
  if (x <= l && r <= y) return mn[i];
  if (x > r || y < l) return INF;
  int mid = (l + r) >> 1, ret = INF;
  if (x <= mid) ret = min(ret, query(i << 1, l, mid, x, y));
  if (y > mid) ret = min(ret, query(i << 1 | 1, mid + 1, r, x, y));
  upd(i);
  return ret;
}
int s1, t1, q1[MAXN];
int s2, t2, q2[MAXN];
void Pre() {
  int A = 1, B = 1;
  q1[t1++] = q2[t2++] = L[1] = 1;
  while (B < n) {
    ++B;
    while (s1 < t1 && num[q1[t1 - 1]] > num[B]) --t1;
    q1[t1++] = B;
    while (s2 < t2 && num[q2[t2 - 1]] < num[B]) --t2;
    q2[t2++] = B;
    while (num[q2[s2]] - num[q1[s1]] > s) {
      if (q2[s2] == A) ++s2;
      if (q1[s1] == A) ++s1;
      ++A;
    }
    L[B] = A;
  }
}
int main() {
  scanf("%d%d%d", &n, &s, &l);
  for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
  build(1, 1, n);
  Pre();
  memset(dp, -1, sizeof dp);
  for (int i = l; i < l << 1; ++i)
    if (L[i] == 1) dp[i] = 1, modify(1, 1, n, i, dp[i]);
  for (int i = l << 1, tmp; i <= n; ++i) {
    if (L[i] == 1)
      dp[i] = 1, modify(1, 1, n, i, dp[i]);
    else if (L[i] - 1 <= i - l) {
      tmp = query(1, 1, n, L[i] - 1, i - l);
      if (tmp == INF) continue;
      modify(1, 1, n, i, dp[i] = tmp + 1);
    }
  }
  printf("%d\n", dp[n]);
}
