#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int maxn = 200001;
const int N = 7000005;
int n, m;
int a[maxn];
int sz, root[maxn], ls[N], rs[N], size[N];
inline long long read() {
  long long res = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch = '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * f;
}
void update(int &x, int y, int p, int l, int r) {
  x = ++sz;
  size[x] = size[y] + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  ls[x] = ls[y];
  rs[x] = rs[y];
  if (p <= mid)
    update(ls[x], ls[y], p, l, mid);
  else
    update(rs[x], rs[y], p, mid + 1, r);
}
int query(int x, int y, int val, int l, int r) {
  if (l == r) return 0;
  int mid = (l + r) >> 1;
  int ans = 0;
  if (val <= mid)
    ans += query(ls[x], ls[y], val, l, mid);
  else
    ans += size[ls[y]] - size[ls[x]] + query(rs[x], rs[y], val, mid + 1, r);
  return ans;
}
int ask(int l, int r, int val) {
  if (r > n) r = n;
  return query(root[l - 1], root[r], val, -inf, inf);
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    update(root[i], root[i - 1], a[i], -inf, inf);
  }
  for (int k = 1; k < n; ++k) {
    long long ans = 0;
    for (int i = 1, j = 1; j <= n; i++, j += k) {
      ans += ask(j + 1, j + k, a[i]);
    }
    printf("%I64d ", ans);
  }
  return 0;
}
