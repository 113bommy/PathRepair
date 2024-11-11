#include <bits/stdc++.h>
using namespace std;
const int OO = 2e9;
const int MOD = 1e9 + 7;
const double Pi = 3.141592653589793;
const int N = 1e5 + 5;
const double Eps = 1e-7;
pair<int, int> mr[N];
int l[N], r[N], v[N], n, q = 0;
double IT[4 * N], res = 0;
void setup(int x, int l, int r) {
  IT[x] = 1.0;
  if (l == r) return;
  int m = (l + r) / 2;
  setup(x * 2, l, m);
  setup(x * 2 + 1, m + 1, r);
}
void update(int x, int l, int r, int L, int R, double V) {
  if (r < L || R < l) return;
  if (L <= l && r <= R) {
    IT[x] *= V;
    return;
  }
  int m = (l + r) / 2;
  if (L <= m) update(x * 2, l, m, L, R, V);
  if (m < R) update(x * 2 + 1, m + 1, r, L, R, V);
}
double get(int x, int l, int r, int p) {
  if (l == r) return IT[x];
  int m = (l + r) / 2;
  if (p <= m)
    return IT[x] * get(x * 2, l, m, p);
  else
    return IT[x] * get(x * 2 + 1, m + 1, r, p);
}
int fl(int x) {
  int l = 1, r = n, m, res = n + 1;
  while (l <= r) {
    m = (l + r) / 2;
    if (x <= mr[m].first) {
      res = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return res;
}
int fr(int x) {
  int l = 1, r = n, m, res = 0;
  while (l <= r) {
    m = (l + r) / 2;
    if (mr[m].first <= x) {
      res = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  return res;
}
int main() {
  int m, x, h, lc, rc;
  scanf("%i%i", &m, &n);
  for (int i = (int)1; i <= (int)m; i++) {
    scanf("%i%i%i%i", &x, &h, &lc, &rc);
    q++;
    l[q] = x - h;
    r[q] = x - 1;
    v[q] = 100 - lc;
    q++;
    l[q] = x + 1;
    r[q] = x + h;
    v[q] = 100 - rc;
  }
  for (int i = (int)1; i <= (int)n; i++)
    scanf("%i%i", &mr[i].first, &mr[i].second);
  sort(mr + 1, mr + n + 1);
  mr[0].first = -1.0 * OO;
  mr[n + 1].first = 1.0 * OO;
  setup(1, 1, n);
  for (int i = (int)1; i <= (int)q; i++) {
    lc = fl(l[i]);
    rc = fr(r[i]);
    if (lc > rc) continue;
    update(1, 1, n, lc, rc, 1.0 * v[i] / 100);
  }
  double chance;
  for (int i = (int)1; i <= (int)n; i++) {
    chance = get(1, 1, n, i);
    res += chance * mr[i].second;
  }
  printf("%.5lf", res);
}
