#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 2e6 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
long long w[N], k;
int f[N], nx[N][35], n;
long long sum[N][35], mn[N][35];
int main() {
  scanf("%d", &n);
  scanf("%lld", &k);
  for (int i = 0; i < n; i++) scanf("%d", &f[i]);
  for (int i = 0; i < n; i++) scanf("%lld", &w[i]);
  for (int i = 0; i < n; i++)
    nx[i][0] = f[i], sum[i][0] = w[i], mn[i][0] = w[i];
  for (int j = 1; j < 35; j++) {
    for (int i = 0; i < n; i++) {
      nx[i][j] = nx[nx[i][j - 1]][j - 1];
      mn[i][j] = min(mn[i][j - 1], mn[nx[i][j - 1]][j - 1]);
      sum[i][j] = sum[i][j - 1] + sum[nx[i][j - 1]][j - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    int now = i;
    long long ans = 0, ret = k, minn = INF;
    for (int j = 34; j >= 0; j--) {
      if (ret - (1ll << j) >= 0) {
        ret -= (1ll << j);
        ans += sum[now][j];
        minn = min(minn, mn[now][j]);
        now = nx[now][j];
      }
    }
    printf("%lld %lld\n", ans, minn);
  }
  return 0;
}
