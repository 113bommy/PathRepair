#include <bits/stdc++.h>
using namespace std;
int f[305][305], rf[305][305], g[305][305], rg[305][305];
int a[305][305];
int n, m, s, t1, t2, t3;
int ans1, ans2, ans3, ans4, Min = 1999999999;
set<pair<int, int> > S;
int C(int first, int second) {
  if (first < second) return t2;
  if (first == second) return t1;
  return t3;
}
int G(int i, int j, int k, int l) {
  int ans = (f[i][l] - f[i][k]) + (rf[j][l] - rf[j][k]);
  ans += (g[l][j] - g[l][i]);
  return ans;
}
int main() {
  scanf("%d %d %d", &n, &m, &s);
  scanf("%d %d %d", &t1, &t2, &t3);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) {
    f[i][1] = 0;
    for (int j = 2; j <= m; j++)
      f[i][j] = f[i][j - 1] + C(a[i][j - 1], a[i][j]);
    rf[i][1] = 0;
    for (int j = 2; j <= m; j++)
      rf[i][j] = rf[i][j - 1] + C(a[i][j], a[i][j - 1]);
  }
  for (int i = 1; i <= m; i++) {
    g[i][1] = 0;
    for (int j = 2; j <= n; j++)
      g[i][j] = g[i][j - 1] + C(a[j - 1][i], a[j][i]);
    rg[i][1] = 0;
    for (int j = 2; j <= n; j++)
      rg[i][j] = rg[i][j - 1] + C(a[j][i], a[j - 1][i]);
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 2; j <= n; j++) {
      S.clear();
      for (int k = m; k >= 1; k--) {
        if (k <= m - 2) S.insert(make_pair(G(i, j, 1, k + 2), k + 2));
        if (S.empty()) continue;
        int tmp = s + f[i][k] + rf[j][k] - rg[k][j] + rg[k][i];
        set<pair<int, int> >::iterator it = S.upper_bound(make_pair(tmp, 0));
        if (it != S.end()) {
          pair<int, int> tmpg = *it;
          if (abs(tmpg.first - tmp) < Min) {
            Min = abs(tmpg.first - tmp);
            ans1 = i, ans2 = j, ans3 = k, ans4 = tmpg.second;
          }
        }
        if (it == S.begin()) continue;
        it--;
        pair<int, int> tmpg = *it;
        if (abs(tmpg.first - tmp) < Min) {
          Min = abs(tmpg.first - tmp);
          ans1 = i, ans2 = j, ans3 = k, ans4 = tmpg.second;
        }
      }
    }
  printf("%d %d %d %d\n", ans1, ans3, ans2, ans4);
  return 0;
}
