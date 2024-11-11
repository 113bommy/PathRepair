#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXK = 10;
const int INF = 0x3f3f3f3f;
static int N, K, Q;
static vector<int> mn[MAXN << 2], mx[MAXN << 2];
inline void update(vector<int> &r, vector<int> &x, vector<int> &y, int is_min) {
  r.clear();
  for (int i = 0; i < (1 << K); i++)
    r.push_back(is_min ? min(x[i], y[i]) : max(x[i], y[i]));
}
inline void read(vector<int> &mn, vector<int> &mx) {
  mn.clear();
  mx.clear();
  static int tmp[MAXK];
  for (int i = 0; i < K; i++) scanf("%d", &tmp[i]);
  for (int s = 0; s < (1 << K); s++) {
    int sum = 0;
    for (int i = 0; i < K; i++) sum += ((s & (1 << i)) ? -1 : 1) * tmp[i];
    mn.push_back(sum);
    mx.push_back(sum);
  }
}
void build(int n, int l, int r) {
  if (l == r) {
    read(mn[n], mx[n]);
    return;
  }
  build((n << 1), l, ((l + r) >> 1));
  build(((n << 1) | 1), (((l + r) >> 1) + 1), r);
  update(mn[n], mn[(n << 1)], mn[((n << 1) | 1)], 1);
  update(mx[n], mx[(n << 1)], mx[((n << 1) | 1)], 0);
}
void modify(int n, int l, int r, int p) {
  if (l == r) {
    read(mn[n], mx[n]);
    return;
  }
  if (p <= ((l + r) >> 1))
    modify((n << 1), l, ((l + r) >> 1), p);
  else
    modify(((n << 1) | 1), (((l + r) >> 1) + 1), r, p);
  update(mn[n], mn[(n << 1)], mn[((n << 1) | 1)], 1);
  update(mx[n], mx[(n << 1)], mx[((n << 1) | 1)], 0);
}
void query(int n, int l, int r, int fl, int fr, vector<int> &rmin,
           vector<int> &rmax) {
  if (fl <= l && r <= fr) {
    update(rmin, rmin, mn[n], 1);
    update(rmax, rmax, mx[n], 0);
    return;
  }
  if (fl <= ((l + r) >> 1))
    query((n << 1), l, ((l + r) >> 1), fl, fr, rmin, rmax);
  if (fr >= (((l + r) >> 1) + 1))
    query(((n << 1) | 1), (((l + r) >> 1) + 1), r, fl, fr, rmin, rmax);
}
int main() {
  scanf("%d%d", &N, &K);
  build(1, 1, N);
  scanf("%d", &Q);
  while (Q--) {
    int op, l, r;
    scanf("%d%d", &op, &l);
    if (op == 1)
      modify(1, 1, N, l);
    else {
      scanf("%d", &r);
      vector<int> rmin = vector<int>(1 << K, INF);
      vector<int> rmax = vector<int>(1 << K, -INF);
      query(1, 1, N, l, r, rmin, rmax);
      int ans = 0;
      for (int i = 0; i < (1 << K); i++) ans = max(ans, rmax[i] - rmin[i]);
      printf("%d\n", ans);
    }
  }
  return 0;
}
