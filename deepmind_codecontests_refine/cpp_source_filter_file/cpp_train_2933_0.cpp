#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, m, cnt[1 << 9], mn = 2e9, mx, pos1, pos2;
vector<vector<pair<long long, long long>>> v(1 << 9);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    long long k, mask = 0, x;
    cin >> k;
    while (k--) cin >> x, x--, mask |= (1 << x);
    cnt[mask]++;
  }
  for (int i = 0; i < m; i++) {
    long long k, mask = 0, x, c;
    cin >> c >> k;
    while (k--) cin >> x, x--, mask |= (1 << x);
    v[mask].push_back({c, i + 1});
  }
  for (int i = 0; i < (1 << 9); i++)
    if (v[i].size() >= 2) {
      sort(v[i].begin(), v[i].end());
      while (v[i].size() > 2) v[i].pop_back();
    }
  for (int i = 0; i < (1 << 9); i++)
    for (int j = 0; j < (1 << 9); j++) {
      if (!v[i].size() || !v[j].size() || (i == j && v[i].size() == 1))
        continue;
      long long mask = (i | j), sum = 0, cost;
      for (int k = 0; k < (1 << 9); k++)
        if ((mask & k) == k) sum += cnt[k];
      if (i == j)
        cost = v[i][0].first + v[i][1].first;
      else
        cost = v[i][0].first + v[j][0].first;
      if (sum > mx || (sum == mx && cost < mn)) {
        mx = sum;
        mn = cost;
        if (i == j)
          pos1 = v[i][0].second, pos2 = v[i][1].second;
        else
          pos1 = v[i][0].second, pos2 = v[j][0].second;
      }
    }
  cout << pos1 << " " << pos2;
  return 0;
}
