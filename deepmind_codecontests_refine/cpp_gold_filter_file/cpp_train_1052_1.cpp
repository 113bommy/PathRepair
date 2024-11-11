#include <bits/stdc++.h>
using namespace std;
long long num[200010];
int main() {
  long long n, k;
  long long ans = 0;
  scanf("%I64d%I64d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%I64d", &num[i]);
  for (int i = 1; i <= n; i++) {
    int tmp = (num[i] + num[i - 1]) / k;
    if ((num[i] + num[i - 1]) % k <= num[i] && i != n) {
      num[i] = (num[i] + num[i - 1]) % k;
    } else if ((num[i] + num[i - 1]) % k > 0) {
      num[i] = 0;
      tmp++;
    }
    ans += tmp;
  }
  printf("%I64d\n", ans);
  return 0;
}
