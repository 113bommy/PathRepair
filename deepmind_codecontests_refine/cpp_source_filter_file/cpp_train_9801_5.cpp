#include <bits/stdc++.h>
using namespace std;
const int N = 355000;
const int SQRTN = 320;
const int LOGN = 20;
const long double PI = acos(-1);
unsigned long long n, a[N], m, q, sum[N], ans;
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }
  sort(a + 1, a + n);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  cin >> m;
  while (m--) {
    scanf("%lld", &q);
    q = n - q;
    ans = sum[n] - a[q + 1];
    printf("%lld\n", ans);
  }
}
