#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 700;
long long f[MAX][MAX];
long long a[MAX][MAX], sum[MAX][MAX];
long long best = -19949994;
long long maxi = 0;
long long n, m;
long long stt;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%lld", &a[i][j]);
      sum[i][j] = sum[i][j - 1] + a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i][0] = -199999999;
  }
  for (int j = 1; j <= m; j++) {
    f[1][j] = sum[1][j];
  }
  for (int i = 2; i <= n; ++i) {
    if (i % 2 != 0) {
      stt = 1;
      for (int j = 2; j <= m; ++j) {
        if (f[i - 1][maxi] < f[i - 1][stt]) {
          maxi = stt;
        }
        f[i][j] = f[i - 1][maxi] + sum[i][j];
        stt++;
      }
    } else {
      for (int j = m - 1; j >= 1; j--) {
        stt = j + 1;
        if (f[i - 1][maxi] < f[i - 1][stt]) {
          maxi = stt;
        }
        f[i][j] = f[i - 1][maxi] + sum[i][j];
      }
    }
    maxi = 0;
  }
  if (n % 2 != 0) {
    for (int i = 2; i <= m; i++) {
      best = max(best, f[n][i]);
    }
  } else {
    for (int i = 1; i <= m - 1; i++) {
      best = max(best, f[n][i]);
    }
  }
  cout << best;
}
