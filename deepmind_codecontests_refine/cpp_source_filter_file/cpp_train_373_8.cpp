#include <bits/stdc++.h>
using namespace std;
long long h[100010], dat[100010], s[100010][5];
int n, root, tot, l[100010], r[100010], sum[100010];
inline void update(int x) {
  if (!x) return;
  int ss = sum[l[x]] + 1;
  for (int i = 0; i < 5; i++)
    s[x][i] = (long long)(s[l[x]][i] + s[r[x]][(i - ss % 5 + 5) % 5]);
  s[x][ss % 5] += (long long)dat[x];
  sum[x] = ss + sum[r[x]];
  h[x] = max(h[l[x]], h[r[x]]) + 1;
}
inline void zig(int &x) {
  int y = l[x];
  l[x] = r[y];
  r[y] = x;
  update(x);
  update(y);
  x = y;
}
inline void zag(int &x) {
  int y = r[x];
  r[x] = l[y];
  l[y] = x;
  update(x);
  update(y);
  x = y;
}
inline void balance(int &x) {
  update(x);
  if (h[l[x]] > h[r[x]] + 1) {
    if (h[l[l[x]]] < h[l[r[x]]]) zag(l[x]);
    zig(x);
  }
  if (h[r[x]] > h[l[x]] + 1) {
    if (h[r[r[x]]] < h[r[l[x]]]) zig(r[x]);
    zag(x);
  }
}
inline void ins(int &x, long long v) {
  if (!x) {
    dat[x = ++tot] = v;
    l[x] = r[x] = 0;
  } else
    ins(v < dat[x] ? l[x] : r[x], v);
  balance(x);
}
inline void del(int &x, long long v) {
  if ((!l[x]) && (!r[x])) {
    dat[x] = 0;
    x = 0;
    return;
  }
  if (dat[x] == v) {
    if (h[l[x]] > h[r[x]]) {
      zig(x);
      del(r[x], v);
    } else {
      zag(x);
      del(l[x], v);
    }
  } else
    del(v < dat[x] ? l[x] : r[x], v);
  balance(x);
}
int main() {
  scanf("%d\n", &n);
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));
  memset(s, 0, sizeof(s));
  memset(h, 0, sizeof(h));
  memset(dat, 0, sizeof(dat));
  memset(sum, 0, sizeof(sum));
  root = 1;
  tot = 0;
  h[0] = -1;
  while (n--) {
    char x[10];
    scanf("%s", &x);
    char y = x[0];
    long long z;
    if (y == 'a') {
      scanf("%d", &z);
      ins(root, z);
    } else if (y == 'd') {
      scanf("%d", &z);
      del(root, z);
    } else
      printf("%I64d\n", s[root][3]);
  }
  return 0;
}
