#include <bits/stdc++.h>
using namespace std;
namespace Solve1 {
const int maxn = 400005;
const int INF = 1000000005;
inline int mymax(const int &a, const int &b) { return a > b ? a : b; }
inline int mymin(const int &a, const int &b) { return a < b ? a : b; }
struct Query {
  int tm, val, ans1, ans2;
  Query(int a = 0, int b = 0, int c = 0, int d = 0)
      : tm(a), val(b), ans1(c), ans2(d) {}
} B[maxn];
int n, m, A[maxn], C[maxn << 1], nC;
int np, head[maxn], next[maxn], last[maxn];
void Add(int tm, int pos, int val) {
  B[++np] = Query(tm, val, 1, 1);
  if (!head[pos])
    head[pos] = np;
  else
    next[last[pos]] = np;
  last[pos] = np;
  return;
}
void Indata() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    C[i] = A[i];
  }
  memset(head, 0, sizeof(head));
  memset(next, 0, sizeof(next));
  memset(last, 0, sizeof(last));
  int pos, val;
  np = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &pos, &val);
    Add(i, pos, val);
    C[i + n] = val;
  }
  sort(C + 1, C + n + m + 1);
  nC = 1;
  for (int i = 2; i <= n + m; i++)
    if (C[i] != C[i - 1]) C[++nC] = C[i];
  for (int i = 1; i <= n; i++) {
    A[i] = lower_bound(C + 1, C + nC + 1, A[i]) - C;
    for (int p = head[i]; p; p = next[p])
      B[p].val = lower_bound(C + 1, C + nC + 1, B[p].val) - C;
  }
  return;
}
struct SegmentTree {
  int maxv[maxn << 2], lc[maxn << 2], rc[maxn << 2], rt, np;
  void Initial() {
    rt = np = 0;
    memset(lc, 0, sizeof(lc));
    memset(rc, 0, sizeof(rc));
    return;
  }
  void pushup(int now) {
    maxv[now] = mymax(maxv[lc[now]], maxv[rc[now]]);
    return;
  }
  void Build(int &now, int L, int R) {
    now = ++np;
    if (L == R) {
      maxv[now] = -INF;
      return;
    }
    int m = (L + R) >> 1;
    Build(lc[now], L, m);
    Build(rc[now], m + 1, R);
    pushup(now);
    return;
  }
  void Update(int now, int L, int R, int i, int d) {
    if (L == R && L == i) {
      maxv[now] = mymax(d, maxv[now]);
      return;
    }
    int m = (L + R) >> 1;
    if (i <= m)
      Update(lc[now], L, m, i, d);
    else
      Update(rc[now], m + 1, R, i, d);
    pushup(now);
    return;
  }
  int Qmax(int now, int L, int R, int i, int j) {
    if (i <= L && R <= j) return maxv[now];
    int m = (L + R) >> 1;
    if (j <= m)
      return Qmax(lc[now], L, m, i, j);
    else if (i > m)
      return Qmax(rc[now], m + 1, R, i, j);
    return mymax(Qmax(lc[now], L, m, i, j), Qmax(rc[now], m + 1, R, i, j));
  }
} ST;
int Fans[maxn], F[maxn], G[maxn], FF[maxn];
int rr[maxn];
void work() {
  Indata();
  ST.Initial();
  ST.Build(ST.rt, 1, nC);
  F[0] = G[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    int base;
    if (A[i] == 1)
      base = 1;
    else
      base = mymax(1, ST.Qmax(ST.rt, 1, nC, 1, A[i] - 1) + 1);
    for (int p = head[i]; p; p = next[p]) {
      if (B[p].val == 1)
        B[p].ans1 = 1;
      else
        B[p].ans1 = mymax(1, ST.Qmax(ST.rt, 1, nC, 1, B[p].val - 1) + 1);
    }
    ST.Update(ST.rt, 1, nC, A[i], base);
    F[i] = ST.Qmax(ST.rt, 1, nC, A[i], A[i]);
  }
  ST.Initial();
  ST.Build(ST.rt, 1, nC);
  for (int i = n; i >= 1; i--) {
    int base;
    if (A[i] == nC)
      base = 1;
    else
      base = mymax(1, ST.Qmax(ST.rt, 1, nC, A[i] + 1, nC) + 1);
    for (int p = head[i]; p; p = next[p]) {
      if (B[p].val == nC)
        B[p].ans2 = 1;
      else
        B[p].ans2 = mymax(1, ST.Qmax(ST.rt, 1, nC, B[p].val + 1, nC) + 1);
    }
    ST.Update(ST.rt, 1, nC, A[i], base);
    G[i] = ST.Qmax(ST.rt, 1, nC, A[i], A[i]);
  }
  for (int i = 1; i <= n; i++)
    for (int p = head[i]; p; p = next[p])
      Fans[B[p].tm] = B[p].ans1 + B[p].ans2 - 1;
  int TrueAns = F[1];
  for (int i = 2; i <= n; i++) TrueAns = mymax(TrueAns, F[i]);
  for (int i = 1; i <= n; i++) FF[i] = F[i] + G[i] - 1;
  memset(rr, 0, sizeof(rr));
  for (int i = n; i >= 1; i--) {
    rr[i] = rr[i + 1];
    if (FF[i] == TrueAns) {
      if (!rr[i])
        rr[i] = A[i];
      else
        rr[i] = mymin(rr[i], A[i]);
    }
  }
  int fr = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = -INF;
    if (FF[i] != TrueAns)
      tmp = TrueAns;
    else {
      if (fr >= A[i] || (rr[i + 1] && rr[i + 1] <= A[i]))
        tmp = TrueAns;
      else
        tmp = TrueAns - 1;
      fr = mymax(fr, A[i]);
    }
    for (int p = head[i]; p; p = next[p])
      Fans[B[p].tm] = mymax(Fans[B[p].tm], tmp);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", Fans[i]);
  return;
}
}  // namespace Solve1
int main() {
  Solve1::work();
  return 0;
}
