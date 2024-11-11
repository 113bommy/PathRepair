#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, p[2][N], sgt[2][N], ord[N], sgtAns[N], ans[N];
void build(int sgt[], int tl = 0, int tr = n - 1, int u = 1) {
  if (tl == tr) {
    sgt[u] = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  build(sgt, tl, tm, 2 * u);
  build(sgt, tm + 1, tr, 2 * u + 1);
  sgt[u] = sgt[2 * u] + sgt[2 * u + 1];
}
void update(int sgt[], int pos, int value, int tl = 0, int tr = n - 1,
            int u = 1) {
  if (tl == tr) {
    sgt[u] = value;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    update(sgt, pos, value, tl, tm, 2 * u);
  else
    update(sgt, pos, value, tm + 1, tr, 2 * u + 1);
  sgt[u] = sgt[2 * u] + sgt[2 * u + 1];
}
int sum(int sgt[], int l, int r, int tl = 0, int tr = n - 1, int u = 1) {
  if (l > r) return 0;
  if (tl == l && tr == r) return sgt[u];
  int tm = (tl + tr) / 2;
  return sum(sgt, l, min(tm, r), tl, tm, 2 * u) +
         sum(sgt, max(tm + 1, l), r, tm + 1, tr, 2 * u + 1);
}
int pos(int sgt[], int prefixSum, int tl = 0, int tr = n - 1, int u = 1) {
  if (tl == tr) {
    return tr;
  }
  int tm = (tl + tr) / 2;
  if (prefixSum <= sgt[2 * u])
    return pos(sgt, prefixSum, tl, tm, 2 * u);
  else
    return pos(sgt, prefixSum - sgt[2 * u], tm + 1, tr, 2 * u + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) cin >> p[i][j];
    build(sgt[i]);
  }
  for (int i = 0; i < n; ++i) {
    ord[i] = 0;
    for (int j = 0; j < 2; ++j) {
      ord[i] += sum(sgt[j], 0, p[j][i] - 1);
      update(sgt[j], p[j][i], 0);
    }
  }
  int d = 0;
  for (int i = n - 2; i >= 0; --i) {
    d += ord[i];
    ord[i] = d % (n - i);
    d /= (n - i);
  }
  build(sgtAns);
  for (int i = 0; i < n; ++i) {
    ans[i] = pos(sgtAns, ord[i] + 1);
    update(sgtAns, ans[i], 0);
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  return 0;
}
