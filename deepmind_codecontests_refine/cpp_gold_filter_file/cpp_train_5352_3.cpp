#include <bits/stdc++.h>
using namespace std;
int n, q;
int query(int *a, int i) {
  if (i < 0) return 0;
  int res = 0;
  while (i) {
    res += a[i];
    i -= (i & (-i));
  }
  return res;
}
int query(int *a, int l, int r) { return query(a, r) - query(a, l - 1); }
void add(int *a, int i, int del) {
  if (i <= 0) return;
  while (i <= n) {
    a[i] += del;
    i += (i & (-i));
  }
}
void add(int *a, int l, int r, int del) {
  add(a, l, del);
  add(a, r + 1, -del);
}
vector<pair<int, int> > qry[100010];
int a[100010];
int lst[100010], lst2[100010];
int tmp[100010];
int fir[100010];
int per[100010];
int can[100010], cnt[100010];
int res[100010];
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    lst[i] = tmp[a[i]];
    lst2[i] = lst[lst[i]];
    tmp[a[i]] = i;
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    qry[r].push_back(make_pair(l, i));
  }
  for (int i = 1; i <= n; ++i) {
    if (i - lst[i] != per[a[i]]) {
      if (!lst[i]) {
        add(can, 1, i, 1);
      } else {
        if (!lst2[i]) {
          per[a[i]] = i - lst[i];
          add(can, lst[i] + 1, i, 1);
        } else {
          add(can, fir[a[i]] + 1, lst[i], -1);
          fir[a[i]] = lst2[i];
          per[a[i]] = i - lst[i];
          add(can, fir[a[i]] + 1, i, 1);
        }
      }
    } else {
      add(can, lst[i] + 1, i, 1);
    }
    add(cnt, lst[i] + 1, 1);
    add(cnt, i + 1, -1);
    for (int j = qry[i].size() - 1; ~j; --j) {
      res[qry[i][j].second] = query(cnt, qry[i][j].first) + 1 -
                              ((query(can, qry[i][j].first) > 0) ? 1 : 0);
    }
  }
  for (int i = 1; i <= q; ++i) {
    printf("%d\n", res[i]);
  }
  return 0;
}
