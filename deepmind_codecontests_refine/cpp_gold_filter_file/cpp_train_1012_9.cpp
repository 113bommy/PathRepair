#include <bits/stdc++.h>
using namespace std;
const long long N = 500;
const long long K = 10;
const long long VMAX = 100000;
long long n, k;
long long v[N * K + 5];
long long f[N + 5], s[K + 5];
long long ap[VMAX + 5], caut[VMAX + 5];
long long dp[N + 5][N * K + 5];
long long ans = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n * k; i++) {
    cin >> v[i];
    ap[v[i]]++;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> f[i];
    caut[f[i]]++;
  }
  for (long long i = 1; i <= k; i++) cin >> s[i];
  for (long long x = 1; x <= VMAX; x++) {
    if (ap[x] == 0 || caut[x] == 0) continue;
    long long cnt = min(ap[x], caut[x] * k);
    dp[0][0] = 0;
    long long bst = 0;
    for (long long cate = 1; cate <= caut[x]; cate++) {
      for (long long lst = 1; lst <= k; lst++)
        for (long long sum = lst; sum <= min(cnt, cate * k); sum++) {
          dp[cate][sum] = max(dp[cate][sum], dp[cate - 1][sum - lst] + s[lst]);
        }
      bst = max(bst, dp[cate][cnt]);
    }
    ans += bst;
    for (long long i = 1; i <= caut[x]; i++)
      for (long long j = 0; j <= min(cnt, i * k); j++) dp[i][j] = 0;
  }
  cout << ans << "\n";
  return 0;
}
