#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pii = pair<int, int>;
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
inline void pi(int a) { printf("%d", a); }
inline ll nl() {
  ll a;
  scanf("%lld", &a);
  return a;
}
inline void pl(ll a) { printf("%lld", a); }
inline double nd() {
  double a;
  scanf("%lf", &a);
  return a;
}
inline void pd(double a) { printf("%.8lf", a); }
inline char nc() {
  char a;
  scanf("%c", &a);
  return a;
}
inline void pc(char a) { printf("%c", a); }
inline void sp() { putchar(' '); }
inline void endl() { putchar('\n'); }
const int N = 510;
int xs[N], dp[2][N][N];
int n, m, b, mod;
void solve() {
  n = ni();
  m = ni();
  b = ni();
  mod = ni();
  for (int i = 0; i < (int)(n); ++i) xs[i] = ni();
  dp[1][0][0] = 1;
  for (int it = 0; it < (int)(n); ++it) {
    int i = it & 1;
    for (int j = 0; j < (int)(m + 1); ++j) {
      for (int k = 0; k < (int)(b + 1); ++k) {
        dp[i][j][k] = dp[i ^ 1][j][k];
        if (j > 0 && k >= xs[it]) dp[i][j][k] += dp[i][j - 1][k - xs[it]];
        while (dp[i][j][k] >= mod) dp[i][j][k] -= mod;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < (int)(b + 1); ++i) {
    ans += dp[(n - 1) & 1][m][i];
    while (ans >= mod) ans -= mod;
  }
  pi(ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
