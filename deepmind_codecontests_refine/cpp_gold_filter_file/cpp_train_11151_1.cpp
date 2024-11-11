#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m;
char a[200005], b[200005];
int sum[200005], cnt[200005];
long long pw[200005];
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s%s", a, b);
  pw[0] = 1LL;
  for (int i = 1; i <= max(n, m); i++) {
    pw[i] = (pw[i - 1] * 2LL) % MOD;
  }
  reverse(a, a + n);
  reverse(b, b + m);
  for (int i = m - 1; i >= 0; i--) {
    sum[i] = sum[i + 1] + (b[i] == '1');
  }
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == '1') {
      res = (res + pw[i] * sum[i]) % MOD;
    }
  }
  printf("%lld\n", res);
}
