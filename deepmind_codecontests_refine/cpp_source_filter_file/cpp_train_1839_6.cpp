#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
map<int, int> v[N];
int rec(int node, int w) {
  auto it = v[node].lower_bound(w);
  if (it == v[node].begin()) {
    return 1;
  }
  it--;
  return (*it).second + 1;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    int val = rec(a, w);
    if (rec(b, w + 1) > val) {
      continue;
    }
    v[b][w] = val;
    auto it = v[b].upper_bound(w);
    while (it != v[b].end() && (*it).second <= w) {
      it = v[b].erase(it);
    }
    ans = max(ans, val);
  }
  cout << ans;
}
