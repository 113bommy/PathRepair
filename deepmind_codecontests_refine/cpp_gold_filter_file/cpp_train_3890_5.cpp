#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 922337203685477;
const long long mininf = -922337203685477;
const long long nax = 0;
long long n, m;
long long pangkat(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  long long save = pangkat(x, y / 2) % m;
  if (y % 2 == 0) {
    long long ret = save * save;
    ret %= m;
    return ret;
  } else if (y % 2) {
    long long ret = save * save * x;
    ret %= m;
    return ret;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> m;
  if (n == 1) {
    cout << 2 % m << '\n';
    return 0;
  }
  long long ans = pangkat(3, n);
  ans %= m;
  ans--;
  ans = ((ans % m) + m) % m;
  cout << ans << '\n';
}
