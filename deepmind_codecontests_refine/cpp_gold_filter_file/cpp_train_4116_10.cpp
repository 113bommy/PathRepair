#include <bits/stdc++.h>
using namespace std;
int read() {
  int cnt = 0, f = 1;
  char ch = 0;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch))
    cnt = (cnt << 1) + (cnt << 3) + (ch - '0'), ch = getchar();
  return cnt * f;
}
int n, m, p;
int a[150050];
struct tree {
  int num, tag, a[5], b[5];
  tree operator+(const tree &A) {
    tree res = A;
    res.tag = 0;
    for (int i = 0; i < num; i++) {
      bool flag = 0;
      for (int j = 0; j < res.num; j++) {
        if (a[i] == res.a[j]) {
          flag = 1;
          res.b[j] += b[i];
          break;
        }
      }
      if (flag) continue;
      if (res.num < p) {
        res.a[res.num] = a[i];
        res.b[res.num] = b[i];
        ++res.num;
        continue;
      }
      int k = 0;
      for (int j = 1; j < res.num; j++)
        if (res.b[j] < res.b[k]) k = j;
      if (b[i] < res.b[k]) {
        for (int j = 0; j < res.num; j++) res.b[j] -= b[i];
      } else {
        int tmp = res.b[k];
        res.a[k] = a[i];
        res.b[k] = b[i];
        for (int j = 0; j < res.num; j++) res.b[j] -= tmp;
      }
    }
    return res;
  }
} t[150050 << 2];
void build(int x, int l, int r) {
  if (l == r) {
    t[x].a[0] = a[l];
    t[x].b[0] = t[x].num = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  t[x] = t[x << 1] + t[x << 1 | 1];
}
void pushnow(int x, int l, int r, int v) {
  t[x].num = 1;
  t[x].a[0] = v;
  t[x].b[0] = r - l + 1;
  t[x].tag = v;
}
void pushdown(int x, int l, int r) {
  if (t[x].tag) {
    int mid = (l + r) >> 1;
    pushnow(x << 1, l, mid, t[x].tag);
    pushnow(x << 1 | 1, mid + 1, r, t[x].tag);
    t[x].tag = 0;
  }
}
void modify(int x, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    pushnow(x, l, r, v);
    return;
  }
  pushdown(x, l, r);
  int mid = (l + r) >> 1;
  if (L <= mid) modify(x << 1, l, mid, L, R, v);
  if (R > mid) modify(x << 1 | 1, mid + 1, r, L, R, v);
  t[x] = t[x << 1] + t[x << 1 | 1];
}
tree query(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return t[x];
  pushdown(x, l, r);
  int mid = (l + r) >> 1;
  if (L > mid)
    return query(x << 1 | 1, mid + 1, r, L, R);
  else if (R <= mid)
    return query(x << 1, l, mid, L, R);
  else
    return query(x << 1, l, mid, L, R) + query(x << 1 | 1, mid + 1, r, L, R);
}
int main() {
  n = read(), m = read(), p = read();
  p = 100 / p;
  for (int i = 1; i <= n; i++) a[i] = read();
  build(1, 1, n);
  while (m--) {
    int op = read(), l = read(), r = read();
    if (op == 1) modify(1, 1, n, l, r, read());
    if (op == 2) {
      tree ans = query(1, 1, n, l, r);
      cout << ans.num << " ";
      for (int i = 0; i < ans.num; i++) cout << ans.a[i] << " ";
      puts("");
    }
  }
  return 0;
}
