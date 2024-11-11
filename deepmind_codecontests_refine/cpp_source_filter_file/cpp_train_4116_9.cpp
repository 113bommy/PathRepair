#include <bits/stdc++.h>
using namespace std;
int lim;
struct data {
  int val, cnt;
  friend bool operator<(data a, data b) { return a.cnt > b.cnt; }
};
struct node {
  int len;
  data a[6];
  friend node operator+(node a, node b) {
    node c = a;
    for (int i = 1; i <= b.len; i++) {
      bool flag = false;
      for (int j = 1; j <= c.len; j++) {
        if (c.a[j].val == b.a[i].val) c.a[j].cnt += b.a[i].cnt, flag = true;
      }
      if (!flag) c.a[++c.len] = b.a[i];
    }
    if (c.len > lim) {
      sort(c.a + 1, c.a + c.len + 1);
      for (int i = c.len; i > lim; i--) {
        for (int j = 1; j <= i; j++) c.a[i].cnt -= c.a[j].cnt;
      }
      while (c.len && c.a[c.len].cnt <= 0) c.len--;
    }
    return c;
  }
} s[150005 * 4];
int tag[150005 * 4], a[150005];
void build(int p, int l, int r) {
  if (l == r) {
    s[p].len = 1, s[p].a[1] = (data){a[l], 1};
    return;
  }
  build((p << 1), l, ((l + r) >> 1));
  build((p << 1 | 1), ((l + r) >> 1) + 1, r);
  s[p] = s[(p << 1)] + s[(p << 1 | 1)];
}
void push_down(int p, int l, int r) {
  if (!tag[p]) return;
  tag[(p << 1)] = tag[(p << 1 | 1)] = tag[p];
  s[(p << 1)].len = s[(p << 1 | 1)].len = 1;
  s[(p << 1)].a[1] = (data){tag[p], ((l + r) >> 1) - l + 1};
  s[(p << 1 | 1)].a[1] = (data){tag[p], r - ((l + r) >> 1)};
  tag[p] = 0;
}
void update(int p, int l, int r, int ul, int ur, int k) {
  if (l >= ul && r <= ur) {
    tag[p] = k;
    s[p].len = 1, s[p].a[1] = (data){k, r - l + 1};
    return;
  }
  push_down(p, l, r);
  if (((l + r) >> 1) >= ul) update((p << 1), l, ((l + r) >> 1), ul, ur, k);
  if (((l + r) >> 1) < ur)
    update((p << 1 | 1), ((l + r) >> 1) + 1, r, ul, ur, k);
  s[p] = s[(p << 1)] + s[(p << 1 | 1)];
}
node query(int p, int l, int r, int ul, int ur) {
  if (l >= ul && r <= ur) return s[p];
  push_down(p, l, r);
  if (((l + r) >> 1) < ul)
    return query((p << 1 | 1), ((l + r) >> 1) + 1, r, ul, ur);
  else if (((l + r) >> 1) >= ur)
    return query((p << 1), l, ((l + r) >> 1), ul, ur);
  else
    return query((p << 1), l, ((l + r) >> 1), ul, ur) +
           query((p << 1 | 1), ((l + r) >> 1) + 1, r, ul, ur);
}
int n, m, p;
int main() {
  cin >> n >> m >> p;
  lim = 100 / p;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, 1, n);
  int t, l, r, x;
  node res;
  while (m--) {
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1) {
      scanf("%d", &x);
      update(1, 1, n, l, r, x);
    } else {
      res = query(1, 1, n, l, r);
      printf("%d ", res.len);
      for (int i = 1; i <= res.len; i++) {
        printf("%d ", res.a[i].val);
      }
      puts("");
    }
  }
  return 0;
}
