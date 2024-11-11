#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int> > v(n + 5);
  for (int i = 1; i <= n; i++) cin >> v[i].first;
  for (int i = 1; i <= n; i++) cin >> v[i].second;
  vector<int> vect[n + 5];
  for (int i = 1; i <= n; i++) vect[v[i].second].push_back(v[i].first);
  for (int i = 1; i <= m; i++) sort(vect[i].rbegin(), vect[i].rend());
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    if (vect[v[a].second][0] != a) ans++;
  }
  cout << ans << endl;
}
