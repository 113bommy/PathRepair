#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9;
const double EPS = 1e-9;
int n, k, x;
set<int> distinctX;
set<pair<int, int> > scenarios;
map<int, int> fsOccur, lstOccur;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    if (i > 1) scenarios.insert({i, i - 1});
    if (i < n) scenarios.insert({i, i + 1});
  }
  for (int i = 0; i < k; ++i) {
    cin >> x;
    distinctX.insert(x);
    if (fsOccur.find(x) == fsOccur.end()) fsOccur[x] = i;
    lstOccur[x] = i;
  }
  int ans = n - int(distinctX.size());
  ans += 2 * n - 2;
  for (auto& scenario : scenarios)
    if (distinctX.find(scenario.first) != distinctX.end() &&
        distinctX.find(scenario.second) != distinctX.end() &&
        fsOccur[scenario.first] < lstOccur[scenario.second])
      --ans;
  cout << ans << '\n';
  return 0;
}
