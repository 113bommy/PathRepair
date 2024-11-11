#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 100;
int T, n, k;
int A[maxn], sum[maxn];
int dp[maxn][maxn][maxn * maxn / 2];
void chk_min(int& x, int y) { x = min(x, y); }
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  A[n] = 1;
  for (int i = 0; i <= n; i++) {
    if (!A[i])
      sum[k]++;
    else
      k++;
  }
  for (int i = 1; i < k; i++) sum[i] += sum[i - 1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n * n / 2; k++) dp[i][j][k] = INF;
  dp[0][0][0] = 0;
  int cnt = sum[k - 1];
  for (int i = 0; i < k; i++) {
    for (int j = 0; j <= cnt; j++) {
      for (int s = 0; s <= n * (n - 1) / 2; s++) {
        if (dp[i][j][s] == INF) continue;
        for (int q = j; q <= cnt; q++)
          chk_min(dp[i + 1][q][s + abs(q - sum[i])],
                  dp[i][j][s] + (q - j) * (q - j));
      }
    }
  }
  int mn = INF;
  for (int s = 0; s <= n * (n - 1) / 2; s++) {
    chk_min(mn, dp[k][cnt][s]);
    int val = cnt * cnt - mn;
    cout << val / 2 << " ";
  }
  cout << endl;
}
