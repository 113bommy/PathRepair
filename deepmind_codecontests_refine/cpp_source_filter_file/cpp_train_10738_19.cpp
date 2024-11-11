#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
multiset<int> s;
int n, z, v[200002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> z;
  for (int i = 1; i <= n; ++i) cin >> v[i];
  sort(v + 1, v + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!s.empty() && i >= n / 2) {
      int x = *s.begin();
      if (v[i] - x >= z)
        ++ans, s.erase(s.lower_bound(x));
      else
        s.insert(v[i]);
    } else
      s.insert(v[i]);
  }
  cout << ans;
  return 0;
}
