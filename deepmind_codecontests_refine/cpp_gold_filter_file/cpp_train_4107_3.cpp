#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> v[N];
int n, m;
int a[N];
long long _abs(long long x) { return x > 0ll ? x : -x; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
  }
  long long s = 0;
  for (int i = 1; i <= m; ++i) {
    if (i > 1 && a[i] != a[i - 1]) v[a[i]].push_back(a[i - 1]);
    if (i < m && a[i] != a[i + 1]) v[a[i]].push_back(a[i + 1]);
    if (i > 1) s += _abs(a[i] - a[i - 1]);
  }
  long long ans = 1e18;
  for (int i = 1; i <= n; ++i) {
    sort(v[i].begin(), v[i].end());
    int se = int(v[i].size());
    int id = se / 2;
    long long t0 = 0, t1 = 0;
    for (int j = 0; j < se; ++j) {
      t0 += _abs(i - v[i][j]);
      t1 += _abs(v[i][j] - v[i][id]);
    }
    ans = min(ans, s - t0 + t1);
  }
  cout << ans << endl;
  return 0;
}
