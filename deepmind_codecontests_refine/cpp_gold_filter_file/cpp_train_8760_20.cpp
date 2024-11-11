#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const long long INF = 0x3f3f3f3f3f3f3f3f;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
template <typename T>
inline void cmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m;
long long p;
int tot, root, lc[MAXN << 1], rc[MAXN << 1];
long long sum[MAXN << 1];
vector<long long> seg[MAXN << 1];
void Merge(vector<long long> &rt, vector<long long> &ls, vector<long long> &rs,
           long long lsum) {
  int lsz = ls.size(), rsz = rs.size();
  rt.resize(lsz + rsz - 1, INF);
  for (int i = 0, j = 0; i < lsz; ++i) {
    long long xl = ls[i], xr = (i == lsz - 1 ? INF : ls[i + 1]);
    long long yl = xl + lsum - p * i, yr = xr + lsum - p * i;
    while (j > 0 && rs[j] > yl) --j;
    while (j < rsz && rs[j] <= yl) ++j;
    if (j) --j;
    for (; j < rsz && rs[j] <= yr; ++j) {
      cmin(rt[i + j], max(xl, rs[j] - lsum + p * i));
    }
  }
  rt[0] = -INF;
}
void Build(int &rt, int b, int e) {
  rt = ++tot;
  if (b == e) {
    read(sum[rt]);
    seg[rt].push_back(-INF);
    seg[rt].push_back(p - sum[rt]);
    return;
  }
  int mid = (b + e) >> 1;
  Build(lc[rt], b, mid);
  Build(rc[rt], mid + 1, e);
  sum[rt] = sum[lc[rt]] + sum[rc[rt]];
  Merge(seg[rt], seg[lc[rt]], seg[rc[rt]], sum[lc[rt]]);
}
inline long long Calc(int rt, long long pre) {
  int i =
      upper_bound(seg[rt].begin(), seg[rt].end(), pre) - seg[rt].begin() - 1;
  return pre + sum[rt] - p * i;
}
long long Query(int rt, int b, int e, int l, int r, long long pre) {
  if (l <= b && e <= r) {
    return Calc(rt, pre);
  }
  int mid = (b + e) >> 1;
  if (l <= mid) pre = Query(lc[rt], b, mid, l, r, pre);
  if (r > mid) pre = Query(rc[rt], mid + 1, e, l, r, pre);
  return pre;
}
void solve() {
  read(n);
  read(m);
  read(p);
  Build(root, 1, n);
  while (m--) {
    int l, r;
    read(l);
    read(r);
    printf("%lld\n", Query(root, 1, n, l, r, 0));
  }
}
int main() {
  solve();
  return 0;
}
