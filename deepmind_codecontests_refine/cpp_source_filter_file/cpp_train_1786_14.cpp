#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > V(n, make_pair(n + 5, -1));
  for (int i = 0, x; i < k; i++) {
    cin >> x;
    x--;
    V[x].first = min(V[x].first, i);
    V[x].second = max(V[x].second, i);
  }
  int ans = 0;
  for (int a = 0; a < n; a++)
    if (V[a].second == -1) ans++;
  for (int a = 0; a < n - 1; a++)
    if (V[a].second == -1 or V[a + 1].second == -1 or
        V[a + 1].second < V[a].first)
      ans++;
  for (int a = 1; a < n; a++)
    if (V[a].second == -1 or V[a - 1].second == -1 or
        V[a - 1].second < V[a].first)
      ans++;
  cout << ans << endl;
  return 0;
}
