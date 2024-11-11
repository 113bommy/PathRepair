#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[30];
int c[30][30];
int c2[30][30];
int c3[30][30];
long long dp[1 << 21];
inline int lowbit(int x) {
  for (int i = 0; i < 32; i++) {
    if (x & 1) return i;
    x >>= 1;
  }
  return 0;
}
void printstg(int s) {
  for (int i = 0; i < n; i++) {
    cout << (bool)(s & (1 << i)) << " ";
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &c[i][j]);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int maxx = 0, sum = 0, mask = 0;
      for (int k = 0; k < n; k++) {
        if (s[j][i] == s[k][i]) {
          mask += (1 << k);
          maxx = max(c[k][i], maxx);
          sum += c[k][i];
        }
      }
      c2[j][i] = sum - maxx;
      c3[j][i] = mask;
    }
  }
  memset(dp, 0x3f, sizeof dp);
  dp[(1 << n) - 1] = 0;
  for (int stg = (1 << n) - 1; stg > 0; stg--) {
    int u = lowbit(stg);
    for (int w = 0; w < m; w++) {
      int dif1 = (1 << u);
      if (dif1 > stg) return 1;
      long long &val = dp[stg - dif1];
      val = min(val, dp[stg] + c[u][w]);
      int dif2 = 0, cost = 0, maxx = 0;
      long long &val2 = dp[stg ^ c3[u][w]];
      val2 = min(val2, dp[stg] + c2[u][w]);
    }
  }
  cout << dp[0] << endl;
  return 0;
}
