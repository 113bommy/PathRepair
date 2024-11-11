#include <bits/stdc++.h>
using namespace std;
int dp1[1000010][22], dp2[1000010][22];
int to[22];
int n, k;
int v[1000010], c[1000010], p[1000010];
int getMax(int l, int r) {
  int k = (int)log2(r - l + 1);
  int kk = to[k];
  if (v[dp1[l][k]] < v[dp1[r - kk + 1][k]])
    return v[dp1[r - kk + 1][k]];
  else
    return v[dp1[l][k]];
}
int getMin(int l, int r) {
  int k = (int)log2(r - l + 1);
  int kk = to[k];
  if (c[dp2[l][k]] < c[dp2[r - kk + 1][k]])
    return c[dp2[l][k]];
  else
    return c[dp2[r - kk + 1][k]];
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    dp1[i][0] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    dp2[i][0] = i;
  }
  to[0] = 1;
  for (int i = 1; i <= 20; i++) to[i] = to[i - 1] * 2;
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= n; i++) {
      int k = i + to[j - 1];
      if (k > n) break;
      bool s1 = v[dp1[i][j - 1]] < v[dp1[k][j - 1]];
      dp1[i][j] = s1 ? dp1[k][j - 1] : dp1[i][j - 1];
      bool s2 = c[dp2[i][j - 1]] < c[dp2[k][j - 1]];
      dp2[i][j] = s2 ? dp2[i][j - 1] : dp2[k][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    int l = i;
    int r = n;
    int pos = -1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (getMax(i, m) * 100 <= getMin(i, m)) {
        pos = m;
        l = m + 1;
      } else
        r = m - 1;
    }
    if (pos == -1)
      p[i] = c[i];
    else if (pos == n)
      p[i] = getMax(i, pos) * 100;
    else
      p[i] = ((getMax(i, pos) * 100) > (getMin(i, pos + 1))
                  ? (getMax(i, pos) * 100)
                  : (getMin(i, pos + 1)));
  }
  sort(p + 1, p + 1 + n);
  double now = (double)k / (double)n;
  double ans = now * (double)p[1];
  for (int i = 2; i <= n - k + 1; i++) {
    double r = (n - i + 1);
    now = now * ((double)(r - k + 1) / (r));
    ans += now * (double)p[i];
  }
  printf("%lf", ans);
  return 0;
}
