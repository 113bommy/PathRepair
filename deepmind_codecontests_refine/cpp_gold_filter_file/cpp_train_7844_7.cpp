#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-10;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
long long a[1005];
int main(void) {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  if (n == 1 || n % 2 == 0) cout << -1 << endl, exit(0);
  long long ans = 0, rez = 0;
  for (long long i = n / 2; i >= 2; i--) {
    rez = max(a[i * 2], a[i * 2 + 1]);
    a[i * 2] -= rez;
    a[i * 2 + 1] -= rez;
    a[i] -= rez;
    if (a[i * 2] < 0) a[i * 2] = 0;
    if (a[i * 2 + 1] < 0) a[i * 2 + 1] = 0;
    if (a[i] < 0) a[i] = 0;
    ans += rez;
  }
  ans += max(a[1], max(a[2], a[3]));
  cout << ans << endl;
  return 0;
}
