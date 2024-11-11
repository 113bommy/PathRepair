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
const int N = 2010;
const int mod = 1e9 + 7;
int dp[N][N];
void solve() {
  int n, m;
  string str;
  cin >> n >> m >> str;
  vector<int> pref(m);
  for (int i = 0; i < (int)(m); ++i) {
    if (i) pref[i] = pref[i - 1];
    if (str[i] == '(')
      pref[i]++;
    else
      pref[i]--;
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
  dp[0][0] = 1;
  int len = n - m;
  for (int i = 1; i <= len; i++) {
    dp[i][0] = dp[i - 1][1];
    for (int j = 1; j <= i; j++)
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
  }
  int ans = 0;
  for (int i = 0; i <= len; i++) {
    for (int j = 0; j <= i; j++) {
      if (j < -mini) continue;
      if (j + cur < 0) continue;
      if (j + cur > len) continue;
      ans += (1LL * dp[i][j] * dp[len - i][j + cur]) % mod;
      ans %= mod;
    }
  }
  pl(ans % mod);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand((int)clock());
  solve();
  return 0;
}
