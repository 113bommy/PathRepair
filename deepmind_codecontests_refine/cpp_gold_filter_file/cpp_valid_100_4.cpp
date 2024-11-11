#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1337377;
const int MAXN = 2e5 + 2;
const int oo = 1e9;
const long long oo15 = 1e15;
const long long oo18 = 1e18;
const long long oooo = 9223372036854775807;
int a[200005];
long long fact[200005], infact[200005];
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long yy = power(x, y / 2);
  if (y % 2)
    return yy * yy % MOD1 * x % MOD1;
  else
    return yy * yy % MOD1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  for (long long i = 1; i <= 2e5 + 3; i++) fact[i] = i * fact[i - 1] % MOD1;
  infact[200003] = power(fact[200003], MOD1 - 2);
  for (long long i = 2e5 + 2; i >= 0; i--)
    infact[i] = (i + 1) * infact[i + 1] % MOD1;
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int n;
    cin >> n;
    int mx1 = 0, mx2 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] > mx1) {
        mx2 = mx1;
        mx1 = a[i];
      } else
        mx2 = max(mx2, a[i]);
    }
    if (mx1 - mx2 >= 2) {
      cout << 0 << "\n";
    } else if (mx2 == mx1) {
      cout << fact[n] << "\n";
    } else {
      long long dem = 0;
      for (int i = 1; i <= n; i++)
        if (a[i] == mx2) dem++;
      cout << fact[n - dem - 1] * fact[dem] % MOD1 *
                  (fact[n] * infact[dem + 1] % MOD1 * infact[n - dem - 1] %
                   MOD1) %
                  MOD1 * dem % MOD1
           << "\n";
    }
  }
}
