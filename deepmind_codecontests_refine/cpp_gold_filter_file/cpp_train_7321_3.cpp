#include <bits/stdc++.h>
using namespace std;
struct Tnode {
  int c, s, num;
} a[100005];
struct node {
  int d, l, num;
} b[100005];
long long f[100005][3];
int n, m, g[100005][3], p[100005][3], res[100005], tot;
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].c, &a[i].s);
    a[i].num = i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &b[i].d, &b[i].l);
    b[i].num = i;
  }
}
int cmp(const Tnode &a, const Tnode &b) { return a.s < b.s; }
int cmp2(const node &a, const node &b) {
  return a.l < b.l || a.l == b.l && a.d < b.d;
}
int search(Tnode a) {
  int l = 1, r = m, mid, ans = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (b[mid].l < a.s)
      l = mid + 1;
    else if (b[mid].l > a.s)
      r = mid - 1;
    else if (b[mid].d >= a.c) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
int search2(Tnode a) {
  int l = 1, r = m, mid, ans = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (b[mid].l < a.s)
      l = mid + 1;
    else if (b[mid].l > a.s)
      r = mid - 1;
    else {
      ans = mid;
      l = mid + 1;
    }
  }
  return ans;
}
void getpath(int n, int k) {
  if (!n) return;
  if (k) {
    tot++;
    res[p[n][k]] = a[n].num;
  }
  getpath(n - 1, g[n][k]);
}
void work() {
  sort(a + 1, a + n + 1, cmp);
  sort(b + 1, b + m + 1, cmp2);
  int i, j, k, l, r;
  for (i = 1; i <= n; i++) {
    f[i][0] = f[i - 1][0];
    g[i][0] = 0;
    if (f[i - 1][1] > f[i][0]) {
      f[i][0] = f[i - 1][1];
      g[i][0] = 1;
    }
    if (f[i - 1][2] > f[i][0]) {
      f[i][0] = f[i - 1][2];
      g[i][0] = 2;
    }
    l = search(a[i]);
    if (l) {
      p[i][1] = b[l].num;
      f[i][1] = f[i - 1][0];
      g[i][1] = 0;
      if (f[i - 1][1] > f[i][1]) {
        f[i][1] = f[i - 1][1];
        g[i][1] = 1;
      }
      if (f[i - 1][2] > f[i][1]) {
        f[i][1] = f[i - 1][2];
        g[i][1] = 2;
      }
      f[i][1] += a[i].c;
    }
    a[i].s--;
    l = search(a[i]);
    a[i].s++;
    if (l) {
      a[i].s--;
      r = search2(a[i]);
      a[i].s++;
      p[i][2] = b[l].num;
      f[i][2] = f[i - 1][0];
      g[i][2] = 0;
      if (f[i - 1][2] > f[i][2]) {
        f[i][2] = f[i - 1][2];
        g[i][2] = 2;
      }
      while (l <= r && b[l].num == p[i - 1][1]) l++;
      if (l <= r && f[i - 1][1] > f[i][2]) {
        f[i][2] = f[i - 1][1];
        g[i][2] = 1;
        p[i][2] = b[l].num;
      }
      f[i][2] += a[i].c;
    }
  }
  k = 0;
  if (f[n][1] > f[n][k]) k = 1;
  if (f[n][2] > f[n][k]) k = 2;
  printf("%I64d\n", f[n][k]);
  getpath(n, k);
  printf("%d\n", tot);
  for (i = 1; i <= m; i++)
    if (res[i]) printf("%d %d\n", i, res[i]);
}
int main() {
  init();
  work();
  return 0;
}
