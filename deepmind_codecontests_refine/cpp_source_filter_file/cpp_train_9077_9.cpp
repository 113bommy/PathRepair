#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 1e6 + 1;
int dta[N];
int cnt[(M + 10) << 2], mini[(M + 10) << 2];
int lazy[(M + 10) << 2];
void pushdown(int k) {
  if (!lazy[k]) {
    return;
  }
  mini[k << 1] += lazy[k], lazy[k << 1] += lazy[k];
  mini[k << 1 | 1] += lazy[k], lazy[k << 1 | 1] += lazy[k];
  lazy[k] = 0;
  return;
}
void pushup(int k) {
  if (mini[k << 1] == mini[k << 1 | 1]) {
    mini[k] = mini[k << 1], cnt[k] = cnt[k << 1] + cnt[k << 1 | 1];
  } else if (mini[k << 1] < mini[k << 1 | 1]) {
    mini[k] = mini[k << 1], cnt[k] = cnt[k << 1];
  } else {
    mini[k] = mini[k << 1 | 1], cnt[k] = cnt[k << 1 | 1];
  }
  return;
}
void modify(int k, int l, int r, int pos, int val) {
  if (l == r) {
    cnt[k] += val;
    return;
  }
  pushdown(k);
  int mid = (l + r) >> 1;
  if (pos <= mid) {
    modify(k << 1, l, mid, pos, val);
  } else {
    modify(k << 1 | 1, mid + 1, r, pos, val);
  }
  pushup(k);
  return;
}
void modify(int k, int l, int r, int x, int y, int v) {
  if (l > y || r < x) {
    return;
  }
  if (l >= x && r <= y) {
    mini[k] += v, lazy[k] += v;
    return;
  }
  pushdown(k);
  int mid = (l + r) >> 1;
  modify(k << 1, l, mid, x, y, v), modify(k << 1 | 1, mid + 1, r, x, y, v);
  pushup(k);
  return;
}
int query(int k, int l, int r, int x, int y) {
  if (l >= y || r <= x) {
    return 0;
  }
  if (mini[k] >= 2) {
    return 0;
  }
  if (l >= x && r <= y) {
    if (mini[k] == 1) {
      return cnt[k];
    }
    return 0;
  }
  pushdown(k);
  int mid = (l + r) >> 1, res = 0;
  res += query(k << 1, l, mid, x, y),
      res += query(k << 1 | 1, mid + 1, r, x, y);
  pushup(k);
  return res;
}
void update(int x, int y, int v) {
  if (x == y) {
    return;
  }
  if (x > y) {
    swap(x, y);
  }
  modify(1, 0, M, x, y - 1, v);
  return;
}
signed main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &dta[i]);
  }
  dta[0] = M, dta[n + 1] = 0;
  for (int i = 0; i <= n; ++i) {
    update(dta[i], dta[i + 1], 1);
    modify(1, 0, M, dta[i], 1);
  }
  while (m--) {
    int pos, val;
    scanf("%d%d", &pos, &val);
    update(dta[pos], dta[pos - 1], -1), update(dta[pos], dta[pos + 1], -1);
    modify(1, 0, M, dta[pos], -1);
    dta[pos] = val;
    update(dta[pos], dta[pos - 1], 1), update(dta[pos], dta[pos + 1], 1);
    modify(1, 0, M, dta[pos], 1);
    printf("%d\n", query(1, 0, M, 1, M - 1));
  }
  return 0;
}
