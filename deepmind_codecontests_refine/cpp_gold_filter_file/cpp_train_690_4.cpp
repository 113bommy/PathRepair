#include <bits/stdc++.h>
using namespace std;
long long Min[1200010], Min_pos[1200010];
long long ans_S2[300010];
long long n, x1, x2;
struct ss {
  long long val, id;
} c[300010];
bool cmp(ss a, ss b) { return a.val < b.val; }
void builine(int, int, int);
long long GET_(int, int, int, int, int);
int GET_pos(int, int, int, int, int);
int main() {
  int i, j, k;
  long long an, ann;
  scanf("%lld%lld%lld", &n, &x1, &x2);
  for (i = 1; i <= n; i++) scanf("%lld", &c[i].val), c[i].id = i;
  sort(c + 1, c + n + 1, cmp);
  for (i = 1; i <= n; i++)
    if (x2 / c[i].val + ((x2 % c[i].val) != 0) <= n - i + 1)
      ans_S2[i] = x2 / c[i].val + ((x2 % c[i].val) != 0);
    else
      ans_S2[i] = n + 1 + i;
  builine(1, n, 1);
  for (i = 1; i <= n; i++) {
    an = x1 / c[i].val + ((x1 % c[i].val) != 0);
    if (an <= n - i + 1) {
      if (GET_(1, n, 1, i + an, n) <= n) {
        printf("Yes\n");
        j = GET_pos(1, n, 1, i + an, n);
        printf("%lld %lld\n", an, x2 / c[j].val + ((x2 % c[j].val) != 0));
        for (k = 0; k < an; k++) printf("%d ", c[k + i].id);
        printf("\n");
        an = x2 / c[j].val + ((x2 % c[j].val) != 0);
        for (k = 0; k < an; k++) printf("%d ", c[k + j].id);
        return 0;
      }
      if (GET_(1, n, 1, 1, i - 1) <= n - an) {
        printf("Yes\n");
        j = GET_pos(1, n, 1, 1, i - 1);
        printf("%lld %lld\n", an, x2 / c[j].val + ((x2 % c[j].val) != 0));
        for (k = 0; k < an; k++) printf("%d ", c[k + i].id);
        printf("\n");
        ann = x2 / c[j].val + ((x2 % c[j].val) != 0);
        for (k = 0; k < ann && k + j < i; k++) printf("%d ", c[k + j].id);
        for (; k < ann; k++) printf("%d ", c[k + j + an].id);
        return 0;
      }
    }
  }
  printf("No\n");
  return 0;
}
void builine(int l, int r, int nu) {
  if (l == r) {
    Min[nu] = ans_S2[l] + l - 1, Min_pos[nu] = l;
    return;
  }
  int mid = (l + r) >> 1;
  builine(l, mid, nu << 1);
  builine(mid + 1, r, nu << 1 | 1);
  Min[nu] = min(Min[nu << 1], Min[nu << 1 | 1]);
  if (Min[nu << 1] < Min[nu << 1 | 1])
    Min_pos[nu] = Min_pos[nu << 1];
  else
    Min_pos[nu] = Min_pos[nu << 1 | 1];
}
long long GET_(int l, int r, int nu, int L, int R) {
  if (L > R) return n + 1;
  if (L <= l && r <= R) return Min[nu];
  int mid = (l + r) >> 1, lm = n + 1, rm = n + 1;
  if (L <= mid) lm = GET_(l, mid, nu << 1, L, R);
  if (R > mid) rm = GET_(mid + 1, r, nu << 1 | 1, L, R);
  if (lm < rm) return lm;
  return rm;
}
int GET_pos(int l, int r, int nu, int L, int R) {
  if (L > R) return n + 1;
  if (L <= l && r <= R) return Min_pos[nu];
  int mid = (l + r) >> 1, lm = 0, rm = 0;
  if (L <= mid) lm = GET_pos(l, mid, nu << 1, L, R);
  if (R > mid) rm = GET_pos(mid + 1, r, nu << 1 | 1, L, R);
  if (!lm || !rm) return lm + rm;
  if (ans_S2[lm] + lm - 1 < ans_S2[rm] + rm - 1) return lm;
  return rm;
}
