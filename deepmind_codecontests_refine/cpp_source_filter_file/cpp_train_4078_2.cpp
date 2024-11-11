#include <bits/stdc++.h>
using namespace std;
long long modpower(long long n, long long k) {
  long long res = 1;
  while (k > 0) {
    if (k & 1) res = (res * n) % 998244353;
    k >>= 1;
    n = (n * n) % 998244353;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long ans = modpower(n, n + m);
  cout << ans;
}
