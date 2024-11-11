#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long n, m, k;
vector<pair<int, int> > v[N];
bool store[N];
void init() {
  cin >> n >> m >> k;
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }
  for (int i = 0; i < k; ++i) {
    cin >> a;
    store[a] = true;
  }
}
void solve() {
  long long ans = 1000000006;
  for (int i = 1; i <= n; ++i) {
    if (store[i]) continue;
    for (int j = 0; j < v[i].size(); ++j)
      if (store[v[i][j].first] && v[i][j].second < ans) {
        ans = v[i][j].second;
      }
  }
  if (ans == 1000000006)
    cout << "-1" << endl;
  else
    cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int __ = 1;
  while (__--) {
    init();
    solve();
  }
}
