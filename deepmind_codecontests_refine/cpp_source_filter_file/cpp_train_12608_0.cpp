#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e6 + 3;
const long long MOD = 1e9 + 7;
long long n, a[NMAX], f[NMAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    vector<int> ve;
    if (a[i] <= n) ve.push_back(a[i]);
    for (int x = sqrt(a[i]); x >= 2; --x)
      if (a[i] % x == 0) {
        if (x <= n) ve.push_back(x);
        if (x * x != a[i] && a[i] / x <= n) ve.push_back(x);
      }
    if (a[i] != 1) ve.push_back(1);
    sort(ve.begin(), ve.end());
    for (int i = (int)ve.size() - 1; i >= 0; --i)
      f[ve[i]] = (f[ve[i]] + f[ve[i] - 1]) % MOD;
  }
  long long res = 0;
  for (int i = 1; i <= n; ++i) res = (res + f[i]) % MOD;
  cout << res;
  return 0;
}
