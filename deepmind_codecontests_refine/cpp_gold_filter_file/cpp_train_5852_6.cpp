#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 10;
const long long M = 1e5 + 10;
const long long eps = 0.00001;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> b(n);
  for (long long i = 0; i < m; ++i) {
    long long x, y, z;
    cin >> x >> y >> z;
    --x;
    --y;
    b[y] += z;
    b[x] -= z;
  }
  vector<long long> pos;
  vector<long long> neg;
  for (long long i = 0; i < n; ++i) {
    if (b[i] == 0) continue;
    if (b[i] < 0)
      neg.push_back(i);
    else
      pos.push_back(i);
  }
  vector<pair<pair<long long, long long>, long long>> ans;
  while (pos.size() > 0 && neg.size() > 0) {
    long long x = pos.back();
    long long y = neg.back();
    if (b[x] == 0) {
      pos.pop_back();
      continue;
    }
    if (b[y] == 0) {
      neg.pop_back();
      continue;
    }
    long long mn = min(b[x], -b[y]);
    b[x] -= mn;
    b[y] += mn;
    ans.push_back({{y + 1, x + 1}, mn});
  }
  cout << ans.size() << endl;
  for (auto to : ans) {
    cout << to.first.first << " " << to.first.second << " " << to.second
         << endl;
  }
  return 0;
}
