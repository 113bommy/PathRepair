#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k, m;
  cin >> n >> k >> m;
  vector<long long> inp(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> inp[i];
    sum += inp[i];
  }
  sort(inp.begin(), inp.end());
  long double ans = (long double)(sum + min(m, n * k)) / n;
  for (long long i = 0; i < k && i < (n - 1) && i < m; i++) {
    sum -= inp[i];
    ans = max(ans, (long double)(sum + min(m - i - 1, (n - i - 1) * k)) /
                       (long double)(n - i - 1));
  }
  cout << setprecision(12) << fixed << ans << '\n';
  cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC << endl;
  return 0;
}
