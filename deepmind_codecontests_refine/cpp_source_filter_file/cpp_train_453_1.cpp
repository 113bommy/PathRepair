#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static unsigned long long splitmix64(unsigned long long x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(unsigned long long x) const {
    static const unsigned long long FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
mt19937 random_generator(
    chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 2003;
const int mod = 1e9 + 7;
int n, m;
void read() { cin >> n >> m; }
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
int dp[maxn][maxn];
int incr[maxn][maxn];
int pr_sum[maxn][maxn];
int f1[maxn][maxn], f2[maxn][maxn];
void solve() {
  if (m == 1) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 2; i <= m; i++)
    incr[1][i] = 1, pr_sum[1][i] = add(pr_sum[1][i - 1], incr[1][i]);
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++) {
      incr[i][j] = add(incr[i][j - 1], pr_sum[i - 1][j]);
      pr_sum[i][j] = add(pr_sum[i][j - 1], incr[i][j]);
    }
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= m; j++) f1[i][j] = add(f1[i][j - 1], pr_sum[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= m; j++) f2[i][j] = add(f1[i][j], mod - incr[i][j]);
  for (int i = 2; i <= m; i++) dp[1][i] = m - i + 1;
  for (int i = 2; i <= n; i++) {
    int sum1 = 0, sum2 = 0;
    for (int j = m; j >= 2; j--) {
      dp[i][j] = f2[i - 1][j] * (m - j + 1) % mod;
      sum2 = add(sum2, dp[i - 1][j]);
      sum1 = add(sum1, sum2);
      dp[i][j] = add(dp[i][j], sum1);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= m; j++)
      ans = add(ans, 1ll * dp[i][j] * (n - i + 1) % mod);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}
