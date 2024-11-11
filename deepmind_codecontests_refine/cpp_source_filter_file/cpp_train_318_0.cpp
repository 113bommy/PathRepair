#include <bits/stdc++.h>
using namespace std;
const int N = 201;
const int T = 201;
int n, t;
long long z;
long long a[N], b[N], c[N];
long long pa[N], pb[N];
bool cl1[N][T], cl2[N][T];
long long mr1[N][T], mr2[N][T];
long long dp1[N][T], dp2[N][T];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> t >> z;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    pa[i] = pa[i - 1] + a[i];
    pb[i] = pb[i - 1] + b[i];
  }
  for (int i = 0; i <= t; i++) cl1[0][i] = cl2[0][i] = true;
  for (int i = 1; i <= n; i++) {
    cl2[i][0] = true;
    mr2[i][0] = 0;
    for (int j = 1; j <= t; j++) {
      mr2[i][j] = -1;
      for (int k = 0; k < j; k++) {
        if (mr2[i][k] == -1) continue;
        if (!cl2[i - 1][j - k]) continue;
        long long mn = mr2[i][k] % z, mx = mr2[i][k];
        long long rm =
            mn + pb[i] * (j - k) - (pb[i - 1] * (j - k) + z - 1) / z * z;
        mn += (j - k) * b[i];
        mx += (j - k) * b[i];
        if (rm < 0) mn += z, rm += z;
        if (mn > mx) continue;
        if (mn > c[i]) continue;
        if (mx > c[i]) {
          long long f = mx - c[i];
          f = (f + z - 1) / z;
          mx -= f * z;
        }
        mx = mx - mn + rm;
        mn = rm;
        mr2[i][j] = max(mr2[i][j], mx);
      }
    }
    for (int j = 1; j <= t; j++) {
      if (cl2[i - 1][j]) {
        if (b[i] * j <= c[i]) cl2[i][j] = true;
      }
      for (int k = 0; k < j; k++) {
        if (mr2[i][k] == -1) continue;
        if (!cl2[i - 1][j - k]) continue;
        if (mr2[i][k] % z + (j - k) * b[i] <= c[i]) cl2[i][j] = true;
      }
    }
    for (int j = 0; j <= t; j++) {
      mr1[i][j] = -1;
      if (cl1[i - 1][j]) {
        if (a[i] + b[i] * j <= c[i]) {
          long long rm =
              pa[i] + pb[i] * j - (pa[i - 1] + pb[i - 1] * j + z - 1) / z * z;
          if (rm >= 0) mr1[i][j] = rm;
        }
      }
      for (int k = 0; k < j; k++) {
        if (mr1[i][k] == -1) continue;
        if (!cl2[i - 1][j - k]) continue;
        long long mn = mr1[i][k] % z, mx = mr1[i][k];
        long long rm =
            mn + pb[i] * (j - k) - (pb[i - 1] * (j - k) + z - 1) / z * z;
        mn += (j - k) * b[i];
        mx += (j - k) * b[i];
        if (rm < 0) mn += z, rm += z;
        if (mn > mx) continue;
        if (mn > c[i]) continue;
        if (mx > c[i]) {
          long long f = mx - c[i];
          f = (f + z - 1) / z;
          mx -= f * z;
        }
        mx = mx - mn + rm;
        mn = rm;
        mr1[i][j] = max(mr1[i][j], mx);
      }
    }
    for (int j = 0; j <= t; j++) {
      if (cl1[i - 1][j]) {
        if (a[i] + b[i] * j <= c[i]) cl1[i][j] = true;
      }
      for (int k = 0; k < j; k++) {
        if (mr1[i][k] == -1) continue;
        if (!cl1[i - 1][j - k]) continue;
        if (mr1[i][k] % z + (j - k) * b[i] <= c[i]) cl1[i][j] = true;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t; j++) {
      dp2[i][j] = 1e18;
      if (j * b[i] <= c[i]) {
        dp2[i][j] = dp2[i - 1][j];
        continue;
      }
      for (int k = 1; k <= j; k++) {
        if (cl2[i][k]) {
          long long cost = (pb[i] * k + z - 1) / z;
          dp2[i][j] = min(dp2[i][j], dp2[i][j - k] + cost);
        }
      }
      for (int k = 1; k <= j; k++) {
        if (mr2[i][k] != -1) {
          if (mr2[i][k] % z + (j - k) * b[i] > c[i]) continue;
          long long cost = (pb[i] * k - mr2[i][k]) / z;
          long long f = mr2[i][k] + (j - k) * b[i] - c[i];
          if (f > 0) {
            cost += (f + z - 1) / z;
          }
          dp2[i][j] = min(dp2[i][j], dp2[i - 1][j - k] + cost);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= t; j++) {
      dp1[i][j] = 1e18;
      if (a[i] + j * b[i] <= c[i]) {
        dp1[i][j] = dp1[i - 1][j];
        continue;
      }
      for (int k = 0; k <= j; k++) {
        if (cl1[i][k]) {
          long long cost = (pb[i] * k + pa[i] + z - 1) / z;
          dp1[i][j] = min(dp1[i][j], dp2[i][j - k] + cost);
        }
      }
      for (int k = 0; k <= j; k++) {
        if (mr1[i][k] != -1) {
          if (mr1[i][k] % z + (j - k) * b[i] > c[i]) continue;
          long long cost = (pa[i] + pb[i] * k - mr1[i][k]) / z;
          long long f = mr1[i][k] + (j - k) * b[i] - c[i];
          if (f > 0) {
            cost += (f + z - 1) / z;
          }
          dp1[i][j] = min(dp1[i][j], dp2[i - 1][j - k] + cost);
        }
      }
    }
  }
  cout << dp1[n][t] << '\n';
}
