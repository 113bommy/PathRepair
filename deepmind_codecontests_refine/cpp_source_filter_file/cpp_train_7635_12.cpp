#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
signed main() {
  long long int n;
  cin >> n;
  vector<vector<long long int>> a(n);
  for (long long int i = 0; i < n; i++) {
    long long int cnt;
    cin >> cnt;
    for (long long int j = 0; j < cnt; j++) {
      long long int num;
      cin >> num;
      a[i].push_back(num);
    }
  }
  for (long long int i = 0; i < n; i++) sort(a.begin(), a.end());
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    long long int prev = (i - 1 + n) % n;
    long long int next = (i + 1) % n;
    for (long long int j = 1; j < a[i].size(); j++) {
      long long int cntPrev =
          (upper_bound(a[prev].begin(), a[prev].end(), a[i][j]) -
           lower_bound(a[prev].begin(), a[prev].end(), a[i][j - 1]));
      long long int cntNext =
          (upper_bound(a[next].begin(), a[next].end(), a[i][j]) -
           lower_bound(a[next].begin(), a[next].end(), a[i][j - 1]));
      ans += (cntNext != cntPrev);
    }
  }
  cout << ans;
  return 0;
}
