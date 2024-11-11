#include <bits/stdc++.h>
using namespace std;
long long ans, mod = 1000000007;
int n, m;
int mypow(int x, long long times) {
  if (times == 0) return 1;
  if (times == 1) return x;
  long long ret = mypow(x, times / 2);
  ret = ret * ret % mod;
  if (times % 2) ret = ret * x % mod;
  return ret;
}
int main() {
  cin >> n >> m;
  ans = mypow(m, n);
  for (int i = 0; i < n; i++)
    ans = (ans + 1ll * mypow(m, n - i) * mypow(2 * m - 1, i)) % mod;
  cout << ans;
}
