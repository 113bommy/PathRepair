#include <bits/stdc++.h>
using namespace std;
int a[105];
int n, d;
int m;
int main() {
  while (scanf("%d %d", &n, &d) != EOF) {
    int i;
    for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &m);
    sort(a + 1, a + n + 1);
    int sum = 0;
    if (n >= m)
      for (i = 1; i <= m; ++i) sum += a[i];
    else {
      for (i = 1; i <= n; ++i) sum += a[i];
      int ans = (m - n) * d;
      sum = sum - ans;
    }
    printf("%d\n", sum);
  }
  return 0;
}
