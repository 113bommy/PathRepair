#include <bits/stdc++.h>
using namespace std;
const int maxk = 17 + 1;
const int maxn = 1 * 1e4 + 17;
long long N, K, R = 1LL << 50;
long long p[maxn], second[maxn];
long long DP[2][maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> p[i];
  for (int i = 1; i <= N; i++) cin >> second[i];
  memset(DP[1], 0x2F, sizeof DP[1]);
  DP[1][0] = 0;
  for (int i = 0; i <= N; i++) {
    memset(DP[i & 1], 0x2F, sizeof DP[i & 1]);
    for (int j = 0; j <= i; j++)
      DP[i & 1][j] = min(DP[i & 1][j], DP[1 - (i & 1)][j] + p[i] + 1LL * j * K),
             DP[i & 1][j + 1] =
                 min(DP[i & 1][j + 1], DP[1 - (i & 1)][j] + second[i]);
  }
  for (int j = 0; j <= N; j++) R = min(R, DP[N & 1][j]);
  return !printf("%lld\n", R);
}
