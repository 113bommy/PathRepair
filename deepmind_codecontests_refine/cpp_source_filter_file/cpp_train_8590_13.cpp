#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, i, j, d, h;
  cin >> n >> d >> h;
  long long temp = d;
  vector<pair<long long, long long>> ans;
  if (d < h) {
    cout << -1;
    return 0;
  } else if (2 * h < d) {
    cout << -1;
    return 0;
  }
  long long k = 2;
  for (i = 0; i < h; i++) {
    ans.push_back({i + 1, i + 2});
  }
  k = h + 2;
  long long prev = 1;
  d -= h;
  while (d--) {
    ans.push_back({prev, k});
    prev = k;
    k++;
  }
  long long x = 1;
  if (h == temp) {
    if (n == 3 && h == 1) {
      cout << -1 << endl;
      return 0;
    }
    x = 2;
  }
  n -= ans.size() + 1;
  while (n--) {
    ans.push_back({2, k});
    k++;
  }
  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }
}
