#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e17;
int n, m, k, f[100010], t[100010], c[100010], costa[100010], costb[100010];
long long fa[1000010];
vector<int> v[1000010];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int day;
    cin >> day >> f[i] >> t[i] >> c[i];
    v[day].push_back(i);
  }
  for (int i = 1; i <= n; i++) costa[i] = -1;
  int dem = 0;
  long long tmp = 0;
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      int ii = v[i][j];
      if (f[ii] != 0) {
        if (costa[f[ii]] > c[ii] || costa[f[ii]] == -1) {
          if (costa[f[ii]] == -1) dem++;
          tmp = tmp + c[ii];
          if (costa[f[ii]] != -1) tmp -= costa[f[ii]];
          costa[f[ii]] = c[ii];
        }
      }
    }
    if (dem == n) fa[i] = tmp;
  }
  long long res = inf;
  for (int i = 1; i <= n; i++) costb[i] = -1;
  dem = 0;
  tmp = 0;
  for (int i = 1000000; i >= 1; i--) {
    for (int j = 0; j < v[i].size(); j++) {
      int ii = v[i][j];
      if (f[ii] == 0) {
        if (costb[t[ii]] > c[ii] || costb[t[ii]] == -1) {
          if (costb[t[ii]] == -1) dem++;
          tmp = tmp + c[ii];
          if (costb[t[ii]] != -1) tmp -= costb[t[ii]];
          costb[t[ii]] = c[ii];
        }
      }
    }
    if (dem == n && i > k + 1)
      if (fa[i - k - 1] != 0) res = min(res, tmp + fa[i - k - 1]);
  }
  if (res == inf)
    cout << -1;
  else
    cout << res;
}
