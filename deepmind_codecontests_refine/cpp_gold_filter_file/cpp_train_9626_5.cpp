#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int> > d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    d.push_back(make_pair(a[i], 0));
  }
  cin >> m;
  vector<int> b(m);
  vector<pair<int, int> > c(n + m);
  vector<pair<int, int> > sum(n + m, make_pair(0, 0));
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    d.push_back(make_pair(b[i], 1));
  }
  sort(d.begin(), d.end());
  int tog = 0;
  if (d[0].second)
    sum[0].second = 1;
  else
    sum[0].first = 1;
  for (int i = 0; i < n + m; i++) {
    if (i > 0) {
      sum[i].first = sum[i - 1].first;
      sum[i].second = sum[i - 1].second;
    }
    if (!d[i].second) {
      tog++;
      if (i > 0) sum[i].first++;
    } else {
      tog--;
      if (i > 0) sum[i].second++;
    }
    c[i].first = tog;
    c[i].second = i;
  }
  sort(c.begin(), c.end());
  if (c[0].first < 0)
    cout << 3 * n - sum[c[0].second].first << ":"
         << 3 * m - sum[c[0].second].second << endl;
  else
    cout << 3 * n << ":" << 3 * m;
  return 0;
}
