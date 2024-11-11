#include <bits/stdc++.h>
using namespace std;
long long a[200001];
long long n, k;
bool check(long long days) {
  long long sum = 0;
  for (long long j = 0; j < n; ++j) {
    sum += max(a[j] - j / days, (long long)0);
  }
  return sum >= k;
}
void solve() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, greater<long long>());
  long long L = 1, R = n;
  long long ans = -1;
  while (L <= R) {
    long long mid = (L + R) / 2;
    if (check(mid)) {
      ans = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
