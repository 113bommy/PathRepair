#include <bits/stdc++.h>
using namespace std;
int dx[6] = {0, 0, 1, -1};
int dy[6] = {1, -1, 0, 0};
const long long mod = 1e9 + 7;
const int L = 1e5 + 10;
int T;
int n, m;
int sum[L];
int main() {
  int i, j;
  long long x, y;
  int ns, ans, t;
  while (~scanf("%d%d", &n, &m)) {
    sum[0] = 0;
    for (i = 1; i < n; i++) {
      scanf("%d", &t);
      sum[i] = sum[i - 1] + t;
    }
    ans = 0x3f3f3f3f;
    for (i = 1; i < n - m; i++) ans = min(ans, sum[i + m] - sum[i]);
    printf("%d\n", ans);
  }
  return 0;
}
