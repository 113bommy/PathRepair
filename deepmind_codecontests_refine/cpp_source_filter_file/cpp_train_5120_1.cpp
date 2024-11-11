#include <bits/stdc++.h>
const int maxn = 0x3f3f3f3f;
const double EI =
    2.71828182845904523536028747135266249775724709369995957496696762772407663035354594571382178525166427;
const double PI = 3.141592653589793238462643383279;
using namespace std;
struct s {
  int a, b, f;
} z[110], zz[110];
inline bool comp(s a, s b) { return a.a < b.a; }
inline bool comp2(s a, s b) { return a.a < b.a; }
inline bool comp1(s a, s b) { return a.a + a.b > b.a + b.b; }
vector<int> ve;
int dp[1010][1010];
int main(void) {
  int n, i, j;
  int r, ans;
  while (~scanf("%d %d", &n, &r)) {
    ve.clear();
    for (i = 0; i < n; i++) {
      scanf("%d %d", &z[i].a, &z[i].b);
      z[i].f = 1;
    }
    sort(z, z + n, comp);
    ans = 0;
    for (i = 0; i < n; i++) {
      if (z[i].b >= 0 && r >= z[i].a) {
        r += z[i].b;
        ans++;
      }
    }
    sort(z, z + n, comp1);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = r;
    int cnt = 0;
    for (i = 0; i < n; i++) {
      if (z[i].b < 0) {
        zz[cnt++] = z[i];
      }
    }
    sort(zz + 1, zz + 1 + cnt, comp1);
    for (i = 1; i <= cnt; i++) {
      for (j = 0; j < i; j++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (dp[i - 1][j] >= zz[i - 1].a) {
          dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + zz[i - 1].b);
        }
      }
    }
    for (i = cnt; i >= 1; i--) {
      if (dp[cnt][i] >= 0) {
        ans += i;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
