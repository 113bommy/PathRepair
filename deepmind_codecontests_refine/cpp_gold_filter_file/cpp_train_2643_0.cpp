#include <bits/stdc++.h>
using namespace std;
long long n, kapasite, x, y, a, adim, burda_kalan50, burda_kalan100,
    orda_kalan50, orda_kalan100, r, ans1, ans2, cozum_var_mi;
long long dp[(int)(52)][(int)(52)][2], C[(int)(52)][(int)(52)];
queue<pair<long long, pair<long long, long long> > > Q;
int main() {
  cin >> n >> kapasite;
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a;
    a == 50 ? x++ : y++;
  }
  dp[0][0][1] = 1;
  Q.push(make_pair(1, make_pair(0, 0)));
  while (!Q.empty()) {
    adim = Q.front().first;
    burda_kalan50 = Q.front().second.first;
    burda_kalan100 = Q.front().second.second;
    orda_kalan50 = x - burda_kalan50;
    orda_kalan100 = y - burda_kalan100;
    r = dp[burda_kalan50][burda_kalan100][adim & 1];
    Q.pop();
    if (burda_kalan50 == x and burda_kalan100 == y) {
      ans1 = adim - 1;
      ans2 = r;
      cozum_var_mi = 1;
      break;
    }
    if (adim & 1) {
      for (int i = 0; i <= orda_kalan50; i++)
        for (int j = 0; j <= orda_kalan100; j++) {
          if (i + j == 0 or i * 50 + j * 100 > kapasite) continue;
          if (!dp[burda_kalan50 + i][burda_kalan100 + j][0])
            Q.push(make_pair(adim + 1,
                             make_pair(burda_kalan50 + i, burda_kalan100 + j)));
          dp[burda_kalan50 + i][burda_kalan100 + j][0] =
              (dp[burda_kalan50 + i][burda_kalan100 + j][0] +
               r * C[orda_kalan50][i] * C[orda_kalan100][j]) %
              1000000007;
        }
    } else {
      for (int i = 0; i <= burda_kalan50; i++)
        for (int j = 0; j <= burda_kalan100; j++) {
          if (i + j == 0 or i * 50 + j * 100 > kapasite) continue;
          if (!dp[burda_kalan50 - i][burda_kalan100 - j][1])
            Q.push(make_pair(adim + 1,
                             make_pair(burda_kalan50 - i, burda_kalan100 - j)));
          dp[burda_kalan50 - i][burda_kalan100 - j][1] =
              (dp[burda_kalan50 - i][burda_kalan100 - j][1] +
               r * C[burda_kalan50][i] * C[burda_kalan100][j]) %
              1000000007;
        }
    }
  }
  if (cozum_var_mi)
    cout << ans1 << '\n' << ans2 << '\n';
  else
    cout << -1 << '\n' << 0 << '\n';
}
