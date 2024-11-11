#include <bits/stdc++.h>
using namespace std;
int n, m;
long long l[200005], r[200005], res[200005];
pair<long long, long long> a[200005];
pair<pair<long long, long long>, int> d[200005];
priority_queue<pair<long long, long long> > q;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  for (int i = 1; i <= m; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 1; i < n; i++) {
    d[i].first.first = l[i + 1] - r[i];
    d[i].first.second = r[i + 1] - l[i];
    d[i].second = i;
  }
  sort(d, d + n);
  sort(a, a + m + 1);
  while (!q.empty()) q.pop();
  int cur = 1;
  for (int i = 1; i <= m; i++) {
    while (d[cur].first.first <= a[i].first && cur < n) {
      q.push(make_pair(-d[cur].first.second, d[cur].second));
      cur++;
    }
    while (!q.empty()) {
      pair<long long, long long> gt = q.top();
      q.pop();
      if (-gt.first < a[i].first) break;
      res[gt.second] = a[i].second;
      break;
    }
  }
  for (int i = 1; i < n; i++)
    if (!res[i]) {
      cout << "No";
      exit(0);
    }
  cout << "Yes" << endl;
  for (int i = 1; i < n; i++) cout << res[i] << " ";
  return 0;
}
