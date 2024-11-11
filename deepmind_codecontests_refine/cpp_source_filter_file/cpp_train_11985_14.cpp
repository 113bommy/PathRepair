#include <bits/stdc++.h>
using namespace std;
vector<int> v[300003];
vector<pair<int, long long> > q[300003];
int cnt[300003], res[300003], n;
void dfs(int r, int p, int h, long long sum) {
  for (auto u : q[r]) {
    sum += u.second;
    if (u.first + h + 1 <= n) cnt[u.first + h + 1] += u.second;
  }
  sum -= cnt[h];
  res[r] = sum;
  for (auto u : v[r]) {
    if (u != p) dfs(u, r, h + 1, sum);
  }
  for (auto u : q[r]) {
    if (u.first + h + 1 <= n) cnt[u.first + h + 1] -= u.second;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long x, y, m, d, e;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cin >> m;
  while (m--) {
    cin >> e >> d >> x;
    q[e].push_back({d, x});
  }
  dfs(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) cout << res[i] << '\n';
}
