#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265358979323846;
long long binpow(long long a, long long b) {
  long long res = 1;
  a %= (long long)(1e9 + 7);
  while (b) {
    if (b & 1) res = res * a % (long long)(1e9 + 7);
    a = a * a % (long long)(1e9 + 7);
    b >>= 1;
  }
  return res;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  long long res = y % 2 ? y / 2 + 1 : (x / 2 - y / 2 + 1);
  cout << res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long tt = 1, el = 0;
  while (tt--) {
    solve();
  }
  return 0;
}
