#include <bits/stdc++.h>
using namespace std;
int cal(char x) {
  if (x == 'A') return 0;
  if (x == 'T') return 1;
  if (x == 'G') return 2;
  return 3;
}
char ch(int x) {
  if (x == 0) return 'A';
  if (x == 1) return 'T';
  if (x == 2) return 'G';
  return 'C';
}
char s[110000];
int q, n;
int nu[11] = {0, 1, 2, 4, 7, 11, 16, 22, 29, 37, 45};
struct seg {
  struct node {
    int l, r;
    int sum[56][4];
  } tr[330000];
  void update(int kk) {
    for (int i = 0; i <= 55; i++)
      for (int k = 0; k < 4; k++)
        tr[kk].sum[i][k] = tr[kk << 1].sum[i][k] + tr[kk << 1 | 1].sum[i][k];
  }
  void upd(int k, int l, int x, int f) {
    for (int i = 1; i <= 10; i++) tr[k].sum[nu[i] + l % i][x] += f;
  }
  void build(int k, int l, int r) {
    tr[k].l = l, tr[k].r = r;
    if (l == r) {
      upd(k, l, cal(s[l]), 1);
      return;
    }
    int mid = (l + r) / 2;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    update(k);
  }
  void change(int k, int a, int b) {
    int l = tr[k].l, r = tr[k].r;
    upd(k, a, cal(s[a]), -1);
    upd(k, a, b, 1);
    if (l == r) return;
    int mid = (l + r) / 2;
    if (a <= mid)
      change(k << 1, a, b);
    else
      change(k << 1 | 1, a, b);
  }
  int ask(int k, int a, int b, int c, int d, int e) {
    int l = tr[k].l, r = tr[k].r;
    if (a == l && b == r) return tr[k].sum[nu[c] + d][e];
    int mid = (l + r) / 2;
    if (b <= mid)
      return ask(k << 1, a, b, c, d, e);
    else if (a > mid)
      return ask(k << 1 | 1, a, b, c, d, e);
    else
      return ask(k << 1, a, mid, c, d, e) +
             ask(k << 1 | 1, mid + 1, b, c, d, e);
  }
} T;
char t[1100000];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  T.build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    int op, l, r, x;
    char c;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d %c", &x, &c);
      T.change(1, x, cal(c));
      s[x] = c;
    } else {
      scanf("%d %d", &l, &r);
      scanf("%s", t);
      int ll = strlen(t);
      int ans = 0;
      for (int i = 0; i < ll; i++)
        ans += T.ask(1, l, r, ll, (i + l) % ll, cal(t[i]));
      printf("%d\n", ans);
    }
  }
  return 0;
}
