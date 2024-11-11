#include <bits/stdc++.h>
using namespace std;
const long long N = 100005, INF = 1e18;
void solve() {
  long long n, a, ans = 0, rank = 1;
  cin >> n;
  for (long long i = 0; i < 4; i++) {
    cin >> a;
    ans += a;
  }
  n--;
  while (n--) {
    long long sum = 0;
    for (long long i = 0; i < 4; i++) {
      cin >> a;
      sum += a;
    }
    if (sum > ans) rank++;
  }
  cout << rank << '\n';
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) solve();
}
