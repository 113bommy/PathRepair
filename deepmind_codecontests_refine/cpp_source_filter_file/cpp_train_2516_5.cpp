#include <bits/stdc++.h>
using namespace std;
pair<long long, int> g[200005];
int main() {
  int n, i;
  scanf("%d", &n);
  vector<pair<int, int>> v(n);
  for (i = 0; i < n; i++) scanf("%d%d", &v[i].second, &v[i].first);
  sort(v.begin(), v.end());
  g[n] = {2e9, 0};
  for (i = n - 1; i >= 0; i--) {
    int poz = lower_bound(v.begin() + i, v.end(), make_pair(v[i].second, -1)) -
              v.begin();
    if (poz == n)
      g[i] = {v[i].first, 1};
    else
      g[i] = {g[poz].first - (v[i].second - v[i].first), g[poz].second};
    if (g[i].first > g[i + 1].first)
      g[i] = g[i + 1];
    else if (g[i].first == g[i + 1].first)
      g[i].second = (g[i].second + g[i + 1].second) % 1000007;
  }
  printf("%d\n", g[0].second);
  return 0;
}
