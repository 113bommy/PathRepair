#include <bits/stdc++.h>
using namespace std;
int a[102400], pre[102400], pre2[102400];
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  pre[0] = a[0];
  for (int i = 1; i < n; i++) pre[i] = max(pre[i - 1], a[i]);
  pre2[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) pre2[i] = min(pre2[i + 1], a[i]);
  for (int i = 0; i < n - 1; i++) ans += pre[i] <= pre2[i + 1];
  printf("%d\n", ans);
  return 0;
}
