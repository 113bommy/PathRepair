#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 1005;
int n, m;
int id[N];
double sum[2][N * M];
int main() {
  cin >> n >> m;
  if (m == 1) {
    printf("%.15f\n", 1.0);
    return 0;
  }
  int tot = 0;
  for (int i = 1; i <= n; ++i) cin >> id[i], tot += id[i];
  int cur = 1;
  for (int i = 0; i <= tot; ++i) sum[cur][i] = 1;
  for (int i = 1; i <= n; ++i) {
    cur ^= 1;
    memset(sum[cur], 0, sizeof(sum[cur]));
    for (int j = 1; j <= tot; ++j) {
      double k = 0;
      k += sum[cur ^ 1][j - 1];
      if (j - m - 1 >= 0) k -= sum[cur ^ 1][j - m - 1];
      if (j > id[i]) k -= sum[cur ^ 1][j - id[i]] - sum[cur ^ 1][j - id[i] - 1];
      if (j == id[i]) k -= sum[cur ^ 1][j - id[i]];
      k /= m - 1;
      sum[cur][j] = sum[cur][j - 1] + k;
    }
  }
  double ans = sum[cur][tot - 1];
  printf("%.15f", ans * (m - 1) + 1.0);
  return 0;
}
