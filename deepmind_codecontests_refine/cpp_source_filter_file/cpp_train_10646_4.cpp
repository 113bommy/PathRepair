#include <bits/stdc++.h>
using namespace std;
int st[300000];
int revers[30], sp[30];
void modify(int level, int ind, int l, int r, int pos, int val, int swap) {
  if (l == r) {
    st[ind] = val;
    return;
  }
  int mid = (l + r) >> 1;
  swap ^= revers[level];
  if (pos <= mid)
    modify(level - 1, (ind << 1) ^ swap ^ sp[level], l, mid, pos, val, swap);
  else
    modify(level - 1, (ind << 1 | 1) ^ swap ^ sp[level], mid + 1, r, pos, val,
           swap);
  st[ind] = st[ind << 1] + st[ind << 1 | 1];
}
long long ask(int level, int ind, int l, int r, int ll, int rr, int swap) {
  if (ll <= l && r <= rr) {
    return st[ind];
  }
  long long ret = 0;
  int mid = (l + r) >> 1;
  swap ^= revers[level];
  if (ll <= mid)
    ret += ask(level - 1, (ind << 1) ^ swap ^ sp[level], l, mid, ll, rr, swap);
  if (mid < rr)
    ret += ask(level - 1, (ind << 1 | 1) ^ swap ^ sp[level], mid + 1, r, ll, rr,
               swap);
  return ret;
}
int n, q;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= (1 << n); ++i) {
    int x;
    scanf("%d", &x);
    modify(n, 1, 1, 1 << n, i, x, 0);
  }
  for (int i = 1, t; i <= q; ++i) {
    scanf("%d", &t);
    if (t == 1) {
      int x, k;
      scanf("%d%d", &x, &k);
      modify(n, 1, 1, 1 << n, x, k, 0);
    } else if (t == 2) {
      int k;
      scanf("%d", &k);
      revers[k] ^= 1;
    } else if (t == 3) {
      int k;
      scanf("%d", &k);
      sp[k + 1] ^= 1;
    } else if (t == 4) {
      int l, r;
      scanf("%d%d", &l, &r);
      cout << ask(n, 1, 1, 1 << n, l, r, 0) << '\n';
    }
  }
}
