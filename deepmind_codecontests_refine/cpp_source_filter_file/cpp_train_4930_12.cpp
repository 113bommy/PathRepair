#include <bits/stdc++.h>
using namespace std;
int l[1000005], r[1000005], stk[1000005];
long long a[1000005], ans[1000005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  int top = 0;
  stk[top++] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[stk[top - 1]] >= a[i]) {
      r[stk[top - 1]] = i;
      top--;
    }
    l[i] = stk[top - 1];
    stk[top++] = i;
  }
  while (top > 1) {
    int i = stk[--top];
    r[i] = n + 1;
  }
  for (int i = 1; i <= n; i++) {
    ans[1] += a[i];
    ans[i - l[i] + 1] -= a[i];
    ans[r[i] - i + 1] -= a[i];
    ans[r[i] - l[i] + 1] += a[i];
  }
  for (int k = 0; k < 2; k++) {
    for (int i = 2; i <= n; i++) ans[i] += ans[i - 1];
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%.15f\n", (double)ans[x] / (n - x + 1));
  }
}
