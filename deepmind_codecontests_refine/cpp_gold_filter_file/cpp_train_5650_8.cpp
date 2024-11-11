#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f;
const int maxn = 1e5 + 10;
const int mod = 998244353;
int x, y, z, idx, mx, mi, m, n, t, k, tot, cnt, sum, flag, res;
int main() {
  scanf("%d", &t);
  while (t--) {
    sum = 0;
    mx = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      sum += x;
      mx = max(mx, x);
    }
    if (mx > sum - mx || (sum & 1)) {
      puts("T");
    } else {
      puts("HL");
    }
  }
  return 0;
}
