#include <bits/stdc++.h>
using namespace std;
string s[110];
double dp[1 << 20 | 1], p[110];
long long d[1 << 20 | 1];
int c[1 << 20 | 1];
int n, m;
int sum(long long x) {
  int ans = 0;
  while (x) {
    if (x & 1) ans++;
    x >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) cin >> s[i];
  m = s[0].size();
  if (n == 1) {
    cout << "0.000000000\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int res = 0;
      for (int k = 0; k < m; k++) {
        if (s[i][k] == s[j][k]) {
          res |= (1 << k);
        }
      }
      d[res] |= (1ll << i) | (1ll << j);
    }
  }
  for (int i = (1 << m) - 1; i; i--) {
    for (int j = 0; j < m; j++) {
      if (i & (1 << j)) {
        d[i ^ (1 << j)] |= d[i];
      }
    }
    c[i] = n - sum(d[i]);
  }
  dp[0] = 1;
  for (int i = 0; i < (1 << m); i++) {
    int bit = sum(i), res = n - c[i];
    double mv = dp[i] / (m - bit);
    if (n == c[i]) continue;
    for (int j = 0; j < m; j++) {
      if (i & (1 << j)) continue;
      double a = 1.0 * (c[i | (1 << j)] - c[i]) / res;
      dp[i | (1 << j)] += mv * (1 - a);
      p[bit + 1] += mv * a;
    }
  }
  double ans = 0;
  for (int i = 1; i <= m; i++) ans += p[i] * i;
  printf("%.9lf\n", ans);
  return 0;
}
