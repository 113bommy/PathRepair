#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k = 0, m = 0, t, f = 0, x = 0, z, y = 0, p = 2,
                  mn = 10000000009, mx = 0, n, ta = 1000000000000000000, tb = 0,
                  r;
  cin >> n >> m;
  long long a[n + 9];
  for (i = 1; i <= n; i++) cin >> a[i];
  vector<pair<long long, long long> > v;
  vector<long long> v1;
  long long sum[100009] = {0};
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    v.push_back({x, y});
    v1.push_back(x);
  }
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  for (i = 1; i <= n; i++) sum[i] = sum[i - 1] + v[i - 1].second;
  for (i = 1; i <= n; i++) {
    k = upper_bound(v1.begin(), v1.end(), a[i]) - v1.begin();
    cout << sum[k] << " ";
  }
  return 0;
}
