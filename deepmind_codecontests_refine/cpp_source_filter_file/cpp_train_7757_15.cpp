#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
inline bool Min(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
inline bool Max(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
inline int ni() {
  int a;
  scanf("%d", &a);
  return a;
}
inline ll nl() {
  ll a;
  scanf("%lld", &a);
  return a;
}
inline double nd() {
  double a;
  scanf("%lf", &a);
  return a;
}
inline void pi(int a) { printf("%d ", a); }
inline void pl(ll a) { printf("%lld ", a); }
inline void pd(double a) { printf("%.12lf ", a); }
const int N = 5000;
const int mod = 1e9 + 7;
int dp[N][N];
void inc(int &v, int add) { v = (v + add) % mod; }
void solve() {
  int n, m;
  string str;
  cin >> n >> m >> str;
  dp[0][0] = 1;
  for (int i = 1; i <= n - m; i++) {
    dp[i][0] = dp[i - 1][1];
    for (int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
      dp[i][j] %= mod;
    }
  }
  int mini = 0;
  int cur = 0;
  for (int i = 0; i < (int)(m); ++i) {
    if (str[i] == '(')
      cur++;
    else
      cur--;
    Min(mini, cur);
  }
  int ans = 0;
  for (int c = 0; c <= n - m; c++) {
    for (int d = 0; d <= c; d++) {
      if (d >= -mini) {
        if (d + cur <= n - m && d + cur >= 0)
          ans += dp[c][d] * dp[n - m - c][d + cur] % mod;
        ans %= mod;
      }
    }
  }
  pi(ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand((int)clock());
  solve();
  return 0;
}
