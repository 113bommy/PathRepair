#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int Mod = 998244353;
int add(int a, int b) { return (a += b) >= Mod ? a - Mod : a; }
int sub(int a, int b) { return (a -= b) < 0 ? a + Mod : a; }
int mul(int a, int b) { return 1ll * a * b % Mod; }
int n, k, a[N], siz, cntblo;
int pre[N], lst[N], dp[N], f[N], sum[400][N], ans[400];
int tag[400], L[400], R[400], bel[N];
void rebuild(int id) {
  for (int i = L[id]; i <= R[id]; i++) {
    sum[id][f[i]] = 0;
    f[i] += tag[id];
  }
  tag[id] = ans[id] = 0;
  for (int i = L[id]; i <= R[id]; i++) {
    sum[id][f[i]] = add(sum[id][f[i]], dp[i]);
    if (f[i] <= k) {
      ans[id] = add(ans[id], dp[i]);
    }
  }
}
void update(int x, int vl) {
  int id = bel[x];
  sum[id][f[x]] = sub(sum[id][f[x]], dp[x]);
  if (f[x] <= k) {
    ans[id] = sub(ans[id], dp[x]);
  }
  f[x] += vl;
  sum[id][f[x]] = add(sum[id][f[x]], dp[x]);
  if (f[x] <= k) {
    ans[id] = add(ans[id], dp[x]);
  }
}
void modify(int l, int r, int vl) {
  if (l > r) {
    return;
  }
  if (bel[l] == bel[r]) {
    rebuild(bel[l]);
    for (int i = l; i <= r; i++) {
      update(i, vl);
    }
    return;
  }
  rebuild(bel[l]);
  for (int i = l; i <= R[bel[l]]; i++) {
    update(i, vl);
  }
  rebuild(bel[r]);
  for (int i = L[bel[r]]; i <= r; i++) {
    update(i, vl);
  }
  for (int id = bel[l] + 1; id < bel[r]; id++) {
    if (vl > 0) {
      ans[id] = sub(ans[id], sum[id][k - tag[id]]);
      ++tag[id];
    } else {
      --tag[id];
      ans[id] = add(ans[id], sum[id][k - tag[id]]);
    }
  }
}
int query(int x) {
  int res = 0;
  for (int i = 1; i < bel[x]; i++) {
    res = add(res, ans[i]);
  }
  for (int i = L[bel[x]]; i <= x; i++) {
    if (f[i] <= k) {
      res = add(res, dp[i]);
    }
  }
  return res;
}
int main() {
  scanf("%d %d", &n, &k);
  siz = sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pre[i] = lst[a[i]];
    lst[a[i]] = i;
    bel[i] = (i - 1) / siz + 1;
  }
  cntblo = bel[n];
  for (int i = 1; i <= cntblo; i++) {
    L[i] = R[i - 1] + 1;
    R[i] = min(n, L[i] + siz - 1);
  }
  dp[1] = 1;
  for (int i = 1; i <= n; i++) {
    modify(pre[i] + 1, i - 1, 1);
    modify(pre[pre[i]] + 1, pre[i], -1);
    dp[i + 1] = query(i);
    rebuild(bel[i]);
    update(i, 1);
  }
  printf("%d", dp[n + 1]);
  return 0;
}
