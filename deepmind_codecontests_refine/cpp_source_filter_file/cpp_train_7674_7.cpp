#include <bits/stdc++.h>
using namespace std;
int n, tot;
double dp[55][55][55];
pair<int, int> T[55];
pair<int, int> aa[55];
vector<int> v[55];
bool ok(double val) {
  for (int i = 0; i < 55; i++)
    for (int j = 0; j < 55; j++)
      for (int k = 0; k < 55; k++) dp[i][j][k] = 1000000000000000;
  dp[1][1][0] = 0;
  for (int nn = 1; nn <= tot; nn++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        for (int w = 0; w <= aa[nn].second; w++) {
          if (aa[nn].second - w > j || i + w > n + 1 ||
              j - aa[nn].second + 2 * w > n)
            continue;
          dp[nn + 1][i + w][j - aa[nn].second + 2 * w] =
              min(dp[nn + 1][i + w][j - aa[nn].second + 2 * w],
                  dp[nn][i][j] - v[nn][w] * val + 1ll * w * aa[nn].first);
        }
      }
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[tot + 1][i][j] <= 0) return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &T[i].first);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &T[i].second);
  }
  sort(T + 1, T + 1 + n, greater<pair<int, int> >());
  for (int i = 1; i <= n; i++) {
    int now = i;
    while (i + 1 <= n && T[i].first == T[i + 1].first) i++;
    aa[++tot] = {T[i].first, i - now + 1};
    v[tot].push_back(0);
    for (int j = 1; j <= i - now + 1; j++)
      v[tot].push_back(v[tot][j - 1] + T[now + j - 1].second);
  }
  double bas = 0, son = 1e8 + 1;
  for (int i = 1; i <= 200; i++) {
    if (ok(((bas + son) / 2)))
      son = ((bas + son) / 2);
    else
      bas = ((bas + son) / 2);
  }
  printf("%.lf", ceil(son * 1000));
}
