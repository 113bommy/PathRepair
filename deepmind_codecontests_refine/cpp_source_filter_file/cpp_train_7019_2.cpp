#include <bits/stdc++.h>
using namespace std;
const int N = 19, maxn = 1e5;
int n;
int a[maxn];
struct SegmentTree {
  long long sum[N][1 << N];
  int lOnes[N][1 << N];
  int rOnes[N][1 << N];
  bool allOnes[N][1 << N];
  void init() { build(1, 0, n - 1); }
  void build(int o, int l, int r) {
    if (l == r) {
      initNode(o, l, r, l);
      return;
    }
    int lc = o << 1, rc = o << 1 | 1, m = (l + r) >> 1;
    build(lc, l, m);
    build(rc, m + 1, r);
    up(o, l, r);
  }
  int p;
  void update(int p) {
    this->p = p;
    update(1, 0, n - 1);
  }
  void update(int o, int l, int r) {
    if (l == r) {
      initNode(o, l, r, l);
      return;
    }
    int lc = o << 1, rc = o << 1 | 1, m = (l + r) >> 1;
    if (p <= m)
      update(lc, l, m);
    else
      update(rc, m + 1, r);
    up(o, l, r);
  }
  long long query() {
    long long ret = 0;
    for (int i = 0, j = 1; i < N; i++, j <<= 1) {
      long long temp = sum[i][1];
      if (allOnes[i][1])
        temp += Sum(n);
      else
        temp += Sum(lOnes[i][1]) + Sum(rOnes[i][1]);
      ret += temp * j;
    }
    return ret;
  }
  long long Sum(long long x) { return x * (x + 1) / 2; }
  void initNode(int o, int l, int r, int pos) {
    for (int i = 0, j = 1; i < N; i++, j <<= 1) {
      sum[i][o] = 0;
      lOnes[i][o] = rOnes[i][o] = allOnes[i][o] = a[pos] & j ? 1 : 0;
    }
  }
  void up(int o, int l, int r) {
    int lc = o << 1, rc = o << 1 | 1, m = (l + r) >> 1;
    for (int i = 0; i < N; i++) {
      sum[i][o] = sum[i][lc] + sum[i][rc];
      allOnes[i][o] = 0;
      if (allOnes[i][lc] && allOnes[i][rc]) {
        lOnes[i][o] = rOnes[i][o] = r - l + 1;
        allOnes[i][o] = 1;
      } else if (allOnes[i][lc]) {
        lOnes[i][o] = lOnes[i][lc] + rOnes[i][rc];
        rOnes[i][o] = rOnes[i][rc];
      } else if (allOnes[i][rc]) {
        lOnes[i][o] = lOnes[i][lc];
        rOnes[i][o] = rOnes[i][lc] + rOnes[i][rc];
      } else {
        lOnes[i][o] = lOnes[i][lc];
        rOnes[i][o] = rOnes[i][rc];
        sum[i][o] += Sum(rOnes[i][lc] + lOnes[i][rc]);
      }
    }
  }
};
SegmentTree ST;
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  ST.init();
  for (int i = 0; i < m; i++) {
    int p, v;
    scanf("%d%d", &p, &v);
    p--;
    a[p] = v;
    ST.update(p);
    printf("%I64d\n", ST.query());
  }
}
