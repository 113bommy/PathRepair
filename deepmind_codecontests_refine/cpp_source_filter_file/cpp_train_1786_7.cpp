#include <bits/stdc++.h>
using namespace std;
int x[100005], y[100005];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int ans = 0, a;
  for (int i = 1; i <= n; i++) x[i] = k + 1;
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a);
    x[a] = min(x[a], i);
    y[a] = max(y[a], i);
  }
  for (int i = 1; i <= n; i++) ans += !y[i];
  for (int i = 1; i < n; i++)
    if (x[i] >= y[i - 1]) ans++;
  for (int i = 1; i < n; i++)
    if (x[i + 1] >= y[i]) ans++;
  printf("%d\n", ans);
  return 0;
}
