#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
int n, m, k;
long long pw(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = (ans * a) % M;
    a = (a * a) % M;
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  long long ans = 1;
  if (k > n || k == 1) {
    ans = pw(m * 1LL, n * 1LL);
  } else if (k == n)
    ans = pw(1LL * m, 1LL * (n + 1) / 2);
  else {
    if (k % 2 == 0)
      ans = m;
    else
      k = m * m % M;
  }
  printf("%I64d", ans);
  return 0;
}
