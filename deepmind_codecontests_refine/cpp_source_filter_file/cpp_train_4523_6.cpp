#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k, cur, ans = -99999999999;
  vector<pair<long long, long long>> v;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> cur;
    v.push_back(make_pair(cur, i));
  }
  sort(v.begin(), v.end());
  for (long long l = 0; l < n; l++) {
    for (long long r = l; r < n; r++) {
      long long swp = 0, sum = 0, t = r - l + 1;
      for (long long i = n - 1; i >= 0 && t > 0; i--) {
        if (v[i].second >= l && r >= v[i].second)
          sum += v[i].first, t--;
        else if (swp < k) {
          swp++, t--;
          sum += v[i].first;
        }
      }
      ans = max(ans, sum);
    }
  }
  cout << ans;
  return 0;
}
