#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 15, M = 3e5 + 15;
int ret[M];
int ind[N * 4], value[N * 4], a[N];
void udpate_ind(int pos, int l, int r, int ii, int v) {
  if (l == r) {
    ind[pos] = v;
    return;
  }
  int mid = (l + r) / 2;
  if (ii <= mid)
    udpate_ind(pos * 2, l, mid, ii, v);
  else
    udpate_ind(pos * 2 + 1, mid + 1, r, ii, v);
  ind[pos] = max(ind[pos * 2], ind[pos * 2 + 1]);
}
int indquery(int pos, int l, int r, int ql, int qr) {
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) return ind[pos];
  int mid = (l + r) / 2;
  return max(indquery(pos * 2, l, mid, ql, qr),
             indquery(pos * 2 + 1, mid + 1, r, ql, qr));
}
void update_val(int pos, int l, int r, int ii, int upd) {
  if (l == r) {
    value[pos] = min(value[pos], upd);
    return;
  }
  int mid = (l + r) / 2;
  if (ii <= mid)
    update_val(pos * 2, l, mid, ii, upd);
  else
    update_val(pos * 2 + 1, mid + 1, r, ii, upd);
  value[pos] = min(value[pos * 2], value[pos * 2 + 1]);
}
int valquery(int pos, int l, int r, int ql, int qr) {
  if (r < ql || qr < l) return 1e9;
  if (ql <= l && r <= qr) return value[pos];
  int mid = (l + r) / 2;
  return min(valquery(pos * 2, l, mid, ql, qr),
             valquery(pos * 2 + 1, mid + 1, r, ql, qr));
}
int X[N];
vector<pair<int, int> > check[N];
int main() {
  int n, i;
  cin >> n;
  int pos = 1;
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    X[pos++] = a[i];
  }
  sort(X + 1, X + pos);
  pos = unique(X + 1, X + pos) - X;
  memset(ret, 127, sizeof(ret));
  memset(value, 127, sizeof(value));
  assert(value[0] >= 1e9);
  int m, l, r;
  scanf("%d", &m);
  for (i = 0; i < m; ++i) {
    scanf("%d%d", &l, &r);
    check[r].push_back(make_pair(l, i));
  }
  int p, j, k, temp;
  for (i = 1; i <= n; ++i) {
    p = lower_bound(X + 1, X + pos + 1, a[i]) - X;
    for (j = 1; j <= p;) {
      k = indquery(1, 1, pos, j, p);
      assert(a[k] <= a[i]);
      if (k == 0) break;
      update_val(1, 1, n, k, a[i] - a[k]);
      temp = lower_bound(X + 1, X + pos + 1, (a[i] + a[k]) / 2) - X;
      if (j >= temp) break;
      j = temp;
    }
    for (j = 0; j < check[i].size(); ++j) {
      ret[check[i][j].second] =
          min(ret[check[i][j].second], valquery(1, 1, n, check[i][j].first, i));
    }
    udpate_ind(1, 1, pos, p, i);
  }
  memset(ind, 0, sizeof(ind));
  memset(value, 127, sizeof(value));
  for (i = 1; i <= n; ++i) {
    p = lower_bound(X + 1, X + pos + 1, a[i]) - X;
    for (j = pos; j >= p;) {
      k = indquery(1, 1, pos, p, j);
      if (k == 0) break;
      update_val(1, 1, n, k, a[k] - a[i]);
      temp = lower_bound(X + 1, X + pos + 1, (a[i] + a[k] + 1) / 2) - X - 1;
      if (j <= temp) break;
      j = temp;
    }
    for (j = 0; j < check[i].size(); ++j) {
      ret[check[i][j].second] =
          min(ret[check[i][j].second], valquery(1, 1, n, check[i][j].first, i));
    }
    udpate_ind(1, 1, pos, p, i);
  }
  for (i = 0; i < m; ++i) printf("%d\n", ret[i]);
}
