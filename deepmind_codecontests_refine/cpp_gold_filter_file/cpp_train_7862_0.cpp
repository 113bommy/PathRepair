#include <bits/stdc++.h>
using namespace std;
int n, mn[200005 * 4], tag[200005 * 4];
long long sum[200005 * 4], h[200005], ans;
vector<int> v[200005];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void divide(int x, int p) {
  for (int i = 1; i * i <= x; ++i)
    if (x % i == 0) {
      v[i].push_back(p);
      if (i * i != x) v[x / i].push_back(p);
    }
}
void build(int pos, int l, int r) {
  if (l == r) {
    sum[pos] = mn[pos] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build((pos << 1), l, mid);
  build((pos << 1 | 1), mid + 1, r);
  sum[pos] = sum[(pos << 1)] + sum[(pos << 1 | 1)];
  mn[pos] = min(mn[(pos << 1)], mn[(pos << 1 | 1)]);
}
void lazy(int pos, int l, int r) {
  int mid = (l + r) >> 1;
  sum[(pos << 1)] = 1ll * (mid - l + 1) * tag[pos];
  sum[(pos << 1 | 1)] = 1ll * (r - mid) * tag[pos];
  mn[(pos << 1)] = mn[(pos << 1 | 1)] = tag[(pos << 1)] = tag[(pos << 1 | 1)] =
      tag[pos];
  tag[pos] = 0;
}
void modify(int pos, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    sum[pos] = 1ll * (r - l + 1) * z;
    mn[pos] = tag[pos] = z;
    return;
  }
  if (tag[pos]) lazy(pos, l, r);
  int mid = (l + r) >> 1;
  if (x <= mid) modify((pos << 1), l, mid, x, y, z);
  if (y > mid) modify((pos << 1 | 1), mid + 1, r, x, y, z);
  sum[pos] = sum[(pos << 1)] + sum[(pos << 1 | 1)];
  mn[pos] = min(mn[(pos << 1)], mn[(pos << 1 | 1)]);
}
int find(int pos, int l, int r, int x) {
  if (x <= mn[pos]) return l - 1;
  if (l == r || tag[pos]) return r;
  int mid = (l + r) >> 1;
  if (x > mn[(pos << 1 | 1)]) return find((pos << 1 | 1), mid + 1, r, x);
  return find((pos << 1), l, mid, x);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) divide(read(), i);
  build(1, 1, n);
  h[200001] = 1ll * n * (n + 1) / 2;
  for (int i = 200000; i >= 1; --i) {
    if (v[i].size() >= 2) {
      if (v[i][1] < n) modify(1, 1, n, v[i][1] + 1, n, n + 1);
      int p = find(1, 1, n, v[i].back());
      if (v[i][0] < p) modify(1, 1, n, v[i][0] + 1, p, v[i].back());
      int q = find(1, 1, n, v[i][v[i].size() - 2]);
      if (q) modify(1, 1, n, 1, q, v[i][v[i].size() - 2]);
    }
    h[i] = 1ll * n * (n + 1) - sum[1];
    ans += (h[i + 1] - h[i]) * i;
  }
  cout << ans << endl;
  return 0;
}
