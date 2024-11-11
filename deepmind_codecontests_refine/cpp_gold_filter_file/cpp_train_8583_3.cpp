#include <bits/stdc++.h>
using namespace std;
long long int num[100005];
long long int h[100005];
int lh;
int n, d;
void geth() {
  lh = 1;
  for (int i = 0; i < n; i++) h[i] = num[i];
  sort(h, h + n);
  for (int i = 1; i < n; i++)
    if (h[i] != h[i - 1]) h[lh++] = h[i];
}
int getmh(long long int x, int kind) {
  int sta = 0;
  int end = lh - 1;
  int mid;
  if (kind == 0 || kind == 1) {
    while (sta <= end) {
      mid = (sta + end) / 2;
      if (h[mid] <= x)
        sta = mid + 1;
      else
        end = mid - 1;
    }
    return end;
  } else {
    while (sta <= end) {
      mid = (sta + end) / 2;
      if (h[mid] >= x)
        end = mid - 1;
      else
        sta = mid + 1;
    }
    return sta;
  }
  return -1;
}
struct tree {
  int l, r, m, who;
} tr[100005 * 4];
void buildtr(int l, int r, int rt) {
  tr[rt].l = l;
  tr[rt].r = r;
  tr[rt].m = 0, tr[rt].who = -1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  buildtr(l, mid, rt << 1);
  buildtr(mid + 1, r, rt << 1 | 1);
}
void add(int rt, int x, int w, int num) {
  if (tr[rt].l > x || tr[rt].r < x) return;
  if (tr[rt].l == tr[rt].r) {
    if (tr[rt].m < num) {
      tr[rt].m = num;
      tr[rt].who = w;
    }
    return;
  }
  add(rt << 1, x, w, num);
  add(rt << 1 | 1, x, w, num);
  if (tr[rt << 1].m >= tr[rt << 1 | 1].m) {
    tr[rt].m = tr[rt << 1].m;
    tr[rt].who = tr[rt << 1].who;
  } else {
    tr[rt].m = tr[rt << 1 | 1].m;
    tr[rt].who = tr[rt << 1 | 1].who;
  }
}
void get_m_who(int &ansm, int &answ, int rt, int l, int r) {
  if (tr[rt].l > r || tr[rt].r < l) return;
  if (tr[rt].l >= l && tr[rt].r <= r) {
    if (ansm < tr[rt].m) {
      ansm = tr[rt].m;
      answ = tr[rt].who;
    }
    return;
  }
  get_m_who(ansm, answ, rt << 1, l, r);
  get_m_who(ansm, answ, rt << 1 | 1, l, r);
}
int who[100005];
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) scanf("%I64d", &num[i]);
  geth();
  buildtr(0, lh, 1);
  int mm = 0, ww = -1;
  for (int i = n - 1; i >= 0; i--) {
    int m = 0, w = -1;
    int H = getmh(num[i], 0);
    int h1 = getmh(num[i] - d, 1);
    int h2 = getmh(num[i] + d, 2);
    if (h1 >= 0) get_m_who(m, w, 1, 0, h1);
    if (h2 < lh) get_m_who(m, w, 1, h2, lh);
    who[i] = w;
    if (mm < m + 1) {
      mm = m + 1;
      ww = i;
    }
    add(1, H, i, m + 1);
  }
  printf("%d\n", mm);
  while (ww != -1) {
    printf("%d ", ww + 1);
    ww = who[ww];
  }
  printf("\n");
}
