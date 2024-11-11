#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 1, N2 = (int)2e3;
long long int n, k, a[N], f[N], c[N2], uc, dp[N2][N2], ans;
map<long long int, long long int> mp;
long long int pwr(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = ((res % 1000000007LL) * (a % 1000000007LL)) % 1000000007LL;
    a = ((a % 1000000007LL) * (a % 1000000007LL)) % 1000000007LL;
    b >>= 1;
  }
  return res;
}
void pre() {
  f[0] = f[1] = 1;
  for (int i = (2); i <= (N - 1); i++) {
    f[i] = ((f[i - 1] % 1000000007LL) * (i % 1000000007LL)) % 1000000007LL;
  }
}
long long int ncr(long long int n, long long int r) {
  if (r > n) return 0;
  long long int num = f[n];
  long long int den =
      ((f[n - r] % 1000000007LL) * (f[r] % 1000000007LL)) % 1000000007LL;
  return ((num % 1000000007LL) * (pwr(den, 1000000007LL - 2) % 1000000007LL)) %
         1000000007LL;
}
bool check(int x) {
  while (x > 0) {
    int y = x % 10;
    if (y != 4 and y != 7) return false;
    x /= 10;
  }
  return true;
}
void solve(int testcase) {
  pre();
  cin >> n >> k;
  uc = n;
  for (int i = (1); i <= (n); i++) {
    cin >> a[i];
    if (check(a[i])) {
      mp[a[i]];
      uc--;
    }
  }
  int y = 0;
  for (auto &p : mp) {
    p.second = ++y;
  }
  for (int i = (1); i <= (n); i++) {
    if (check(a[i])) {
      c[mp[a[i]]]++;
    }
  }
  for (int i = (0); i <= (y); i++) dp[i][0] = 1;
  for (int i = (1); i <= (y); i++)
    for (int j = (1); j <= (y); j++) {
      dp[i][j] = dp[i - 1][j] +
                 ((dp[i - 1][j - 1] % 1000000007LL) * (c[i] % 1000000007LL)) %
                     1000000007LL;
      dp[i][j] %= 1000000007LL;
    }
  for (int i = (0); i <= (k); i++) {
    ans += ncr(uc, k - i) * dp[y][i];
    ans %= 1000000007LL;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);
  clock_t b = clock();
  int t = 1;
  for (int tt = (1); tt <= (t); tt++) solve(tt);
  clock_t e = clock();
  cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
  return 0;
}
