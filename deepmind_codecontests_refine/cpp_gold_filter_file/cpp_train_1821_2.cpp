#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 15, M = 2e5 + 5, MAXI = 1e9 + 5;
map<int, int> L, R;
map<int, int>::iterator it;
int c[M], pos[N], Hash[N];
struct Range {
  int l, r, ind;
  bool operator<(const Range& rhs) const {
    if (rhs.r != r) return r < rhs.r;
    return l < rhs.l;
  }
} seg[M], my[M];
void update(long long y, int n) {
  while (y < N) Hash[y] = max(Hash[y], n), y += y & (-y);
}
int q(long long y) {
  int ret = 0;
  while (y) ret = max(ret, Hash[y]), y = y & (y - 1);
  return ret;
}
int main() {
  int l, r, n, m, i, j, p = 1, R1, R2, ind;
  long long ret = 0, x, y, w, e;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &l, &r);
    pos[p++] = l;
    pos[p++] = r;
    L[l] = max(L[l], r);
    R[r] = max(R[r], MAXI - l);
    seg[i].l = l, seg[i].r = r, seg[i].ind = i;
  }
  for (i = 0; i < m; ++i) {
    scanf("%d%d%d", &l, &r, &c[i]);
    pos[p++] = l, pos[p++] = r;
    my[i].l = l, my[i].r = r, my[i].ind = i;
  }
  sort(pos + 1, pos + p);
  p = unique(pos + 1, pos + p) - pos;
  sort(seg, seg + n);
  sort(my, my + m);
  for (x = -1, i = 0, j = 0; i < m; ++i) {
    while (j < n) {
      if (seg[j].r > my[i].r) break;
      if (x < seg[j].r) {
        ind = lower_bound(pos + 1, pos + p, seg[j].l) - pos;
        update(N - ind, seg[j].r - seg[j].l);
        x = seg[j].r;
      }
      ++j;
    }
    ind = lower_bound(pos + 1, pos + p, my[i].l) - pos;
    w = q(N - ind);
    ind = my[i].ind;
    e = c[ind];
    if (w * e > ret) ret = w * e, R2 = i;
  }
  memset(Hash, 0, sizeof(Hash));
  for (it = L.begin(); it != L.end(); ++it)
    ind = lower_bound(pos + 1, pos + p, it->first) - pos,
    update(ind, it->second);
  for (i = 0; i < m; ++i) {
    ind = lower_bound(pos + 1, pos + p, my[i].l) - pos;
    w = min(q(ind), my[i].r);
    w -= my[i].l;
    ind = my[i].ind;
    e = c[ind];
    if (w * e > ret) ret = w * e, R2 = i;
  }
  memset(Hash, 0, sizeof(Hash));
  for (it = R.begin(); it != R.end(); ++it)
    ind = lower_bound(pos + 1, pos + p, it->first) - pos,
    update(N - ind, it->second);
  for (i = 0; i < m; ++i) {
    ind = lower_bound(pos + 1, pos + p, my[i].r) - pos;
    w = max(1LL * MAXI - q(N - ind), 1LL * my[i].l);
    w = my[i].r - w;
    ind = my[i].ind;
    e = c[ind];
    if (w * e > ret) ret = w * e, R2 = i;
  }
  cout << ret << endl;
  if (ret > 0) {
    ind = my[R2].ind;
    for (i = 0; i < n; ++i) {
      x = max(seg[i].l, my[R2].l), y = min(seg[i].r, my[R2].r), w = y - x;
      if (w * c[ind] == ret) R1 = seg[i].ind + 1;
    }
    cout << R1 << " " << ind + 1 << endl;
  }
}
