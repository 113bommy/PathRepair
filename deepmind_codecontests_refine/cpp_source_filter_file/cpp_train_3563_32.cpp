#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 1e9 + 7;
const long long infll = 1e18 + 7;
bool google_contest = false;
long long myadd(long long a, long long b) {
  long long ans = a + b;
  ans -= ans >= mod ? mod : 0;
  return ans;
}
long long mysub(long long a, long long b) { return (a - b + mod) % mod; }
long long mymul(long long a, long long b) { return (a * b) % mod; }
long long mypow(long long a, long long b) {
  long long ans = 1;
  while (b > 0)
    if (b & 1)
      ans = mymul(ans, a), b--;
    else
      a = mymul(a, a), b >>= 1;
  return ans;
}
long long nCr(long long n, long long r) {
  if (r == 0) return 1;
  if (r == 1) return n;
  if (n == 0) return 0;
  return mymul(n, mymul(nCr(n - 1, r - 1), mypow(r, mod - 2)));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, tt;
  t = 1;
  if (google_contest) tt = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> dist[i][j];
      }
    }
    bool clr[n];
    for (int i = 0; i < n / 2; i++) clr[i] = true;
    for (int i = n / 2; i < n; i++) clr[i] = false;
    int ans = INT_MAX;
    for (int l = 0; l < 10000; l++) {
      random_shuffle(clr + 1, clr + n);
      vector<vector<int> > dp(k, vector<int>(n, INT_MAX));
      for (int i = 1; i < n; i++)
        if (clr[i] ^ clr[0]) dp[0][i] = dist[0][i];
      for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
          for (int h = 0; h < n; h++) {
            if (clr[j] ^ clr[h])
              dp[i][h] = min(dp[i][h], dp[i - 1][j] + dist[j][h]);
          }
        }
      }
      ans = min(ans, dp[k - 1][0]);
    }
    cout << ans << '\n';
    if (google_contest) {
      cout << "Case " << tt++ << ": ";
    }
  }
  return 0;
}
