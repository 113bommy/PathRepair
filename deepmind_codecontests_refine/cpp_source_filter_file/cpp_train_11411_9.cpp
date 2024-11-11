#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1000;
int s[110][110][10];
int main() {
  int n, q, k;
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    s[a][b][c]++;
  }
  for (int i = 0; i <= k; i++) {
    for (int j = 1; j <= 100; j++) {
      for (int l = 1; l <= 100; l++) {
        s[j][l][i] += s[j][l - 1][i] + s[j - 1][l][i] - s[j - 1][l - 1][i];
      }
    }
  }
  while (q--) {
    long long ans = 0;
    int t, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    for (int i = 0; i <= k; i++) {
      ans += ((t + i) % (k + 1)) * (s[x2][y2][i] - s[x1 - 1][y2][i] -
                                    s[x2][y1 - 1][i] + s[x1 - 1][y1 - 1][i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
