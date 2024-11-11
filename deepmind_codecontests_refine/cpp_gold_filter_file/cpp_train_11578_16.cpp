#include <bits/stdc++.h>
using namespace std;
int n, m, k, t, inf = 9999999;
int a[200005], l[200005], r[200005], d[200005];
struct node {
  int l, r, d;
} e[200005];
bool cmp(node a, node b) {
  if (a.l < b.l) {
    return 1;
  }
  if (a.l == b.l) {
    if (a.r < b.l) {
      return 1;
    }
    return 0;
  }
  return 0;
}
bool query(int x) {
  if (x == 0) {
    return 1;
  }
  int pos = m - x + 1;
  int minn = a[pos], min_pos = inf, max_pos = -1, flag = 1, tot = 0;
  for (int i = 1; i <= k; i++) {
    if (d[i] > minn) {
      flag = 0;
      e[++tot].l = l[i];
      e[tot].r = r[i];
      e[tot].d = d[i];
    }
  }
  if (flag == 1) {
    return 1;
  }
  sort(e + 1, e + 1 + tot, cmp);
  int ip = 1, cost = n + 1;
  while (ip <= tot) {
    max_pos = e[ip].r;
    int las = tot + 1;
    for (int j = ip + 1; j <= tot; j++) {
      if (e[j].l > max_pos) {
        las = j;
        break;
      }
      if (e[j].r > max_pos) {
        max_pos = e[j].r;
      }
    }
    cost += 2 * (max_pos - (e[ip].l - 1));
    ip = las;
  }
  if (cost <= t) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  scanf("%d %d %d %d", &m, &n, &k, &t);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d %d %d", &l[i], &r[i], &d[i]);
  }
  sort(a + 1, a + 1 + m);
  int l = 0, r = m, ans = 0;
  while (l <= r) {
    if (l == r) {
      if (query(l)) {
        ans = l;
      }
      break;
    }
    if (l + 1 == r) {
      if (query(r)) {
        ans = r;
        break;
      }
      if (query(l)) {
        ans = l;
        break;
      }
      break;
    }
    int mid = (l + r) / 2;
    if (query(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
