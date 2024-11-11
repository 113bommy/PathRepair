#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 9, INF = 1e9;
long long ar[MAX], par[MAX], c[MAX], v[MAX], n, k, s, t, ans = INF;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k >> s >> t;
  for (int i = 0; i < n; i++) cin >> c[i] >> v[i];
  for (int i = 0; i < k; i++) cin >> ar[i];
  sort(ar, ar + k), ar[k] = s;
  for (int i = k - 1; i >= 0; i--) ar[i + 1] -= ar[i];
  sort(ar, ar + k + 1);
  for (int i = 1; i <= k + 1; i++) par[i] = par[i - 1] + ar[i - 1];
  for (int i = 0; i < n; i++)
    if (ar[k] <= v[i]) {
      long long pos = upper_bound(ar, ar + k + 1, v[i] / 2) - ar;
      long long tmp =
          2 * s - par[pos] - (k + 1 - pos) * v[i] + (par[k + 1] - par[pos]);
      if (tmp <= t) ans = min(ans, c[i]);
    }
  if (ans == INF)
    cout << -1;
  else
    cout << ans;
  return 0;
}
