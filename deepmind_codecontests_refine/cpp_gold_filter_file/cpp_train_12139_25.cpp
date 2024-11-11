#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = N * 40;
int n, m, k, a[N];
queue<int> q[N];
int size, rt[M], c[M][2], v[M];
inline void update(int &p, int x, int y, int l = 1, int r = n) {
  ++size;
  c[size][0] = c[p][0];
  c[size][1] = c[p][1];
  v[size] = v[p] + y;
  p = size;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(c[p][0], x, y, l, mid);
  else
    update(c[p][1], x, y, mid + 1, r);
}
inline int ask(int p, int x, int y, int l = 1, int r = n) {
  if (l > y || r < x) return 0;
  if (x <= l && r <= y) return v[p];
  int mid = (l + r) >> 1;
  return ask(c[p][0], x, y, l, mid) + ask(c[p][1], x, y, mid + 1, r);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = n; i; --i) {
    rt[i] = rt[i + 1];
    update(rt[i], i, 1);
    q[a[i]].push(i);
    if ((int)q[a[i]].size() > k) {
      update(rt[i], q[a[i]].front(), -1);
      q[a[i]].pop();
    }
  }
  scanf("%d", &m);
  int x, y, lans = 0;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    x = (x + lans) % n + 1;
    y = (y + lans) % n + 1;
    if (x > y) swap(x, y);
    printf("%d\n", lans = ask(rt[x], x, y));
  }
  return 0;
}
