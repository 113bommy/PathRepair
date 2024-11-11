#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000009;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int MAXN = 0;
const int MAXM = 0;
int n, m, p, k;
int a[20][101][3];
string s;
int b[101], prof;
int ans = 0;
int t, p2, p1, i, j;
bool cmp(int k1, int k2) {
  return (a[p2][k1][1] - a[p1][k1][0] > a[p2][k2][1] - a[p1][k2][0]);
}
int main() {
  cin >> n >> m >> p;
  for (i = 0; i < n; i++) {
    cin >> s;
    for (j = 0; j < m; j++)
      for (k = 0; k < 3; k++) cin >> a[i][j][k];
  }
  for (p1 = 0; p1 < 1; p1++)
    for (p2 = 0; p2 < n; p2++) {
      if (p1 == p2) continue;
      for (i = 0; i < m; i++) b[i] = i;
      sort(b, b + m, cmp);
      prof = 0;
      t = p;
      for (i = 0; i < m; i++) {
        if (a[p2][b[i]][1] - a[p1][b[i]][0] <= 0) break;
        prof += (a[p2][b[i]][1] - a[p1][b[i]][0]) * min(t, a[p1][b[i]][2]);
        t -= min(t, a[p1][b[i]][2]);
      }
      if (prof > ans) {
      }
      ans = max(ans, prof);
    }
  cout << ans << endl;
  return 0;
}
