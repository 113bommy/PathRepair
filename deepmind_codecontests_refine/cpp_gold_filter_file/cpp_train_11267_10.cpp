#include <bits/stdc++.h>
using namespace std;
void dout() { cerr << '\n'; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << " " << H;
  dout(T...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100003;
const long long inf = 1e18;
int n, p, k, a[N], c[7][N];
long long dp[2][(1 << 7)][8];
int ind[N];
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n >> p >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ind[i] = i;
  }
  sort(ind + 1, ind + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < p; j++) {
      cin >> c[j][i];
    }
  }
  for (int i = 1; i <= n; i++) {
    int cur = ind[i];
  }
  for (int mask = 0; mask < (1 << p); mask++) {
    for (int j = 0; j <= p; j++) {
      dp[0][mask][j] = dp[1][mask][j] = -inf;
    }
  }
  for (int i = 0; i < p; i++) {
    dp[1][(1 << i)][1] = c[i][ind[1]];
  }
  dp[1][0][0] = a[ind[1]];
  for (int i = 2; i <= n; i++) {
    int cur = ind[i];
    for (int mask = 0; mask < (1 << p); mask++) {
      int mx = __builtin_popcount(mask);
      if (mx > i) {
        continue;
      }
      for (int j = 0; j <= mx; j++) {
        dp[i & 1][mask][j] = dp[(i - 1) & 1][mask][j];
        if (i <= k + j) {
          if (j > 0 && i < k + j) {
            for (int l = 0; l < p; l++) {
              if (mask >> l & 1) {
                dp[i & 1][mask][j] =
                    max(dp[i & 1][mask][j],
                        dp[(i - 1) & 1][mask ^ (1 << l)][j - 1] + c[l][cur]);
              }
            }
          }
          dp[i & 1][mask][j] =
              max(dp[i & 1][mask][j], dp[(i - 1) & 1][mask][j] + a[cur]);
        } else {
          for (int l = 0; l < p; l++) {
            if (mask >> l & 1) {
              dp[i & 1][mask][j] =
                  max(dp[i & 1][mask][j],
                      dp[(i - 1) & 1][mask ^ (1 << l)][j] + c[l][cur]);
            }
          }
        }
      }
    }
  }
  long long res = 0;
  for (int j = 0; j <= p; j++) {
    res = max(res, dp[n & 1][(1 << p) - 1][j]);
  }
  cout << res;
}
