#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    long long ans = 2 * m, cnt = 1;
    for (int i = 2; i <= n; i++) {
      cnt = (cnt * m) % mod;
      ans = (ans * (2 * m - 1) + cnt) % mod;
    }
    printf("%I64d", ans);
    printf("\n");
    ;
  }
}
