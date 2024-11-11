#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const long long INF = 1e18;
int dp[105][35000];
struct Node {
  int a, b;
} p[MAXN];
bool cmp(const Node& u, const Node& v) {
  if (u.b >= 0 && v.b >= 0) {
    return u.a < v.a;
  } else if (u.b < 0 && v.b < 0) {
    return max(u.a, -u.b) + u.b > max(v.a, -v.b) + v.b;
  } else {
    return u.b > v.b;
  }
}
struct Node2 {
  int w, v, rw;
} k[MAXN];
void init() { memset(dp, 0, sizeof(dp)); }
int main() {
  init();
  int n, r;
  scanf("%d%d", &n, &r);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &p[i].a, &p[i].b);
  }
  sort(p + 1, p + n + 1, cmp);
  int ans = 0, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (p[i].b < 0) {
      ++cnt;
      if (p[i].a <= abs(p[i].b)) {
        k[cnt].w = abs(p[i].b);
        k[cnt].v = 1;
        k[cnt].rw = abs(p[i].b);
      } else {
        k[cnt].w = p[i].a;
        k[cnt].v = 1;
        k[cnt].rw = abs(p[i].b);
      }
    } else if (p[i].b >= 0 && r >= p[i].a) {
      r += p[i].b;
      ++ans;
    }
  }
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 0; j <= r; ++j) {
      if (j - k[i].w >= 0)
        dp[i][j - k[i].rw] = max(dp[i][j - k[i].rw], dp[i - 1][j] + 1);
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }
  int tmp = 0;
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 0; j <= r; ++j) {
      tmp = max(tmp, dp[i][j]);
    }
  }
  printf("%d\n", ans + tmp);
  return 0;
}
