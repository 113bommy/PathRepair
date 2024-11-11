#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400123;
const int MAXM = 400123;
const long long MO = 1e9 + 9;
long long f[MAXN], tree1[MAXN * 3], tree2[MAXN * 3], sum[MAXN], tree[MAXN * 3],
    a[MAXN];
int n, m, L, R;
void Init() {
  f[0] = 1;
  f[1] = 0;
  for (int i = 2; i < MAXN; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % MO;
  }
  for (int i = 1; i < MAXN; i++) {
    sum[i] = (sum[i - 1] + f[i + 1]) % MO;
  }
}
void change(int l, int r, int num) {
  if (l > R || r < L) return;
  if (L <= l && r <= R) {
    int k = l - L;
    tree1[num] = (tree1[num] + f[k + 1]) % MO;
    tree2[num] = (tree2[num] + f[k + 2]) % MO;
    tree[num] = (1LL * tree1[num] * sum[r - l] + tree2[num] * sum[r - l + 1] +
                 tree[num << 1] + tree[(num << 1) + 1]) %
                MO;
  } else {
    int m = (l + r) >> 1;
    change(l, m, num * 2);
    change(m + 1, r, num * 2 + 1);
    tree[num] = (1LL * tree1[num] * sum[r - l] + tree2[num] * sum[r - l + 1] +
                 tree[num << 1] + tree[(num << 1) + 1]) %
                MO;
  }
}
int find(int l, int r, int num) {
  if (l > R || r < L) return 0;
  if (L <= l && r <= R) {
    return tree[num];
  } else {
    int m = (l + r) >> 1;
    long long tmp = find(l, m, num << 1) + find(m + 1, r, num * 2 + 1);
    if (L > l)
      tmp += tree1[num] * (sum[min(r, R) - l] - sum[L - l - 1]) +
             tree2[num] * (sum[min(R, r) - l + 1] - sum[L - l]);
    else
      tmp += tree1[num] * (sum[R - max(l, L)]) +
             tree2[num] * (sum[R - max(L, l) + 1]);
    return tmp % MO;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &a[i]);
    a[i] = (a[i] + a[i - 1]) % MO;
    ;
  }
  Init();
  while (m--) {
    int k;
    scanf("%d%d%d", &k, &L, &R);
    if (k == 1) {
      change(1, n, 1);
    } else {
      long long tmp = find(1, n, 1);
      tmp += (a[R] - a[L - 1]) % MO + MO * MO;
      printf("%d\n", tmp % MO);
    }
  }
  return 0;
}
