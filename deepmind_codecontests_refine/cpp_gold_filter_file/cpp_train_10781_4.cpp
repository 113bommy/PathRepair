#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long a[N];
struct tr {
  int l, r, maxi;
} t[N * 4];
int sign(long long x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}
void cal(int pos, int l, int r) {
  int mid = (l + r) / 2, u = pos * 2, v = u + 1;
  t[pos].maxi = max(t[u].maxi, t[v].maxi);
  t[pos].l = t[u].l;
  t[pos].r = t[v].r;
  if (!a[mid] || !a[mid + 1] || sign(a[mid]) < sign(a[mid + 1])) {
  } else {
    t[pos].maxi = max(t[pos].maxi, t[u].r + t[v].l);
    if (t[u].maxi == mid - l + 1) {
      t[pos].l = t[u].l + t[v].l;
    }
    if (t[v].maxi == r - mid) t[pos].r = t[v].l + t[u].r;
  }
}
void build(int pos, int l, int r) {
  if (l == r) {
    int x = !!a[l];
    t[pos].l = t[pos].r = t[pos].maxi = x;
    return;
  }
  int mid = (l + r) >> 1;
  build(pos * 2, l, mid);
  build(pos * 2 + 1, mid + 1, r);
  cal(pos, l, r);
}
void update(int pos, int l, int r, int k, int d) {
  int mid = (l + r) >> 1;
  if (l == r) {
    a[l] += d;
    int x = !!a[l];
    t[pos].l = t[pos].r = t[pos].maxi = x;
    return;
  } else {
    int mid = (l + r) >> 1;
    if (k <= mid)
      update(pos * 2, l, mid, k, d);
    else
      update(pos * 2 + 1, mid + 1, r, k, d);
    cal(pos, l, r);
  }
}
int main() {
  int u, v, n, i, m, l, r, d;
  cin >> n;
  cin >> u;
  for (i = 1; i < n; ++i) scanf("%d", &v), a[i - 1] = v - u, u = v;
  if (n > 1) build(1, 0, n - 2);
  cin >> m;
  while (m--) {
    scanf("%d%d%d", &l, &r, &u);
    if (n == 1) {
      printf("1\n");
    } else {
      if (l > 1) update(1, 0, n - 2, l - 2, u);
      if (r < n) update(1, 0, n - 2, r - 1, -u);
      printf("%d\n", t[1].maxi + 1);
    }
  }
}
