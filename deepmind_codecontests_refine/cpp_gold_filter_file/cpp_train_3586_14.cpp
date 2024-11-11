#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
long long f(long long x, int n, int m) {
  long long res = 0;
  --x;
  for (int i = 1; i <= n; ++i) res += min((long long)m, x / i);
  return res;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long l = 1, r = 1LL * n * m + 1, x;
  while (l < r) {
    x = (l + r) >> 1;
    if (f(x, n, m) < k)
      l = x + 1;
    else
      r = x;
  }
  cout << l - 1 << endl;
  return 0;
}
