#include <bits/stdc++.h>
int n, m, p;
struct stType {
  int lp, rp;
  int cnt;
} st[2000005];
int cntST;
int nxt[100005], head[100005];
int a[100005];
int preK[100005];
int pointer[100005];
int ans;
void add_st(int& x, int l, int r, int p) {
  st[++cntST] = st[x];
  x = cntST;
  st[x].cnt++;
  if (l == r) return;
  if (p <= ((l + r) >> 1))
    add_st(st[x].lp, l, ((l + r) >> 1), p);
  else
    add_st(st[x].rp, ((l + r) >> 1) + 1, r, p);
}
void standing_by() {
  int i, j, k;
  scanf("%d%d", &n, &p);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    nxt[i] = head[a[i]];
    head[a[i]] = i;
  }
  for (i = 1; i <= n; i++) {
    for (j = head[i], k = 1; j && k <= p; j = nxt[j], k++)
      ;
    for (k = head[i]; j; j = nxt[j], k = nxt[k]) preK[k] = j;
  }
  for (i = 1; i < 100005; i++) {
    pointer[i] = pointer[i - 1];
    if (preK[i]) add_st(pointer[i], 1, n, preK[i]);
  }
}
int sum_st(int x, int l, int r, int L, int R) {
  if (x == 0 || r < L || l > R || st[x].cnt == 0) return 0;
  if (l >= L && r <= R) return st[x].cnt;
  return sum_st(st[x].lp, l, ((l + r) >> 1), L, R) +
         sum_st(st[x].rp, ((l + r) >> 1) + 1, r, L, R);
}
void complete() {
  int i;
  int l, r;
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &l, &r);
    l = ((l + ans) % n) + 1;
    r = ((r + ans) % n) + 1;
    if (l > r) l ^= r ^= l ^= r;
    ans = r - l + 1 - sum_st(pointer[r], 1, n, l, r);
    printf("%d\n", ans);
  }
}
int main() {
  standing_by();
  complete();
  return 0;
}
