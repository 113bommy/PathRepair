#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005], b[100005], pk = 1;
long long ans = 1;
int u(int nu, int de) { return (nu + de) / de; }
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (2); i <= (k); i++) pk *= 10;
  for (int i = (1); i <= (n / k); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (n / k); i++) scanf("%d", &b[i]);
  for (int i = (1); i <= (n / k); i++) {
    long long mul = u(10 * pk - 1, a[i]) - u((b[i] + 1) * pk - 1, a[i]) +
                    u(b[i] * pk - 1, a[i]);
    ans = ans * mul % 1000000007;
  }
  printf("%lld\n", (ans + 1000000007) % 1000000007);
  return 0;
}
