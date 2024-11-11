#include <bits/stdc++.h>
using namespace std;
int n, k, q, inc[101];
double a[101], mi = 1000000007LL, ma;
set<vector<int> > S;
set<vector<int> >::iterator it;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> q;
  int m = n / k;
  for (int i = 0; i < q; i++) {
    vector<int> v;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      v.push_back(x);
      inc[v[j] - 1] = 1;
    }
    sort(v.begin(), v.end());
    S.insert(v);
  }
  for (it = S.begin(); it != S.end(); it++) {
    vector<int> v = *it;
    double s = 0;
    for (int i = 0; i < v.size(); i++) s += a[v[i] - 1];
    s /= v.size();
    mi = min(mi, s);
    ma = max(ma, s);
  }
  vector<double> v;
  for (int i = 0; i < n; i++)
    if (!inc[i]) v.push_back(a[i]);
  if (v.size() >= m && k > S.size()) {
    sort(v.begin(), v.end());
    double s = 0;
    for (int i = 0; i < m; i++) s += v[i];
    mi = min(mi, s / m);
    s = 0;
    for (int i = 0; i < m; i++) s += v[v.size() - 1 - i];
    ma = max(ma, s / m);
  }
  cout << setprecision(9) << mi << " " << ma;
}
