#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[1000] = {0};
  for (long long i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = 1001;
  long long ans = 0;
  long long curr = 0;
  for (long long i = 1; i < n + 1; i++) {
    if (a[i] == a[i - 1] + 1 && a[i] == a[i + 1] - 1)
      curr++, ans = max(ans, curr);
    else
      curr = 0;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start, end;
  start = clock();
  long long tc;
  tc = 1;
  for (long long i = 1; i <= tc; i++) solve();
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
}
