#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 100;
const long long INF = 1e18;
const long long MOD = 998244353;
long long k;
void solve() {
  cin >> k;
  for (int i = 2; i <= 2000; ++i) {
    long long sum = k + i - 1;
    if (1e6 * (i - 1) < sum) continue;
    cout << i << '\n';
    cout << -1 << ' ';
    long long cur_sum = -1;
    for (int j = 0; j < i - 1; ++j) {
      if (cur_sum + 1e6 < sum) {
        cur_sum += 1e6;
        cout << (long long)1e6 << ' ';
      } else {
        cout << sum - cur_sum << ' ';
        cur_sum = sum;
      }
    }
    break;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long test = 1;
  while (test--) solve();
  return 0;
}
