#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, k, arr[N], nxt[N], pos[N];
int val[N], is[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int i = 0; i <= n; ++i) pos[i] = 0;
  for (int i = n; i >= 0; --i) {
    nxt[i] = pos[arr[i]];
    pos[arr[i]] = i;
  }
  int ans = 0;
  set<pair<int, int>> s;
  for (int i = 1; i <= n; ++i) {
    if (is[arr[i]]) {
      int v = val[arr[i]];
      auto p = *s.lower_bound(make_pair(v, arr[i]));
      assert(p.second == arr[i]);
      s.erase(p);
      val[arr[i]] = nxt[i];
      s.insert({nxt[i], arr[i]});
      continue;
    }
    if (s.size() == k) {
      auto p = *s.begin();
      s.erase(p);
      is[p.second] = 0;
      ++ans;
      is[arr[i]] = 1;
      val[arr[i]] = nxt[i];
      s.insert({nxt[i], arr[i]});
    } else {
      ++ans;
      is[arr[i]] = 1;
      val[arr[i]] = nxt[i];
      s.insert({nxt[i], arr[i]});
    }
  }
  cout << ans << '\n';
}
