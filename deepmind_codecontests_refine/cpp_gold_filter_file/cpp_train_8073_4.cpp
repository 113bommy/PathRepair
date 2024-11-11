#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 1e5 + 7;
const long long maxe = 1e6 + 7;
const long long INF = 1e9 + 7;
const double PI = acos(-1);
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
inline void Max(int &a, int b) {
  if (b > a) a = b;
}
inline void Min(int &a, int b) {
  if (a == -1 || b < a) a = b;
}
int n, L, p, t;
int dp[maxn];
int g[maxn];
int l[maxn];
int r[maxn];
void run(int k, int w, int x, int y) {
  int num = (y - x) / p;
  if (num + w > dp[k]) {
    dp[k] = num + w;
    g[k] = x + num * p;
  } else if (num + w == dp[k]) {
    g[k] = min(g[k], x + num * p);
  }
}
int main() {
  cin >> L >> n >> p >> t;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l[i], &r[i]);
  }
  dp[0] = 0;
  g[0] = -INF;
  int now = 0;
  for (int i = 1; i <= n; i++) {
    if (now > 0) now--;
    for (; now < i && g[now] + t <= r[i]; now++) {
      if (g[now] + t <= l[i])
        run(i, dp[now], l[i], r[i]);
      else
        run(i, dp[now], g[now] + t, r[i]);
    }
    if (dp[i] < dp[i - 1]) {
      dp[i] = dp[i - 1];
      g[i] = g[i - 1];
    } else if (dp[i] == dp[i - 1])
      g[i] = min(g[i], g[i - 1]);
  }
  int ans = 0;
  for (int i = n; i >= 0; i--) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
