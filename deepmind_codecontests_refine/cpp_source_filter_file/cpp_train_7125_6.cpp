#include <bits/stdc++.h>
using namespace std;
int a[100005], dp1[100005], dp2[100005], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i > 0; --i)
    if (a[i] < a[i + 1])
      dp1[i] = 1 + dp1[i + 1];
    else
      dp1[i] = 1;
  for (int i = 1; i <= n; ++i)
    if (a[i] > a[i - 1])
      dp2[i] = 1 + dp2[i - 1];
    else
      dp2[i] = 1;
  int mx = 1;
  if (n - 1) mx = 2;
  a[n + 1] = 1 << 30;
  for (int i = 1; i <= n; ++i) {
    if (a[i - 1] < a[i + 1]) mx = max(mx, dp2[i - 1] + 1 + dp1[i + 1]);
    mx = max(mx, max(dp2[i - 1] + 1, dp1[i + 1] + 1));
  }
  printf("%d\n", mx);
}
