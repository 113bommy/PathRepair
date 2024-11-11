#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int D[500][501], cnt[501], PS[501];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  int N, K;
  long long ans = 0;
  cin >> N >> K;
  if (K == 1) {
    cout << "0\n";
    return 0;
  }
  for (int l = 1; l <= N; l++) {
    memset(D, 0, sizeof(D));
    D[0][1] = 1;
    for (int i = 1; i < N; i++) {
      D[i][0] = 0;
      for (int j = min(i + 1, l); j > 0; j--) {
        D[i][j] = (D[i][j] + D[i - 1][j - 1]) % MOD;
        D[i][1] = (D[i][1] + D[i - 1][j]) % MOD;
      }
    }
    for (int j = 1; j <= l; j++) {
      PS[l] = (PS[l] + D[N - 1][j]) % MOD;
    }
  }
  cnt[1] = PS[1];
  for (int i = 2; i <= N; i++) {
    cnt[i] = (MOD + PS[i] - PS[i - 1]) % MOD;
  }
  for (int i = 1; i <= N; i++) {
    ans = (ans + (2LL * cnt[i] * PS[min((K - 1) / i, N)]) % MOD) % MOD;
  }
  cout << ans << '\n';
  return 0;
}
