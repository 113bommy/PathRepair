#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 9e18 + 2e17;
const int inf = 2e9;
const int N = 2e5 + 22;
const double eps = 1e-10;
const double PI = 3.14159265;
int n, m;
int a[N], ans[N];
void _solve() {
  cin >> n;
  for (int i = (int)0; i < (int)n; i++) cin >> a[i];
  int inc = -inf, dec = inf;
  for (int i = (int)0; i < (int)n; i++) {
    if (a[i] <= inc && a[i] >= dec) {
      cout << "NO";
      return;
    }
    if (a[i] > inc && a[i] >= dec)
      inc = a[i], ans[i] = 0;
    else if (a[i] < dec && a[i] <= inc)
      dec = a[i], ans[i] = 1;
    else if (i + 1 < n) {
      if (a[i + 1] > a[i])
        inc = a[i], ans[i] = 0;
      else
        dec = a[i], ans[i] = 1;
    } else if (a[i] > inc)
      inc = a[i], ans[i] = 0;
    else
      dec = a[i], ans[i] = 1;
  }
  cout << "YES\n";
  for (int __i = 0; __i < (int)n; __i++) cout << ans[__i] << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _solve();
  return 0;
}
