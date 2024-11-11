#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100007], T[1000007], val[1000007];
bool push[1000007];
inline int get(int v) {
  if (push[v]) {
    return val[v];
  }
  return T[v];
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    T[v] = a[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  T[v] = max(T[2 * v], T[2 * v + 1]);
}
long long rmq(int v, int tl, int tr, int l, int r) {
  if (push[v]) {
    push[2 * v] = push[2 * v + 1] = true;
    val[2 * v] = val[2 * v + 1] = val[v];
    T[v] = val[v];
    push[v] = false;
  }
  if (tl == l && tr == r) {
    return T[v];
  }
  int tm = (tl + tr) / 2;
  long long res;
  if (r <= tm) {
    res = rmq(2 * v, tl, tm, l, r);
  } else if (l > tm) {
    res = rmq(2 * v + 1, tm + 1, tr, l, r);
  } else {
    res = max(rmq(2 * v, tl, tm, l, tm), rmq(2 * v + 1, tm + 1, tr, tm + 1, r));
  }
  T[v] = max(get(2 * v), get(2 * v + 1));
  return res;
}
void update(int v, int tl, int tr, int l, int r, long long value) {
  if (tl == l && tr == r) {
    push[v] = true;
    val[v] = value;
    return;
  }
  if (push[v]) {
    push[2 * v] = push[2 * v + 1] = true;
    val[2 * v] = val[2 * v + 1] = val[v];
    T[v] = val[v];
    push[v] = false;
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) {
    update(2 * v, tl, tm, l, r, value);
  } else if (l > tm) {
    update(2 * v + 1, tm + 1, tr, l, r, value);
  } else {
    update(2 * v, tl, tm, l, tm, value);
    update(2 * v + 1, tm + 1, tr, tm + 1, r, value);
  }
  T[v] = max(get(2 * v), get(2 * v + 1));
}
int main() {
  int i, w, h;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  build(1, 0, n - 1);
  scanf("%d", &m);
  for (i = 0; i < m; ++i) {
    scanf("%d%d", &w, &h);
    --w;
    long long maxi = rmq(1, 0, n - 1, 0, w);
    printf("%I64d\n", maxi);
    update(1, 0, n - 1, 0, w, maxi + h);
  }
  return 0;
}
