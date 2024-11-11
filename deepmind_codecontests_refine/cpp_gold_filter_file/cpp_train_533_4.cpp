#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<pair<long long, long long>> ans;
  long long in = 0;
  while (1) {
    if (in >= n) break;
    if (a[in] == in + 1) {
      in++;
      continue;
    }
    if (abs(in + 1 - a[in]) * 2 >= n) {
      ans.push_back({in + 1, a[in]});
      swap(a[in], a[a[in] - 1]);
      continue;
    }
    long long z = a[in];
    if (z > n / 2) {
      if (in + 1 <= n / 2) {
        ans.push_back({in + 1, n});
        ans.push_back({n, 1});
        ans.push_back({1, z});
        ans.push_back({1, n});
        swap(a[in], a[n - 1]);
        swap(a[0], a[n - 1]);
        swap(a[0], a[z - 1]);
        swap(a[0], a[n - 1]);
      } else {
        ans.push_back({in + 1, 1});
        ans.push_back({1, z});
        ans.push_back({1, in + 1});
        swap(a[0], a[in]);
        swap(a[0], a[z - 1]);
        swap(a[0], a[in]);
      }
    } else {
      if (in + 1 <= n / 2) {
        ans.push_back({in + 1, n});
        ans.push_back({n, z});
        swap(a[in], a[n - 1]);
        swap(a[z - 1], a[n - 1]);
      } else {
        ans.push_back({in + 1, 1});
        ans.push_back({1, n});
        ans.push_back({n, z});
        ans.push_back({1, in + 1});
        swap(a[0], a[in]);
        swap(a[0], a[n - 1]);
        swap(a[n - 1], a[z - 1]);
        swap(a[0], a[in]);
      }
    }
  }
  cout << ans.size() << endl;
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
