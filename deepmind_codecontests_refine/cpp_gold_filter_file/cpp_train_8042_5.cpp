#include <bits/stdc++.h>
using namespace std;
long long int powm(long long int x, long long int y,
                   long long int m = 1000000007) {
  x = x % m;
  long long int res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long int modi(long long int a, long long int m = 1000000007) {
  return powm(a, m - 2, m);
}
void pre() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  pre();
  long long int test;
  cin >> test;
  while (test--) {
    long long int n;
    cin >> n;
    long long int ct = n / 4;
    if (n % 4 != 0) ct++;
    long long int rm = n - ct;
    while (rm > 0) {
      cout << 9;
      rm--;
    }
    while (ct--) cout << 8;
    cout << endl;
  }
  return 0;
}
