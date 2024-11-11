#include <bits/stdc++.h>
inline int read() {
  int ret;
  scanf("%d", &ret);
  return ret;
}
int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx4[4] = {1, 0, -1, 0};
int dy4[4] = {0, 1, 0, -1};
using namespace std;
int c[4010], h[4010], t[4010];
int n, p;
int dp1[4010][4010], dp2[4010][4010];
void work() {
  for (int i = 1; i <= int(n); i++) {
    if (i == 1 || t[i] / p != t[i - 1] / p) {
      for (int j = 0; j < int(4010); j++) {
        dp1[i][j] = j >= c[i] ? h[i] : 0;
      }
    } else {
      for (int j = 0; j < int(4010); j++) {
        dp1[i][j] = dp1[i - 1][j];
        if (j >= c[i]) dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - c[i]] + h[i]);
      }
    }
  }
  for (int i = n; i > 0; i--) {
    if (i == n || t[i] / p != t[i + 1] / p) {
      for (int j = 0; j < int(4010); j++) {
        dp2[i][j] = j >= c[i] ? h[i] : 0;
      }
    } else {
      for (int j = 0; j < int(4010); j++) {
        dp2[i][j] = dp2[i + 1][j];
        if (j >= c[i]) dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - c[i]] + h[i]);
      }
    }
  }
}
int Main() {
  ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  scanf("%d", &p);
  for (int i = 1; i <= int(n); i++) {
    scanf("%d", &c[i]);
    scanf("%d", &h[i]);
    scanf("%d", &t[i]);
  }
  for (int i = 1; i <= int(n); i++)
    for (int j = 1; j <= int(i); j++)
      if (t[j] > t[i]) swap(t[i], t[j]), swap(c[i], c[j]), swap(h[i], h[j]);
  work();
  int Q;
  scanf("%d", &Q);
  for (int _Q = 0; _Q < int(Q); _Q++) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int l = lower_bound(t + 1, t + n + 1, a - p + 1) - t;
    int r = lower_bound(t + 1, t + n + 1, a + 1) - t - 1;
    int ans = 0;
    if (l <= r && 1 <= l && r <= n) {
      if (t[l] / p == t[r] / p) {
        if (a / p == t[r] / p)
          ans = dp1[r][b];
        else
          ans = dp2[l][b];
      } else
        for (int j = 0; j < int(b + 1); j++) {
          ans = max(ans, dp1[r][j] + dp2[l][b - j]);
        }
    }
    printf("%d\n", ans);
  }
  return 0;
}
int main() { return Main(); }
