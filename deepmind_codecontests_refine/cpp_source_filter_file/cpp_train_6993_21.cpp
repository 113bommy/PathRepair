#include <bits/stdc++.h>
int n, q, a[100005], L[100005], R[100005], cnt[100005];
int solve(int l, int r) {
  if (l > r) return 0;
  int lm = 0, mx = 0;
  for (int i = l; i <= r; ++i) {
    lm = std::max(lm, R[a[i]]);
    mx = std::max(mx, cnt[a[i]]);
    if (lm == i) return mx + solve(i + 1, r);
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    R[a[i]] = i;
  }
  printf("%d", n - solve(1, n));
  return 0;
}
