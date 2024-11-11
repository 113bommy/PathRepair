#include <bits/stdc++.h>
using namespace std;
struct Q {
  int l, r, id;
  bool operator<(const Q a) const {
    if (l == a.l) return r < a.r;
    return l < a.l;
  }
} q[400003];
int a[400003], b[400003];
int pos[400003];
int m, sum[400003];
int lb(int k) { return k & -k; }
void add(int k, int v) {
  while (k <= m) {
    sum[k] += v;
    k += lb(k);
  }
}
int s(int k) {
  int re = 0;
  while (k) {
    re += sum[k];
    k -= lb(k);
  }
  return re;
}
int L[400003];
int main() {
  int i, j, n;
  while (~scanf("%d", &n)) {
    memset(sum, 0, sizeof(sum));
    m = 0;
    for (i = 0; i < n; i++) {
      scanf("%d%d", &q[i].l, &q[i].r);
      q[i].id = i;
      b[m++] = q[i].l, b[m++] = q[i].r;
    }
    sort(b, b + m);
    m = unique(b, b + m) - b;
    for (i = 0; i < n; i++) {
      int id = lower_bound(b, b + m, q[i].r) - b + 1;
      add(id, 1);
    }
    sort(q, q + n);
    int ans = 0;
    for (i = 0; i < n; i++) {
      int l = lower_bound(b, b + m, q[i].l) - b + 1;
      int r = lower_bound(b, b + m, q[i].r) - b + 1;
      add(r, -1);
      ans = s(r) - s(l - 1);
      L[q[i].id] = ans;
    }
    for (i = 0; i < n; i++) {
      printf("%d\n", L[i]);
    }
  }
}
