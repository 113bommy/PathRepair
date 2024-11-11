#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, i, j, k, ans, id, x;
  cin >> n >> m >> k;
  map<int, int> c;
  for (i = 0; i < n; i++) {
    cin >> id >> x;
    if (c.find(id) == c.end())
      c[id] = x;
    else
      c[id] = min(x, c[id]);
  }
  ans = 0;
  for (auto p : c) ans += p.second;
  ans = min(ans, k);
  cout << ans << "\n";
  return 0;
}
