#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000005], sum[1000005];
double stk[1000005];
int num[1000005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
  int top = 0;
  for (int i = 1; i <= n; i++) {
    stk[++top] = a[i];
    num[top] = 1;
    while (top > 1 && stk[top] <= stk[top - 1]) {
      top--;
      stk[top] = (stk[top] * num[top] + stk[top + 1] * num[top + 1]) /
                 (num[top] + num[top + 1]);
      num[top] = num[top] + num[top + 1];
    }
  }
  int cur = 0;
  for (int i = 1; i <= top; i++) {
    for (int j = cur + 1; j <= cur + num[i]; j++) printf("%.10lf\n", stk[i]);
    cur += num[i];
  }
  return 0;
}
