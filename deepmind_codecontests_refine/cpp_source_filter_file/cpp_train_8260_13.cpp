#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], v[N * 10], ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    int x = a[i], y = 0;
    if (!v[x]) v[x] = 1, ans++;
    for (int j = i + 1; j <= n; ++j) {
      x = x | a[j];
      y = y | a[j];
      if (x == y) break;
      if (!v[x]) v[x] = 1, ans++;
    }
  }
  printf("%d", ans);
  return 0;
}
