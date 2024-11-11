#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2, typename T3>
class triple {
 public:
  T1 first;
  T2 second;
  T3 third;
  triple() {
    first = 0;
    second = 0;
    third = 0;
  }
};
const int maxn = 60 + 10;
const int maxk = 1000 + 10;
int n, m, q;
int a[maxn][maxn];
int dp[maxk][maxn][maxn];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  memset(dp, 63, sizeof(dp));
  for (int(t) = (1); (t) < (m + 1); (t)++) {
    for (int(i) = (1); (i) < (n + 1); (i)++)
      for (int(j) = (1); (j) < (n + 1); (j)++) cin >> a[i][j];
    for (int(k) = (1); (k) < (n + 1); (k)++)
      for (int(i) = (1); (i) < (n + 1); (i)++)
        for (int(j) = (1); (j) < (n + 1); (j)++)
          a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    for (int(i) = (1); (i) < (n + 1); (i)++)
      for (int(j) = (1); (j) < (n + 1); (j)++)
        dp[0][i][j] = min(dp[0][i][j], a[i][j]);
  }
  for (int(t) = (1); (t) < (1001); (t)++)
    for (int(k) = (1); (k) < (n + 1); (k)++)
      for (int(i) = (1); (i) < (n + 1); (i)++)
        for (int(j) = (1); (j) < (n + 1); (j)++)
          dp[t][i][j] = min(dp[t][i][j], dp[t - 1][i][k] + dp[0][k][j]);
  for (int(i) = (1); (i) < (q + 1); (i)++) {
    int s, t, k;
    cin >> s >> t >> k;
    cout << dp[k][s][t] << "\n";
  }
  return 0;
}
