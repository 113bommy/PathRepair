#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long power(long long x, long long y) {
  long long ans = 1;
  for (int i = 1; i <= y; i++) ans = ans * x % mod;
  return ans;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long res;
  if (k == 1)
    res = power(m, n);
  else if (k == n) {
    if (k % 2 == 0)
      res = power(m, n / 2);
    else
      res = power(m, n / 2 + 1);
  } else {
    if (k % 2 == 0)
      res = m;
    else
      res = power(m, 2);
  }
  cout << res << endl;
}
