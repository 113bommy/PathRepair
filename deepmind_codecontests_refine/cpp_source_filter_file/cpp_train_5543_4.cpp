#include <bits/stdc++.h>
using namespace std;
int n, k, m[222222], c[222222];
vector<int> s[222222];
int check(int x) {
  for (int i = 0; i < x; i++) s[i].clear();
  for (int i = 0; i < n; i++) {
    if ((int)s[i % x].size() >= c[m[i]]) return 0;
    s[i % x].push_back(m[i]);
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> m[i];
  for (int i = 1; i <= k; i++) cin >> c[i];
  sort(m, m + n, greater<int>());
  int l = 1, r = n, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << l << endl;
  check(l);
  for (int i = 0; i < l; i++) {
    cout << s[i].size() << ' ';
    for (int j = 0; j < (int)s[i].size(); j++) cout << s[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
