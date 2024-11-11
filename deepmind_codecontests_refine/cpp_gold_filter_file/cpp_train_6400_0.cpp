#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10, inf = 0x3f3f3f3f;
template <class T>
inline bool scan(T &ret) {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  ret = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - '0';
}
struct g {
  int l, r, id;
} node[MAXN];
bool cmp(g a, g b) { return a.l < b.l; }
int a[MAXN], b[MAXN], in[MAXN], nex[MAXN], c[MAXN];
int tmp[MAXN], ans[MAXN], x[MAXN];
int minv[MAXN * 4];
void build(int o, int l, int r) {
  if (l == r)
    minv[o] = c[l], x[l] = o;
  else {
    int m = (l + r) / 2;
    build((o << 1), l, m);
    build(((o << 1) | 1), m + 1, r);
    minv[o] = min(minv[(o << 1)], minv[((o << 1) | 1)]);
  }
}
int L, R, mn;
void query(int o, int l, int r) {
  if (L <= l && r <= R)
    mn = min(mn, minv[o]);
  else {
    int m = (l + r) / 2;
    if (L <= m) query((o << 1), l, m);
    if (m < R) query(((o << 1) | 1), m + 1, r);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    int l = lower_bound(b + 1, b + n + 1, a[i]) - b;
    in[i] = l;
  }
  memset(tmp, inf, sizeof tmp);
  for (int i = n; i > 0; i--) {
    nex[i] = tmp[in[i]];
    tmp[in[i]] = i;
  }
  memset(tmp, -1, sizeof tmp);
  for (int i = 1; i <= n; i++) {
    c[i] = (tmp[in[i]] == -1) ? inf : (i - tmp[in[i]]);
    tmp[in[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &node[i].l, &node[i].r);
    node[i].id = i;
  }
  sort(node, node + m, cmp);
  build(1, 1, n);
  for (int i = 1, k = 0; i <= n; i++) {
    while (k < m && node[k].l == i) {
      L = i;
      R = node[k].r;
      mn = inf;
      query(1, 1, n);
      ans[node[k].id] = mn;
      k++;
    }
    if (nex[i] < inf) {
      c[nex[i]] = inf;
      minv[x[nex[i]]] = inf;
      for (int j = x[nex[i]]; j > 1; j >>= 1)
        minv[j >> 1] = min(minv[j], minv[j ^ 1]);
    }
  }
  for (int i = 0; i < m; i++) printf("%d\n", ans[i] < n ? ans[i] : -1);
  return 0;
}
