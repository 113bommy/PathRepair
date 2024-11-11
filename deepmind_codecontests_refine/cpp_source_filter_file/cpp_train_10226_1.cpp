#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<long long int, long long int> v;
  long long int n, m, i, j, ans = 0;
  queue<long long int> q;
  cin >> n >> m;
  vector<long long int> res, a(n);
  vector<pair<long long int, long long int> > d(n + 2);
  for (i = 1; i <= n; i++) {
    cin >> a[i - 1];
  }
  sort(a.begin(), a.end());
  v.second = -2e9 - 1;
  d[0] = v;
  v.first = 2e9 + 1;
  d[n + 1] = v;
  for (i = 1; i <= n; i++) {
    d[i].first = a[i - 1];
    d[i].second = a[i - 1];
    q.push(i);
  }
  i = 0;
  while (i < m) {
    j = q.front();
    q.pop();
    bool f = 0;
    if (d[j].second + 1 < d[j + 1].first && i < m) {
      ans += d[j].second + 1 - a[j - 1];
      res.push_back(d[j].second + 1);
      d[j].second++;
      i++;
      f = 1;
    }
    if (d[j].first - 1 > d[j - 1].second) {
      ans += a[j - 1] - d[j].first + 1;
      res.push_back(d[j].first - 1);
      d[j].first--;
      i++;
      f = 1;
    }
    if (f) q.push(j);
  }
  cout << ans << '\n';
  for (i = 0; i < res.size(); i++) cout << res[i] << " ";
  return 0;
}
