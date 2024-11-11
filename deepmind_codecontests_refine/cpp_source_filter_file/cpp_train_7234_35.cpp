#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x[100002], ans = 0;
  scanf("%d", &n);
  x[0] = x[n + 1] = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++)
    x[i] = min(x[i], min(x[i + 1] + 1, x[i - 1] + 1));
  for (int i = n - 1; i > 1; i--) {
    x[i] = min(x[i], min(x[i + 1] + 1, x[i - 1] + 1));
    ans = max(x[i], ans);
  }
  printf("%d\n", ans);
  return 0;
}
