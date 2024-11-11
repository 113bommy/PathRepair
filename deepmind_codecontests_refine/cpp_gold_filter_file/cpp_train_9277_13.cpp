#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MOD = 1e9 + 7;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int _;
using namespace std;
int cnt[MAXN];
int dp[MAXN][MAXN * MAXN];
int cc[MAXN][MAXN];
int num[MAXN];
void init() {
  cc[0][0] = 1;
  for (int i = 1; i <= MAXN - 1; ++i)
    for (int j = 1; j <= i; ++j)
      cc[i][j] = (cc[i - 1][j - 1] + cc[i - 1][j]) % MOD;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int N;
  init();
  while (cin >> N) {
    int zz = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(num, 0, sizeof(num));
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
      cin >> num[i];
      zz += (cnt[num[i]] == 0);
      cnt[num[i]]++;
      for (int j = i; j >= 1; --j) {
        for (int k = 9999; k >= num[i]; --k)
          dp[j][k] += dp[j - 1][k - num[i]] % MOD;
      }
    }
    if (zz <= 2) {
      cout << N << endl;
      continue;
    }
    int res = 1;
    for (int i = 1; i <= 100; ++i) {
      for (int j = res + 1; j <= cnt[i]; ++j)
        if (cc[cnt[i] + 1][j + 1] == dp[j][j * i]) res = max(res, j);
    }
    cout << res << endl;
  }
  return 0;
}
