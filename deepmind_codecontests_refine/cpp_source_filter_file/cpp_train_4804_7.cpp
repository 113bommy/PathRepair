#include <bits/stdc++.h>
using namespace std;
signed solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tests = 1;
  while (tests--) solve();
  return 0;
}
const int N = 2000;
int k;
long long ans[N];
signed solve() {
  cin >> k;
  cout << N << '\n';
  ans[0] = -1;
  long long sum = k + N, i = 1;
  while (sum > (long long)1e9) {
    ans[i++] = (long long)1e9;
    sum -= (long long)1e9;
  }
  ans[i++] = sum;
  for (; i < N; ++i) ans[i] = 0;
  for (auto &x : ans) cout << x << ' ';
  cout << '\n';
  return 0;
}
