#include <bits/stdc++.h>
using namespace std;
int rd() {
  int k = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') k = k * 10 + c - '0', c = getchar();
  return k;
}
const int N = 200001, M = 4000001;
int n, l[N], r[N], x[N << 1], m, v[M];
bool lf[M], rf[M];
void Update(int x, int l, int r, int L, int R) {
  if (lf[x] && rf[x] && v[x] == 1) return;
  if (L <= l && r <= R) {
    v[x] = lf[x] = rf[x] = 1;
    return;
  }
  int p = (l + r) >> 1;
  if (L <= p) Update((x << 1), l, p, L, R);
  if (p < R) Update((x << 1 | 1), p + 1, r, L, R);
  lf[x] = lf[(x << 1)], rf[x] = rf[(x << 1 | 1)],
  v[x] = v[(x << 1)] + v[(x << 1 | 1)] - (rf[(x << 1)] && lf[(x << 1 | 1)]);
}
int main() {
  n = rd();
  for (int i = 1; i <= n; ++i)
    x[++m] = l[i] = rd(), x[++m] = r[i] = rd(), x[++m] = (--r[i]);
  sort(x + 1, x + m + 1), m = unique(x + 1, x + m + 1) - x - 1;
  for (int i = 1; i <= n; ++i) {
    l[i] = lower_bound(x + 1, x + m + 1, l[i]) - x,
    r[i] = lower_bound(x + 1, x + m + 1, r[i]) - x;
    Update(1, 1, m, l[i], r[i]), printf("%d ", v[1]);
  }
  return 0;
}
