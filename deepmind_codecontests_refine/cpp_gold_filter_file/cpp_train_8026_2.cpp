#include <bits/stdc++.h>
using namespace std;
int n;
pair<long long, long long> a[100010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
  sort(a + 1, a + n + 1);
  long long ans = -1e9;
  for (int i = 1; i <= n; ++i) ans = max(ans, a[i].first + a[i].second);
  cout << ans;
  return 0;
}
