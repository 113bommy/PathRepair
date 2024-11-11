#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 20;
int n, i, a[N], u, v, mx = INT_MIN, ans, c1, c2, cnt;
vector<int> adj[N];
bool m1[N], m2[N], ok;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (i = 1; i <= n; i++) {
    if (a[i] == mx)
      m1[i] = true, c1++;
    else if (a[i] == mx - 1)
      m2[i] = true, c2++;
  }
  if (c1 > 1)
    ans = mx + 1;
  else
    ans = mx;
  for (i = 1; i <= n; i++) {
    if (m2[i]) {
      int cnt = 0;
      for (auto j : adj[i]) cnt += m1[j];
      if (cnt != c1) ans = max(ans, mx + 1);
    }
    int cnt = m1[i];
    for (auto j : adj[i]) cnt += m1[j];
    if (cnt == c1) ok = true;
  }
  if (!ok) ans = mx + 2;
  cout << ans;
}
