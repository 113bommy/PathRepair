#include <bits/stdc++.h>
using namespace std;
int n, m;
long long k, l, r, mid, res;
inline bool judge(const long long& M) {
  static long long res;
  res = 0;
  for (int i = 1; i <= n; ++i) res += min((long long)m, (M - 1) / i);
  return res <= k;
}
int main(void) {
  cin >> n >> m >> k;
  l = 1, r = 1LL * n * m;
  --k;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (judge(mid))
      l = mid + 1, res = mid;
    else
      r = mid - 1;
  }
  cout << res;
  return 0;
}
