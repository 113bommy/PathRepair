#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 15, M = 2e5 + 5, MAXI = 1e9 + 5;
map<int, int> L, R;
map<int, int>::iterator it;
int c[M], pos[N], Hash[N], a[M], b[M];
struct Range {
  int u, v, ind;
  bool operator<(const Range& rhs) const {
    if (rhs.v != v) return v < rhs.v;
    return u < rhs.u;
  }
} ran[M], my[M];
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
    ++l, ++r;
    pos[p++] = l;
    pos[p++] = r;
    L[l] = max(L[l], r);
    R[r] = max(R[r], MAXI - l);
    ran[i].u = l, ran[i].v = r;
    ran[i].ind = i;
  }
  for (i = 0; i < m; ++i) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    ++a[i], ++b[i];
    pos[p++] = a[i], pos[p++] = b[i];
    my[i].u = a[i], my[i].v = b[i], my[i].ind = i;
  }
  assert(p < N);
  sort(pos + 1, pos + p);
  p = unique(pos + 1, pos + p) - pos - 1;
  sort(ran, ran + n);
  sort(my, my + m);
  for (x = -1, i = 0, j = 0; i < m; ++i) {
    while (j < n) {
      if (ran[j].v > my[i].v) break;
      if (ran[j].v > x) {
        ind = lower_bound(pos + 1, pos + p + 1, ran[j].u) - pos;
        update(N - ind, ran[j].v - ran[j].u);
        x = ran[j].v;
      }
      ++j;
    }
    ind = lower_bound(pos + 1, pos + p + 1, my[i].u) - pos;
    w = q(N - ind);
    ind = my[i].ind;
    e = c[ind];
    if (w * e > ret) ret = w * e, R2 = ind;
  }
  memset(Hash, 0, sizeof(Hash));
  for (it = L.begin(); it != L.end(); ++it) {
    ind = lower_bound(pos + 1, pos + p + 1, it->first) - pos;
    update(ind, it->second);
  }
  for (i = 0; i < m; ++i) {
    ind = lower_bound(pos + 1, pos + p + 1, a[i]) - pos;
    w = min(q(ind), b[i]);
    w -= a[i];
    if (w * c[i] > ret) {
      ret = w * c[i];
      R2 = i;
    }
  }
  memset(Hash, 0, sizeof(Hash));
  for (it = R.begin(); it != R.end(); ++it) {
    ind = lower_bound(pos + 1, pos + p + 1, it->first) - pos;
    update(N - ind, it->second);
  }
  for (i = 0; i < m; ++i) {
    ind = lower_bound(pos + 1, pos + p + 1, b[i]) - pos;
    w = MAXI - q(N - ind);
    w = max(w, 1LL * a[i]);
    w = b[i] - w;
    if (w * c[i] > ret) {
      ret = w * c[i];
      R2 = i;
    }
  }
  cout << ret << endl;
  if (ret > 0) {
    ind = R2;
    for (i = 0; i < n; ++i) {
      x = max(ran[i].u, a[ind]), y = min(ran[i].v, b[ind]), w = y - x;
      if (w * c[ind] == ret) R1 = ran[i].ind + 1;
    }
    cout << R1 << " " << ind + 1 << endl;
  }
}
