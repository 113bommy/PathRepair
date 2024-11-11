#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int MAX = 2e5 + 10;
const long long mod = 1e9 + 7;
int ans[MAX], a[MAX];
int main() {
  int n, m, i, x;
  while (~scanf("%d%d", &n, &m)) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (i = 0; i < m; i++) {
      scanf("%d", &x);
      ans[i] = lower_bound(a, a + n, x) - a;
    }
    printf("%d", ans[0]);
    for (i = 1; i < m; i++) {
      printf(" %d", ans[i]);
    }
    puts("");
  }
  return 0;
}
