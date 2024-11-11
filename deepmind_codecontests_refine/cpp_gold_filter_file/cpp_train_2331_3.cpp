#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const int LEVEL = log2(N) + 1;
long long test = 1, n, a[N], ct = 0, ans = 0;
void solve() {
  cin >> n;
  for (int i = 1; i <= 2 * n - 1; i++) {
    cin >> a[i];
    if (a[i] < 0) ct++;
    a[i] = abs(a[i]);
  }
  sort(a + 1, a + 2 * n);
  int m = (n % 2 == 0) ? 2 : 1;
  ct %= m;
  for (int i = 1; i <= 2 * n - 1; i++) {
    if (i <= ct)
      ans -= a[i];
    else
      ans += a[i];
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  ;
  for (int i = 1; i <= test; i++) {
    solve();
  }
}
