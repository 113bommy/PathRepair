#include <bits/stdc++.h>
using namespace std;
const int N = 3000 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);
template <class T, class S>
inline void add(T &a, S b) {
  a += b;
  if (a >= mod) a -= mod;
}
template <class T, class S>
inline void sub(T &a, S b) {
  a -= b;
  if (a < 0) a += mod;
}
template <class T, class S>
inline bool chkmax(T &a, S b) {
  return a < b ? a = b, true : false;
}
template <class T, class S>
inline bool chkmin(T &a, S b) {
  return a > b ? a = b, true : false;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int m, n;
int ans;
int a[N];
int dp[N];
int tot = 1;
int ch[N * N][2];
bool check(int l, int r) {
  int x = a[l], y = a[l + 1], z = a[l + 2], w = a[l + 3];
  if (x == 0 && y == 0 && z == 1 && w == 1) return false;
  if (x == 0 && y == 1 && z == 0 && w == 1) return false;
  if (x == 1 && y == 1 && z == 1 && w == 0) return false;
  if (x == 1 && y == 1 && z == 1 && w == 1) return false;
  return true;
}
void calc(int n) {
  dp[n + 1] = 1;
  int u = 1;
  for (int i = n; i >= 1; i--) {
    dp[i] = 0;
    if (i + 1 <= n + 1) add(dp[i], dp[i + 1]);
    if (i + 2 <= n + 1) add(dp[i], dp[i + 2]);
    if (i + 3 <= n + 1) add(dp[i], dp[i + 3]);
    if (i + 4 <= n + 1 && check(i, i + 3)) add(dp[i], dp[i + 4]);
    if (!ch[u][a[i]]) {
      ch[u][a[i]] = ++tot;
      add(ans, dp[i]);
    }
    u = ch[u][a[i]];
  }
}
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    calc(i);
    printf("%d\n", ans);
  }
  return 0;
}
