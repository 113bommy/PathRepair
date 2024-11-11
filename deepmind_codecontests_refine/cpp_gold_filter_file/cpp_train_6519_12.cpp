#include <bits/stdc++.h>
using namespace std;
int siz, tr[100005], i, tmp, j, n, s1, s2, x[100005], l[100005][20],
    r[100005][20], v[100005], p, q, u, mid;
const int inf = 1e9 + 7;
int abs(int k) { return k < 0 ? -k : k; }
int lowbit(int p) { return p & -p; }
void add(int p, int v) {
  if (p == 0) {
    tr[0] += v;
    return;
  }
  while (p <= n) {
    tr[p] += v;
    p += lowbit(p);
  }
}
int query(int p) {
  int ans = 0;
  while (p > 0) {
    ans += tr[p];
    p -= lowbit(p);
  }
  return ans + tr[0];
}
int main() {
  scanf("%d%d%d", &n, &s1, &s2);
  for (i = 1; i <= n; i++) scanf("%d", &x[i]);
  if (n == 1) {
    printf("%d\n", min(max(abs(s1 - s2), abs(x[1] - s1)),
                       max(abs(s1 - s2), abs(x[1] - s2))));
    return 0;
  }
  p = abs(s1 - s2);
  q = inf;
  for (i = 0; i < n; i++) l[i][0] = r[i][0] = x[i + 1];
  for (i = 1; i < 20; i++) {
    for (j = 0; j < n; j++) {
      l[j][i] = min(l[j][i - 1], l[min(n - 1, j + (1 << (i - 1)))][i - 1]);
      r[j][i] = max(r[j][i - 1], r[min(n - 1, j + (1 << (i - 1)))][i - 1]);
    }
  }
  while (p < q) {
    memset(tr, 0, sizeof(tr));
    mid = (p + q) / 2;
    siz = 0;
    for (i = 1; i < n; i++) {
      v[i] = i;
      for (j = 19; j >= 0; j--) {
        if (abs(l[v[i]][j] - x[i]) <= mid && abs(r[v[i]][j] - x[i]) <= mid)
          v[i] = min(n, v[i] + (1 << j));
        if (v[i] == n) break;
      }
    }
    i = 0;
    x[0] = s1;
    v[0] = 0;
    for (j = 19; j >= 0; j--) {
      if (abs(l[v[i]][j] - x[0]) <= mid && abs(r[v[i]][j] - x[i]) <= mid)
        v[i] = min(n, v[i] + (1 << j));
      if (v[i] == n) break;
    }
    tmp = v[i];
    x[0] = s2;
    v[0] = 0;
    for (j = 19; j >= 0; j--) {
      if (abs(l[v[i]][j] - x[i]) <= mid && abs(r[v[i]][j] - x[i]) <= mid)
        v[i] = min(n, v[i] + (1 << j));
      if (v[i] == n) break;
    }
    v[i] = max(tmp, v[i]);
    add(v[0], 1);
    siz++;
    if (v[0] == n) goto tag;
    for (i = 1; i < n; i++) {
      u = query(i - 1);
      if (u < siz && abs(x[i + 1] - x[i]) <= mid) {
        siz++;
        add(v[i], 1);
        if (v[i] == n) goto tag;
      }
    }
    p = mid + 1;
    continue;
  tag:
    q = mid;
  }
  printf("%d\n", p);
  return 0;
}
