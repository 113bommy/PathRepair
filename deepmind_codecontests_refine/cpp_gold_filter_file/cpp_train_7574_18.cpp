#include <bits/stdc++.h>
using namespace std;
const long long oo = 3e18 + 7;
const long long N = 234567;
const long long mod = 1e9 + 7;
long long a[N], nxt[N], sum[N], n, m, k;
void solve() {
  cin >> n;
  string s;
  cin >> s;
  for (long long i = 1; i <= n; ++i) {
    if (n % i == 0) {
      for (long long j = 0; j <= (i - 1) / 2; ++j) {
        swap(s[j], s[i - j - 1]);
      }
    }
  }
  cout << s;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  solve();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
