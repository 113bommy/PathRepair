#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > can[2];
bool used[2][2005];
int solve(int x, int type) {
  memset(used, false, sizeof(used));
  int ans = 0;
  int maxx = x;
  bool p = false;
  while (true) {
    if (p) break;
    for (int i = can[type].size() - 1; i >= -1; --i) {
      if (i == -1) {
        p = true;
        break;
      }
      if (used[type][i] || maxx < can[type][i].second)
        continue;
      else {
        used[type][i] = true;
        maxx += can[type][i].first;
        ans++;
        break;
      }
    }
    type = (type + 1) % 2;
  }
  return ans;
}
int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int t, h, m;
    cin >> t >> h >> m;
    can[t].push_back(make_pair(m, h));
  }
  sort(can[0].begin(), can[0].end());
  sort(can[1].begin(), can[1].end());
  cout << min(solve(x, 0), solve(x, 1)) << endl;
  return 0;
}
