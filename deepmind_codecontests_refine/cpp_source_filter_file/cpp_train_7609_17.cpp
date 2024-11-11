#include <bits/stdc++.h>
using namespace std;
void solve();
signed main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(3);
  solve();
}
const long long INF = 1e18, MAXN = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
  long long n, curmin = INF, curmax = -INF;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    long long num;
    cin >> num;
    curmin = min(num, curmin);
    curmax = max(num, curmax);
  }
  cout << n - (curmax - curmin + 1) << "\n";
}
