#include <bits/stdc++.h>
using namespace std;
long long p2(long long a) {
  long long b = 2, ans = 1;
  while (a > 0) {
    if (a % 2 == 1) ans = (ans * 1LL * b) % 1000000007;
    a /= 2;
    b = (b * 1LL * b) % 1000000007;
  }
  return ans;
}
int main() {
  int n, m, k;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  long long gap = n - m;
  long long block = m / k, rem = m % k, impb = 0, add;
  while (gap > 0 && block != 0) {
    if (block >= gap)
      add = gap;
    else
      add = block;
    impb += add;
    block -= add;
    rem += add;
    gap -= add;
    block += rem / k;
    rem = rem % k;
  }
  long long ans = ((p2(block) - 1) * 2LL * k) % 1000000007;
  ans = (ans + rem + (impb * 1LL * (k - 1)) % 1000000007) % 1000000007;
  cout << ans << endl;
  return 0;
}
