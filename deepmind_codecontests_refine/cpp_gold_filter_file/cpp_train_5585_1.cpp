#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<long double> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int j;
  long double ans = 0;
  for (int i = 0; i < n - 2; i++) {
    j = lower_bound(v.begin(), v.end(), v[i] + m) - v.begin();
    if (j == n) j--;
    if (v[j] > v[i] + m) j--;
    ans = max(ans, (v[j] - v[i + 1]) / (v[j] - v[i]));
  }
  if (ans != 0)
    cout << fixed << setprecision(9) << ans;
  else
    cout << -1;
  return 0;
}
