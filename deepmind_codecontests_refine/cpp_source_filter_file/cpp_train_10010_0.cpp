#include <bits/stdc++.h>
const int M = 2e5 + 5;
int n, ans, a[M], L[M], R[M], pos[M];
int top, stk[M];
signed main() {
  register int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", a + i), pos[a[i]] = i;
  for (i = 1; i <= n; ++i) {
    while (top && a[i] > a[stk[top]]) --top;
    L[i] = stk[top] + 1;
    stk[++top] = i;
  }
  top = 0;
  for (i = n; i >= 1; --i) {
    while (top && a[i] > a[stk[top]]) --top;
    R[i] = stk[top] - 1;
    stk[++top] = i;
  }
  for (i = 1; i <= n; ++i) {
    if (!L[i]) L[i] = 1;
    if (!~R[i]) R[i] = n;
  }
  for (i = 1; i <= n; ++i) {
    if (i - L[i] >= R[i] - i) {
      for (j = i + 1; j <= R[i]; ++j)
        ans += L[i] <= pos[a[i] - a[j]] && pos[a[i] - a[j]] <= R[i];
    } else {
      for (j = L[i]; j <= i - 1; ++j)
        ans += L[i] <= pos[a[i] - a[j]] && pos[a[i] - a[j]] <= R[i];
    }
  }
  printf("%d", ans);
}
