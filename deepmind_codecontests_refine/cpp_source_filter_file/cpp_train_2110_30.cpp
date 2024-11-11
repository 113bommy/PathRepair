#include <bits/stdc++.h>
using namespace std;
long long int binpowmod(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return binpowmod(n, p - 2, p);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, i, f = 0, j, ans = 0, l, r, k, t1, t2, x, y, cnt, n, m;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; ++i) cout << i << " ";
    cout << endl;
  }
  return 0;
}
