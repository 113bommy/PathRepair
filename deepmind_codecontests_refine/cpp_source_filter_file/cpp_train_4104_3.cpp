#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 17;
int val[maxn];
int f[maxn][maxn];
int rf[maxn][maxn];
int main() {
  int n, total = 0, res = maxn * maxn, cnt_res = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> val[i];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      f[i][j] = f[i][j - 1] + (val[j] < val[i]),
      rf[i][j] = rf[i][j - 1] + (val[j] > val[i]);
  for (int i = 1; i <= n; ++i) total += rf[i][i];
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (val[i] < val[j]) continue;
      int cur = total - rf[i][i] - rf[j][j] + rf[i][j] + rf[j][i] - 1 -
                f[i][j] + f[i][i] + f[j][j] - f[j][i];
      if (cur < res)
        res = cur, cnt_res = 1;
      else if (cur == res)
        cnt_res++;
    }
  }
  cout << res << " " << cnt_res;
}
