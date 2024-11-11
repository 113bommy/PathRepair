#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int h, t;
int q[50000];
int dq;
int ans[50000];
int flag;
int sum;
int a, b, c;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  h = 1;
  t = 0;
  sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d:%d:%d", &a, &b, &c);
    dq = a * 3600 + b * 60 + c;
    while (h <= t && q[h] < dq) ++h;
    if (t - h + 1 < m)
      q[++t] = dq + k - 1, ans[i] = ++sum;
    else
      q[++t] = dq + k - 1, ans[i] = sum;
    if (t - h + 1 == m) flag = 1;
  }
  if (flag == 0)
    printf("No solution\n");
  else {
    printf("%d\n", sum);
    for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
  }
  return 0;
}
