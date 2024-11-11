#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long n, m, k;
  cin >> n >> m >> k;
  vector<int32_t> x, y;
  x.resize(k);
  y.resize(k);
  vector<vector<int32_t>> d(m + n + 1, vector<int32_t>(0)),
      s(m + n + 1, vector<int32_t>(0));
  for (long i = 0; i < k; i++) {
    cin >> x[i] >> y[i];
    s[x[i] + y[i]].push_back(i);
    d[x[i] + m - y[i]].push_back(i);
  }
  bool up = 1, right = 1;
  int x0 = 0, y0 = 0;
  long long t = 0;
  vector<int64_t> ans(k, -1);
  do {
    if (up == right) {
      long d0 = x0 + m - y0;
      for (long i = 0; i < d[d0].size(); i++) {
        long j = d[d0][i];
        if (ans[j] == -1) ans[j] = t + abs(x0 - x[j]);
      }
    } else {
      long s0 = x0 + y0;
      for (long i = 0; i < s[s0].size(); i++) {
        long j = s[s0][i];
        if (ans[j] == -1) ans[j] = t + abs(x0 - x[j]);
      }
    }
    long dd = min(up ? m - y0 : y0, right ? n - x0 : x0);
    t += dd;
    x0 += right ? dd : -dd;
    y0 += up ? dd : -dd;
    if (x0 == 0 || x0 == n) right = !right;
    if (y0 == 0 || y0 == m) up = !up;
  } while (x0 != 0 || y0 != 0);
  for (long i = 0; i < k; i++) cout << ans[i] << '\n';
}
