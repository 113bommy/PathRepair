#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 40 * N;
int n, m, x, y, rt[N], size, a[N], su[M], c[M][2], la[N];
inline void add(int pos, int val, int &v, int v2, int l = 1, int r = n) {
  su[v = ++size] = su[v2];
  su[v] += val;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (pos <= mid)
    add(pos, val, c[v][0], c[v2][0], l, mid), c[v][1] = c[v2][1];
  else
    add(pos, val, c[v][1], c[v2][1], mid + 1, r), c[v][0] = c[v2][0];
}
inline int ask(int y, int v, int l = 1, int r = n) {
  if (l == r) return l;
  int mid = (l + r) >> 1, t = su[c[v][0]];
  return y <= t ? ask(y, c[v][0], l, mid) : ask(y - t, c[v][1], mid + 1, r);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = n; i; --i) {
    add(i, 1, rt[i], rt[i + 1]);
    if (la[a[i]]) add(la[a[i]], -1, rt[i], rt[i]);
    la[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    int tot = 1;
    for (int pos = 1; su[rt[pos]] > i; pos = ask(i + 1, rt[pos]), ++tot)
      ;
    printf("%d ", tot);
  }
  return 0;
}
