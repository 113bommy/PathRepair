#include <bits/stdc++.h>
using namespace std;
int vl[800010][40], num[200010][40], ans[40], stt, n, k, q, opt;
void merge(int o) {
  for (int i = 0; i < stt; i++)
    vl[o][i] = max(vl[(o << 1)][i], vl[(o << 1 | 1)][i]);
}
void update(int o, int l, int r, int x) {
  if (l == r) {
    for (int i = 0; i < stt; i++) {
      vl[o][i] = 0;
      for (int j = 0; j < k; j++) {
        if (i & (1 << j))
          vl[o][i] += num[l][j];
        else
          vl[o][i] -= num[l][j];
      }
    }
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update((o << 1), l, mid, x);
  else
    update((o << 1 | 1), mid + 1, r, x);
  merge(o);
}
void build(int o, int l, int r) {
  if (l == r) {
    for (int i = 0; i < stt; i++) {
      vl[o][i] = 0;
      for (int j = 0; j < k; j++) {
        if (i & (1 << j))
          vl[o][i] += num[l][j];
        else
          vl[o][i] -= num[l][j];
      }
    }
    return;
  }
  int mid = (l + r) >> 1;
  build((o << 1), l, mid), build((o << 1 | 1), mid + 1, r);
  merge(o);
}
void query(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    for (int i = 0; i < stt; i++) ans[i] = max(ans[i], vl[o][i]);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) query((o << 1), l, mid, L, R);
  if (R > mid) query((o << 1 | 1), mid + 1, r, L, R);
  return;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < k; j++) scanf("%d", &num[i][j]);
  stt = 1 << k;
  build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &opt);
    if (opt == 2) {
      int ll, rr;
      scanf("%d%d", &ll, &rr);
      int out = 0, inf = INT_MAX;
      for (int i = 0; i < stt; i++) ans[i] = -inf;
      query(1, 1, n, ll, rr);
      for (int i = 0; i < stt; i++) out = max(out, ans[i] + ans[stt - i - 1]);
      printf("%d\n", out);
    } else {
      int p;
      scanf("%d", &p);
      for (int i = 0; i < k; i++) scanf("%d", &num[p][i]);
      update(1, 1, n, p);
    }
  }
}
