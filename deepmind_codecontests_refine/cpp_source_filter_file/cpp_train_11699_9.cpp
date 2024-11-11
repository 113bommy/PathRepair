#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, MOD = 998244353;
int n, m, k;
int main() {
  cin >> n >> m >> k;
  if (n - m <= -k - 1) return 0 * printf("0\n");
  if (k + 1 >= m) return 0 * printf("1\n");
  double ans = 1;
  for (int i = 0; i <= k; i++) ans = ans * (m - i) / (n + i + 1);
  printf("%.8lf\n", 1 - ans);
  return 0;
}
