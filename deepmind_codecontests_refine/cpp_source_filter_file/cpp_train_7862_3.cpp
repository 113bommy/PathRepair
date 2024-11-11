#include <bits/stdc++.h>
using namespace std;
long long H[200005];
int a[200005];
long long c[200005 << 2];
long long s[200005 << 2];
long long lz[200005 << 2];
vector<int> v[200005];
int u;
int yl, yr;
void build(int o, int l, int r) {
  if (l == r) {
    lz[o] = l;
    c[o] = l;
    s[o] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(o * 2, l, mid);
  build(o * 2 + 1, mid + 1, r);
  lz[o] = -1;
  c[o] = c[o * 2] + c[o * 2 + 1];
  s[o] = min(s[o * 2], s[o * 2 + 1]);
}
void pushdown(int o, int l, int r) {
  if (l == r) return;
  if (lz[o] == -1) return;
  lz[o * 2] = lz[o];
  lz[o * 2 + 1] = lz[o];
  s[o * 2] = lz[o];
  s[o * 2 + 1] = lz[o];
  int mid = (l + r) >> 1;
  c[o * 2] = lz[o] * (mid - l + 1);
  c[o * 2 + 1] = lz[o] * (r - mid);
  lz[o] = -1;
}
void update(int o, int l, int r) {
  if (yl <= l && yr >= r) {
    c[o] = 1LL * u * (r - l + 1);
    s[o] = u;
    lz[o] = u;
    return;
  }
  pushdown(o, l, r);
  int mid = (l + r) >> 1;
  if (yl <= mid) update(o * 2, l, mid);
  if (yr > mid) update(o * 2 + 1, mid + 1, r);
  c[o] = c[o * 2] + c[o * 2 + 1];
  s[o] = min(s[o * 2], s[o * 2 + 1]);
  if (lz[o * 2] == lz[o * 2 + 1] && lz[o * 2] >= 0) lz[o] = lz[o * 2];
}
int query(int o, int l, int r) {
  if (l == r && c[o] < u) return l;
  if (l == r && c[o] >= u) return 0;
  if (lz[o] != -1 && lz[o] < u) return r;
  if (lz[o] != -1 && lz[o] >= u) return 0;
  int mid = (l + r) >> 1;
  if (s[o * 2 + 1] < u)
    return query(o * 2 + 1, mid + 1, r);
  else
    return query(o * 2, l, mid);
}
int main() {
  int n;
  scanf("%d", &n);
  int mx = -1;
  memset(a, 0, sizeof(a));
  for (int i = 1; i < n + 1; ++i) {
    int tmp;
    scanf("%d", &tmp);
    a[tmp] = i;
    mx = max(mx, tmp);
  }
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j * i <= mx; ++j) {
      if (a[j * i]) v[i].push_back(a[j * i]);
    }
  }
  for (int i = 0; i <= mx; ++i) sort(v[i].begin(), v[i].end());
  long long sum = 1LL * n * (n + 1);
  build(1, 1, n);
  for (int i = mx; i >= 0; --i) {
    H[i] = sum - c[1];
    int k = v[i].size();
    if (k < 2) {
      continue;
    }
    u = n + 1;
    yl = v[i][1] + 1;
    yr = n;
    if (yl <= yr) update(1, 1, n);
    u = v[i][k - 1];
    int pos = query(1, 1, n);
    pos = min(pos, v[i][1]);
    if (pos > v[i][0] && pos <= v[i][1]) {
      yl = v[i][0] + 1;
      yr = pos;
      update(1, 1, n);
    }
    u = v[i][k - 2];
    pos = query(1, 1, n);
    pos = min(pos, v[i][0]);
    if (pos >= 1 && pos <= v[i][0]) {
      yl = 1;
      yr = pos;
      update(1, 1, n);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= mx; ++i) {
    ans += 1LL * i * (H[i] - H[i - 1]);
  }
  printf("%I64d\n", ans);
}
