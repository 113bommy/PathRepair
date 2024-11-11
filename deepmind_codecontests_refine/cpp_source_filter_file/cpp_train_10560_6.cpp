#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long int, pair<long long int, long long int>> x,
         pair<long long int, pair<long long int, long long int>> y) {
  return x.second.first < x.second.first;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  vector<pair<long long int, pair<long long int, long long int>>> v(n);
  long long int i;
  for (i = 0; i <= n - 1; i++) {
    cin >> v[i].first;
    v[i].second.first = i;
    v[i].second.second = -1;
  }
  for (long long int i = 0; i < m; i++) {
    long long int u, v;
    cin >> u >> v;
  }
  sort(v.begin(), v.end());
  long long int flag = 1;
  for (long long int i = 0; i < n; i++) {
    v[i].second.second = flag;
    flag = flag ^ 1;
  }
  sort(v.begin(), v.end(), cmp);
  for (auto x : v) {
    cout << x.second.second << " ";
  }
  cout << "\n";
  return 0;
}
