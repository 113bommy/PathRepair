#include <bits/stdc++.h>
using namespace std;
void read(long long a = 0) {
  freopen("in", "r", stdin);
  if (a) freopen("out", "w", stdout);
}
long long a[100009 * 10], b[100009 * 10];
long long n, m;
bool bs(long long num) {
  bool vis[100009 * 10] = {};
  long long space = 0;
  for (int i = num; i >= 0; i--) {
    if (a[i] && !vis[a[i]]) {
      vis[a[i]] = 1;
      space += b[a[i] - 1];
    } else {
      space--;
      space = max(space, 0ll);
    }
  }
  for (int i = 1; i <= m; i++)
    if (!vis[i]) return 0;
  if (space == 0)
    return 1;
  else
    return 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  long long lo = 0, hi = n + 1;
  while (lo < hi) {
    long long mid = (lo + hi - 1) >> 1;
    if (bs(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  if (hi == n + 1)
    cout << "-1";
  else
    cout << hi + 1;
}
