#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxs = 1 << 7;
long long f[maxn][maxs];
int a[maxn];
int s[maxn][12], num[maxn];
bool cmp(const int &i, const int &j) { return a[i] > a[j]; }
int siz(int s) {
  int ret = 0;
  while (s) {
    ret += s & 1;
    s >>= 1;
  }
  return ret;
}
int main() {
  int n, p, k;
  scanf("%d%d%d", &n, &p, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), num[i] = i;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= p; ++j) {
      scanf("%d", &s[i][j]);
    }
  }
  memset(f, -1, sizeof(f));
  sort(num + 1, num + n + 1, cmp);
  f[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int se = 0; se < (1 << p); ++se) {
      if (f[i - 1][se] == -1) continue;
      f[i][se] = max(f[i][se], f[i - 1][se]);
      for (int j = 1; j <= p; ++j) {
        if ((se >> j - 1) & 1) continue;
        int to = se | (1 << j - 1);
        f[i][to] = max(f[i][to], f[i - 1][se] + s[num[i]][j]);
      }
      if (i - siz(se) <= k) {
        f[i][se] = max(f[i][se], f[i - 1][se] + a[num[i]]);
      }
    }
  }
  printf("%lld\n", f[n][(1 << p) - 1]);
  return 0;
}
