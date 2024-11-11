#include <bits/stdc++.h>
using namespace std;
int n, k, x, y, c;
vector<pair<int, int>> v[100005];
pair<int, int> dfs(int x, int y) {
  pair<int, int> r;
  vector<pair<int, int>> z;
  for (auto it : v[x]) {
    if (it.first != y) {
      r = dfs(it.first, x);
      z.push_back({r.first + it.second, r.second + it.second});
    }
  }
  sort(z.rbegin(), z.rend());
  int a = 0, b = 0, next = 0;
  for (int i = 0; i < min((int)z.size(), k - 1); i++) {
    a += z[i].first;
  }
  if (z.size() >= k) {
    next = z[k - 1].first;
  }
  for (int i = 0; i < (int)z.size(); i++) {
    if (i < k - 1) {
      b = max(b, a - z[i].first + z[i].second + next);
    } else {
      b = max(b, a + z[i].second);
    }
  }
  return {a, b};
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y >> c;
    v[x].push_back({y, c});
    v[y].push_back({x, c});
  }
  cout << dfs(0, -1).second << endl;
}
