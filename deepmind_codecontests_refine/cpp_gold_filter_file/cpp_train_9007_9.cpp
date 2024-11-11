#include <bits/stdc++.h>
using namespace std;
int n, m, p, top, res, a[500009], b[500009], st[500009], f[500009];
int c[5000009], d[5000009], c2[5000009], d2[5000009];
char s[500009], s2[500009];
void update(int k, int l, int r, int i, int j, int u) {
  int m;
  if (d[k] == 0) {
    c[k] = d[k];
    d[k * 2] = d[k];
    d[k * 2 + 1] = d[k];
    d[k] = -1;
  }
  if ((l > j) || (r < i)) return;
  if ((i <= l) && (r <= j)) {
    c[k] = u;
    d[k * 2] = u;
    d[k * 2 + 1] = u;
    return;
  }
  m = (l + r) >> 1;
  update(k * 2, l, m, i, j, u);
  update(k * 2 + 1, m + 1, r, i, j, u);
  c[k] = max(c[k * 2], c[k * 2 + 1]);
}
void update2(int k, int l, int r, int i, int j, int u) {
  int m;
  if (d2[k] == n + 1) {
    c2[k] = d2[k];
    d2[k * 2] = d2[k];
    d2[k * 2 + 1] = d2[k];
    d2[k] = 0;
  }
  if ((l > j) || (r < i)) return;
  if ((i <= l) && (r <= j)) {
    c2[k] = u;
    d2[k * 2] = u;
    d2[k * 2 + 1] = u;
    return;
  }
  m = (l + r) >> 1;
  update2(k * 2, l, m, i, j, u);
  update2(k * 2 + 1, m + 1, r, i, j, u);
  c2[k] = min(c2[k * 2], c2[k * 2 + 1]);
}
void getres(int k, int l, int r, int i, int j) {
  int m;
  if (d[k] == 0) {
    c[k] = d[k];
    d[k * 2] = d[k];
    d[k * 2 + 1] = d[k];
    d[k] = -1;
  }
  if ((l > j) || (r < i)) return;
  if ((i <= l) && (r <= j)) {
    res = max(res, c[k]);
    return;
  }
  m = (l + r) >> 1;
  getres(k * 2, l, m, i, j);
  getres(k * 2 + 1, m + 1, r, i, j);
}
void getr(int k, int l, int r, int i) {
  int m;
  if (res != n + 1) return;
  if (d2[k] == n + 1) {
    c2[k] = d2[k];
    d2[k * 2] = d2[k];
    d2[k * 2 + 1] = d2[k];
    d2[k] = -1;
  }
  if ((r < i) || (c2[k] == n + 1)) return;
  if ((c2[k] < n + 1) && (l >= i)) {
    res = c2[k];
    return;
  }
  m = (l + r) >> 1;
  getr(k * 2, l, m, i);
  getr(k * 2 + 1, m + 1, r, i);
}
void getl(int k, int l, int r, int i) {
  int m;
  if (res != 0) return;
  if (d[k] == 0) {
    c[k] = d[k];
    d[k * 2] = d[k];
    d[k * 2 + 1] = d[k];
    d[k] = -1;
  }
  if ((l > i) || (c[k] == 0)) return;
  if ((c[k] > 0) && (r <= i)) {
    res = c[k];
    return;
  }
  m = (l + r) >> 1;
  getl(k * 2 + 1, m + 1, r, i);
  getl(k * 2, l, m, i);
}
int bsr(int l, int r, int k) {
  int mid, tmp;
  tmp = (int)1e9;
  while (l <= r) {
    mid = (l + r) >> 1;
    res = 0;
    getres(1, 1, n, k, mid);
    if (res > 0) {
      tmp = min(tmp, res);
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (tmp == (int)1e9)
    return (-1);
  else
    return (tmp);
}
int bsl(int l, int r, int k) {
  int mid, tmp;
  tmp = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    res = 0;
    getres(1, 1, n, mid, k);
    if (res > 0) {
      tmp = max(tmp, res);
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return (tmp);
}
int main() {
  int i, j, x, y;
  char kt;
  scanf("%d%d%d", &n, &m, &p);
  scanf("%s", &s);
  for (i = 1; i <= n; i++)
    if (s[i - 1] == '(')
      a[i] = -1;
    else
      a[i] = 1;
  scanf("%s", &s2);
  for (i = 1; i <= m; i++) {
    if (s2[i - 1] == 'L') b[i] = -1;
    if (s2[i - 1] == 'R') b[i] = 1;
    if (s2[i - 1] == 'D') b[i] = 0;
  }
  top = 0;
  for (i = 1; i <= n; i++)
    if (a[i] == 1) {
      f[i] = st[top];
      f[st[top]] = i;
      top--;
    } else {
      top++;
      st[top] = i;
    }
  for (i = 1; i <= n; i++) update(1, 1, n, i, i, i);
  for (i = 1; i <= n; i++) update2(1, 1, n, i, i, i);
  for (i = 1; i <= 5000009; i++) d[i] = -1;
  for (i = 1; i <= m; i++) {
    if (b[i] == -1) {
      res = 0;
      getl(1, 1, n, p - 1);
      p = res;
    }
    if (b[i] == 1) {
      res = n + 1;
      getr(1, 1, n, p + 1);
      p = res;
    }
    if (b[i] == 0) {
      x = min(f[p], p);
      y = max(f[p], p);
      update(1, 1, n, x, y, 0);
      update2(1, 1, n, x, y, n + 1);
      res = n + 1;
      getr(1, 1, n, p + 1);
      if (res < n + 1)
        p = res;
      else {
        res = 0;
        getl(1, 1, n, p - 1);
        if (res == 0) return (0);
        p = res;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    res = 0;
    getres(1, 1, n, i, i);
    if (res > 0) {
      if (a[i] == -1)
        printf("%c", '(');
      else
        printf("%c", ')');
    }
  }
}
