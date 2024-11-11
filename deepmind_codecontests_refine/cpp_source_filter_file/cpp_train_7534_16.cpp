#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int n, m, a[maxn], b[maxn];
pair<int, int> t[5 * maxn];
void upd(int v, int tl, int tr, int l, int r, pair<int, int> p) {
  int tm = (tl + tr) / 2;
  if (tl == l && tr == r) {
    t[v] = p;
    return;
  }
  if (t[v].first) {
    t[2 * v] = t[2 * v + 1] = t[v];
    t[v] = {0, 0};
  }
  if (r <= tm)
    upd(2 * v, tl, tm, l, r, p);
  else if (l > tm)
    upd(2 * v + 1, tm + 1, tr, l, r, p);
  else {
    upd(2 * v, tl, tm, l, tm, p);
    upd(2 * v + 1, tm + 1, tr, tm + 1, r, p);
  }
}
pair<int, int> get(int v, int tl, int tr, int in) {
  if (t[v].first || tl == tr) {
    return t[v];
  }
  int tm = (tl + tr) >> 1;
  if (in <= tm) return get(2 * v, tl, tm, in);
  return get(2 * v + 1, tm + 1, tr, in);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  int t, x, y, k;
  pair<int, int> p;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d%d", &x, &y, &k);
      p.first = x;
      p.second = y;
      upd(1, 1, n, y, y + k - 1, p);
    } else {
      scanf("%d", &x);
      p = get(1, 1, n, x);
      int z = p.first;
      int l = p.second;
      if (z)
        printf("%d", a[x - l + z]);
      else
        printf("%d", b[x]);
    }
  }
}
