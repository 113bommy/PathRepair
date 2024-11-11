#include <bits/stdc++.h>
using namespace std;
int v[1000000 + 5];
pair<int, int> ap[1000000 + 5];
int Ms[1000000 + 5];
int md[1000000 + 5];
void umin(int &a, int b) { a = min(a, b); }
void umax(int &a, int b) { a = max(a, b); }
int main() {
  int n, m;
  cin >> n >> m;
  int i, z, p, s, flag = 0;
  for (z = 1; z <= m; z++) ap[z] = {(INT_MAX / 2 - 1), 0};
  for (i = 1; i <= n; i++)
    cin >> v[i], umin(ap[v[i]].first, i), umax(ap[v[i]].second, i);
  for (z = 1; z <= m; z++) Ms[z] = max(Ms[z - 1], ap[z].second);
  for (md[m + 1] = (INT_MAX / 2 - 1), z = m; z >= 1; z--)
    md[z] = min(md[z + 1], ap[z].first);
  long long ans = 0;
  s = m;
  while (s >= 1 && md[s] >= ap[s - 1].second) s--;
  for (p = 0; p < m && flag == 0; p++) {
    while (s <= m && (s <= p + 1 || Ms[p] > md[s])) s++;
    ans += 1LL * (m - s + 2);
    if (ap[p + 1].first < Ms[p]) flag = 1;
  }
  cout << ans;
  return 0;
}
