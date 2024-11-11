#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 205;
const long long INF = 200;
long long n, l, beg, p[MAXN], n1, n2;
double dp1[MAXN][MAXN], dp2[MAXN][MAXN][MAXN], sum[MAXN];
vector<double> win1, lose1, win2, lose2;
vector<long long> pack;
int main() {
  while (~scanf("%lld %lld %lld", &n, &l, &beg)) {
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &p[i]);
    }
    for (long long i = 1; i <= n; i++) {
      long long x;
      scanf("%lld", &x);
      if (x == -1) {
        win1.push_back(p[i] * 1.0 / 100);
        lose1.push_back((100 - p[i]) * 1.0 / 100);
        n1++;
      } else {
        win2.push_back(p[i] * 1.0 / 100);
        lose2.push_back((100 - p[i]) * 1.0 / 100);
        pack.push_back(x);
        n2++;
      }
    }
    dp1[0][0] = 1;
    dp2[0][0][beg] = 1;
    for (long long i = 1; i <= n1; i++) {
      for (long long j = 0; j < i; j++) {
        dp1[i][j + 1] += dp1[i - 1][j] * win1[i - 1];
        dp1[i][j] += dp1[i - 1][j] * lose1[i - 1];
      }
    }
    for (long long i = 1; i <= n2; i++) {
      for (long long j = 0; j < i; j++) {
        for (long long k = 0; k <= INF; k++) {
          dp2[i][j + 1][min(k + pack[i - 1], 200ll)] +=
              dp2[i - 1][j][k] * win2[i - 1];
          dp2[i][j][k] += dp2[i - 1][j][k] * lose2[i - 1];
        }
      }
    }
    double ans = 0;
    for (long long i = 0; i <= n2; i++) {
      for (long long j = 0; j <= INF; j++) {
        sum[j] = 0;
      }
      sum[0] = dp2[n2][i][0];
      for (long long j = 1; j <= INF; j++) {
        sum[j] = sum[j - 1] + dp2[n2][i][j];
      }
      for (long long j = max(0ll, l - i); j <= n1; j++) {
        double pos;
        if (!j) {
          pos = sum[INF];
        } else {
          sum[INF] - sum[j - 1];
        }
        ans += dp1[n1][j] * pos;
      }
    }
    printf("%.12f\n", ans);
  }
}
