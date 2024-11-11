#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m, k;
int getmask(int a, int b) {
  int cnt[31];
  cnt[k + 1] = 0;
  for (int i = k; i >= 0; i--) cnt[i] = (((b - 1) >> i) - ((a - 1) >> i)) & 1;
  int ret = 0;
  for (int i = 0; i <= k; i++) ret |= (cnt[i] ^ cnt[i + 1]) << i;
  return ret;
}
int px[N];
struct Segment_Tree {
  const static int NODE = N << 2;
  int Min[NODE], addv[NODE], w[NODE];
  void init(int o, int L, int R) {
    if (L == R)
      w[o] = getmask(px[L], px[L + 1]);
    else {
      init((o << 1), L, ((L + R) >> 1)),
          init((o << 1 | 1), ((L + R) >> 1) + 1, R);
      w[o] = w[(o << 1)] ^ w[(o << 1 | 1)];
    }
  }
  void add(int o, int L, int R, int l, int r, int x) {
    if (l <= L && R <= r)
      addv[o] += x, Min[o] += x;
    else {
      if (l <= ((L + R) >> 1)) add((o << 1), L, ((L + R) >> 1), l, r, x);
      if (r > ((L + R) >> 1)) add((o << 1 | 1), ((L + R) >> 1) + 1, R, l, r, x);
      Min[o] = min(Min[(o << 1)], Min[(o << 1 | 1)]), w[o] = 0;
      if (Min[(o << 1)] == Min[o]) w[o] ^= w[(o << 1)];
      if (Min[(o << 1 | 1)] == Min[o]) w[o] ^= w[(o << 1 | 1)];
      Min[o] += addv[o];
    }
  }
} T;
struct Event {
  int l, r, x, w;
  bool operator<(const Event& B) const { return x < B.x; }
} A[N];
int tot;
bool work() {
  int a = getmask(px[1], px[n]), ans = 0;
  T.init(1, 1, n - 1);
  for (int i = 1; i <= tot - 1; i++) {
    T.add(1, 1, n - 1, A[i].l, A[i].r - 1, A[i].w);
    int ret = a;
    if (T.Min[1] == 0) ret ^= T.w[1];
    if (A[i + 1].x > A[i].x) {
      int b = getmask(A[i].x, A[i + 1].x);
      int ca = 0, cb = 0, val = 0;
      bool flag = false;
      for (int j = k; j >= 0; j--) {
        if (ret & (1 << j)) ++ca;
        if (b & (1 << j)) ++cb;
        if (((ca & 1) && (cb & 1)) ^ flag) val ^= 1 << j;
        flag = (ca & 1) && (cb & 1);
      }
      ans ^= val;
    }
  }
  return ans;
}
void init() {
  int lim;
  scanf("%*d%d%d", &m, &lim);
  while ((1 << (k + 1)) <= lim) ++k;
  static int a[N], b[N], c[N], d[N];
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    px[++n] = a[i], px[++n] = c[i] + 1;
  }
  sort(px + 1, px + n + 1);
  n = unique(px + 1, px + n + 1) - px - 1;
  for (int i = 1; i <= m; i++) {
    a[i] = lower_bound(px + 1, px + n + 1, a[i]) - px;
    c[i] = lower_bound(px + 1, px + n + 1, c[i] + 1) - px;
    A[++tot] = (Event){a[i], c[i], b[i], 1};
    A[++tot] = (Event){a[i], c[i], d[i] + 1, -1};
  }
  sort(A + 1, A + tot + 1);
}
int main() {
  init();
  puts(work() ? "Hamed" : "Malek");
  return 0;
}
