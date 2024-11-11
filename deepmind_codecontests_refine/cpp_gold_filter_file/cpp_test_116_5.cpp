#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
const int MOD = 998244353;
long long d[MAX][2];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) d[i][0] = d[i][1] = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      d[x][0] = (d[x][0] * 2 + (x == 0) + (x ? d[x - 1][0] : 0)) % MOD;
      d[x][1] = ((x >= 2 ? d[x - 2][0] : 0) + 2 * d[x][1] + (x == 1)) % MOD;
      d[x + 2][1] = d[x + 2][1] * 2 % MOD;
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + d[i][0] + d[i][1]) % MOD;
    printf("%lld\n", ans);
  }
}
