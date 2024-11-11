#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 7;
int n, a[maxn];
int f[maxn] = {0}, g[maxn] = {0};
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) f[i] = f[i - 1] + (a[i] == 1);
  for (int i = n; i > 0; --i) g[i] = g[i + 1] + (a[i] == 2);
  int ans = 0;
  for (int mid = 1; mid <= n; ++mid) {
    int t1 = 0, t2 = 0;
    for (int i = 1; i <= mid; ++i) {
      t1 = max(t1, f[i] + g[i] - g[mid]);
    }
    for (int i = mid; i <= n; ++i) {
      t2 = max(t2, f[i] - f[mid - 1] + g[i]);
    }
    ans = max(ans, t1 + t2);
  }
  printf("%d", ans);
  return 0;
}
