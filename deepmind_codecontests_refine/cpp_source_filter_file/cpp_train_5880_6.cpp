#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int a[N];
double f[N][N], nf[N][N];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k > 200) {
    double ans = n;
    ans *= (n - 1);
    ans /= 4.0;
    cout << ans << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      f[i][j] = (a[i] > a[j]);
    }
  }
  int segs = n * (n + 1) / 2;
  for (int step = 1; step <= k; step++) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        nf[i][j] = 0.0;
        nf[i][j] += f[i][j] * 1.0 *
                    (((i + 1) * i / 2) + ((j - i) * (j - i - 1) / 2) +
                     ((n - j) * (n - j - 1) / 2));
        for (int sum = j; sum <= i + (n - 1); sum++) {
          int from = (sum - n + 1 > 0 ? sum - n + 1 : 0);
          int to = (i < sum - j ? i : sum - j);
          nf[i][j] += (1.0 - f[sum - j][sum - i]) * (to - from + 1);
        }
        for (int sum = i; sum <= i + (j - 1); sum++) {
          int from = (sum - j + 1 > 0 ? sum - j + 1 : 0);
          int to = (i < sum - i ? i : sum - i);
          nf[i][j] += f[sum - i][j] * (to - from + 1);
        }
        for (int sum = (i + 1) + j; sum <= j + (n - 1); sum++) {
          int from = (i + 1 > sum - n + 1 ? i + 1 : sum - n + 1);
          int to = (j < sum - j ? j : sum - j);
          nf[i][j] += f[i][sum - j] * (to - from + 1);
        }
        nf[i][j] /= segs;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        f[i][j] = nf[i][j];
      }
    }
  }
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans += f[i][j];
    }
  }
  printf("%.17f\n", ans);
  return 0;
}
