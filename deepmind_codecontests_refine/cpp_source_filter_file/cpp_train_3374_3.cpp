#include <bits/stdc++.h>
using namespace std;
vector<long long> a, b;
vector<vector<vector<long long> > > d;
int n, m;
long long Bt(int p, int k, int obj) {
  long long& r = d[p][k][obj];
  if (r != -1) return r;
  if (p == n) {
    if (k == obj) return r = 0;
    return r = 1e15;
  }
  r = Bt(p + 1, k + 1, obj) + a[p];
  if (k) r = min(r, Bt(p + 1, k - 1, obj) + b[p]);
  return r;
}
int main() {
  cin >> n >> m;
  a = b = vector<long long>(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  d = vector<vector<vector<long long> > >(
      n + 1,
      vector<vector<long long> >(3 * n + 1, vector<long long>(2 * n + 1, -1)));
  vector<vector<long long> > v(2 * n + 1, vector<long long>(2 * n + 1));
  for (int i = 0; i <= 2 * n; ++i) {
    for (int j = 0; j <= 2 * n; ++j) v[i][j] = Bt(0, i, j);
  }
  long long res = 1e15;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= 2 * n; ++j) {
      res = min(res, v[0][i] + v[i][0] + ((m - 2) / 2) * (v[i][j] + v[j][i]));
    }
  }
  cout << res << endl;
}
