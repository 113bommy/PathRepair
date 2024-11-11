#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 200500;
int tr[MAXN << 2], a[MAXN], ans[MAXN], k[MAXN], pos[MAXN], g[MAXN], h[MAXN];
bool cmp(const int &o, const int &p) {
  if (o == p) return o < p;
  return a[o] > a[p];
}
bool cmp2(const int &o, const int &p) { return k[o] < k[p]; }
void insert(int o, int L, int R, int v) {
  tr[o]++;
  if (L + 1 == R) return;
  if (v < ((L + R) >> 1))
    insert((o << 1), L, ((L + R) >> 1), v);
  else
    insert((o << 1 | 1), ((L + R) >> 1), R, v);
}
int Q(int o, int L, int R, int v) {
  if (L + 1 == R) {
    return L;
  }
  if (tr[(o << 1)] >= v) {
    return Q((o << 1), L, ((L + R) >> 1), v);
  }
  return Q((o << 1 | 1), ((L + R) >> 1), R, v - tr[(o << 1)]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    h[i] = i;
  }
  sort(h, h + n, cmp);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &k[i], &pos[i]);
    g[i] = i;
  }
  sort(g, g + m, cmp2);
  int j = 0;
  for (int i = 0; i < n; ++i) {
    insert(1, 0, n, h[i]);
    while (j < m && k[g[j]] == i + 1) {
      ans[g[j]] = a[Q(1, 0, n, pos[g[j]])];
      j++;
    }
  }
  for (int i = 0; i < m; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
