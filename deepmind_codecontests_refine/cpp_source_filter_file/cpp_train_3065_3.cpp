#include <bits/stdc++.h>
using namespace std;
int n, m, s, e, a[100005], b[100005], f[100005];
vector<int> v[100005];
vector<int>::iterator it;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> m >> n >> s >> e;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i], v[b[i]].push_back(i);
  memset(f, 60, sizeof f);
  f[0] = -1;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = s / e; j >= 0; j--) {
      it = upper_bound(v[a[i]].begin(), v[a[i]].end(), f[j]);
      if (it == v[a[i]].end()) continue;
      f[j + 1] = min(*it, f[j + 1]);
      if (i + f[j + 1] + (j + 1) * e <= s) ans = max(ans, j + 1);
    }
  cout << ans;
  return 0;
}
