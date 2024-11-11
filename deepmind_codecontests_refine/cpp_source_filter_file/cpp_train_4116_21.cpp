#include <bits/stdc++.h>
using namespace std;
const int M = 1000001;
int n, m, k, p, a[M];
struct vv {
  int a[6], b[6];
  int sz, tag;
} t[M], ans;
vv mrg(vv x, vv y) {
  vv a = y;
  a.tag = 0;
  for (int i = 0; i < x.sz; i++) {
    int B = 0;
    for (int j = 0; j < a.sz; j++)
      if (a.a[j] == x.a[i]) {
        a.b[j] += x.b[i];
        B = 1;
        break;
      }
    if (!B) {
      if (a.sz < p) {
        a.a[a.sz] = x.a[i];
        a.b[a.sz] = x.b[i];
        a.sz++;
        continue;
      }
      int mn = 0x3f3f3f3f, fr = 0;
      for (int j = 0; j < a.sz; j++)
        if (mn > a.b[j]) mn = a.b[j], fr = j;
      if (mn > x.b[i]) {
        for (int j = 0; j < a.sz; j++) a.b[j] -= x.b[i];
        continue;
      }
      for (int j = 0; j < a.sz; j++) a.b[j] -= mn;
      a.b[fr] = x.b[i] - mn + 1;
      a.a[fr] = x.a[i];
    }
  }
  return a;
}
void build(int now, int l, int r) {
  if (l == r) {
    t[now].a[0] = a[l];
    t[now].b[0] = 1;
    t[now].sz = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(now * 2, l, mid);
  build(now * 2 + 1, mid + 1, r);
  t[now] = mrg(t[now * 2], t[now * 2 + 1]);
}
void down(int now, int l, int r, int k) {
  t[now].sz = 1;
  t[now].a[0] = k;
  t[now].b[0] = r - l + 1;
  t[now].tag = k;
}
void pd(int now, int l, int r) {
  if (!t[now].tag) return;
  int mid = (l + r) >> 1;
  down(now * 2, l, mid, t[now].tag);
  down(now * 2 + 1, mid + 1, r, t[now].tag);
  t[now].tag = 0;
}
void mody(int now, int l, int r, int L, int R, int k) {
  if (L <= l && r <= R) {
    down(now, l, r, k);
    return;
  }
  int mid = (l + r) >> 1;
  pd(now, l, r);
  if (L <= mid) mody(now * 2, l, mid, L, R, k);
  if (R > mid) mody(now * 2 + 1, mid + 1, r, L, R, k);
  t[now] = mrg(t[now * 2], t[now * 2 + 1]);
}
void ask(int now, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    ans = mrg(ans, t[now]);
    return;
  }
  int mid = (l + r) >> 1;
  pd(now, l, r);
  if (L <= mid) ask(now * 2, l, mid, L, R);
  if (R > mid) ask(now * 2 + 1, mid + 1, r, L, R);
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  p = 100 / p;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  for (; m; m--) {
    int op, l, r, k;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      scanf("%d", &k);
      mody(1, 1, n, l, r, k);
    } else {
      ans.sz = 0;
      ask(1, 1, n, l, r);
      printf("%d ", ans.sz);
      for (int i = 0; i < ans.sz; i++) printf("%d ", ans.a[i]);
      printf("\n");
    }
  }
}
