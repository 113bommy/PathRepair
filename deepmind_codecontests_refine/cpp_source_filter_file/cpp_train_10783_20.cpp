#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e5 + 100, mod = 1e9 + 7;
long long n, m;
long long bs(long long l, long long r) {
  if (l >= r) return l;
  long long mid = (l + r) / 2;
  if (mid * (mid + 1) / 2 >= n - m)
    return bs(l, mid);
  else
    return bs(mid + 1, r);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (m >= n) return cout << n, 0;
  cout << bs(0, 1e9) + m;
}
