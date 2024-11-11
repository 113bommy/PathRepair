#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int main() {
  int n, w;
  cin >> n >> w;
  int a[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += ceil((a[i] * 1.0) / (2.0));
  }
  if (sum > w)
    cout << -1;
  else {
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) v.push_back({a[i], i});
    sort(v.begin(), v.end(), cmp);
    int d[n];
    for (int i = 0; i < n; i++) d[i] = ceil(((v[i].first) * 1.0) / (2.0));
    w = w - sum;
    for (int i = 0; i < n; i++) {
      if (w == 0)
        break;
      else {
        int x = min(v[i].first - d[i], w);
        d[i] = d[i] + min(v[i].first - d[i], w);
        w -= x;
      }
    }
    int res[n];
    for (int i = 0; i < n; i++) {
      int idx = v[i].second;
      res[idx] = d[i];
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
  }
  return 0;
}
