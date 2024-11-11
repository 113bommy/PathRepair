#include <bits/stdc++.h>
using namespace std;
struct seg_tree {
  int num[200005];
  int dmin[800005];
  int dmax[800005];
  void build(int i, int l, int r) {
    if (l < r) {
      build(i << 1, l, l + r >> 1);
      build(i << 1 | 1, (l + r >> 1) + 1, r);
      push_up(i);
    } else {
      dmax[i] = dmin[i] = num[l];
    }
  }
  inline void push_up(int i) {
    dmax[i] = max(dmax[i << 1], dmax[i << 1 | 1]);
    dmin[i] = min(dmin[i << 1], dmin[i << 1 | 1]);
  }
  pair<int, int> query(int i, int l, int r, int l1, int r1) {
    if (l == l1 && r == r1)
      return {dmax[i], dmin[i]};
    else {
      int mid = l + r >> 1;
      if (l1 > mid) {
        return query(i << 1 | 1, mid + 1, r, l1, r1);
      } else if (r1 <= mid) {
        return query(i << 1, l, mid, l1, r1);
      } else {
        pair<int, int> tmp, tmp2;
        tmp = query(i << 1, l, mid, l1, mid);
        tmp2 = query(i << 1 | 1, mid + 1, r, mid + 1, r1);
        return {max(tmp.first, tmp2.first), min(tmp.second, tmp.second)};
      }
    }
  }
  inline void updat(int i, int l, int r, int l1, int x) {
    if (l == l1 && r == l1)
      dmax[i] = dmin[i] = x;
    else {
      int mid = l + r >> 1;
      if (l1 > mid)
        updat(i << 1 | 1, mid + 1, r, l1, x);
      else if (l1 <= mid)
        updat(i << 1, l, mid, l1, x);
      push_up(i);
    }
  }
} tr[1 << 5];
int p[200050][5];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      scanf("%d", &p[i][j]);
    }
    for (int j = 0; j < (1 << k); j++) {
      int sum = 0;
      for (int z = 0; z < k; z++) {
        if ((1 << z) & j) {
          sum += p[i][z];
        } else {
          sum -= p[i][z];
        }
      }
      tr[j].num[i] = sum;
    }
  }
  for (int j = 0; j < (1 << k); j++) {
    tr[j].build(1, 1, n);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int index;
      scanf("%d", &index);
      for (int i = 0; i < k; i++) {
        scanf("%d", &p[index][i]);
      }
      for (int j = 0; j < (1 << k); j++) {
        int sum = 0;
        for (int z = 0; z < k; z++) {
          if ((1 << z) & j) {
            sum += p[index][z];
          } else {
            sum -= p[index][z];
          }
        }
        tr[j].updat(1, 1, n, index, sum);
      }
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      int ans = 0;
      for (int j = 0; j < (1 << k); j++) {
        pair<int, int> tmp = tr[j].query(1, 1, n, l, r);
        ans = max(ans, tmp.first - tmp.second);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
