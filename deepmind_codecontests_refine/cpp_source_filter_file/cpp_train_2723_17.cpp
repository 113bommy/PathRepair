#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
const int MAX_N = 51;
const lint MOD = 998244353;
lint dp1[MAX_N][MAX_N][MAX_N];
lint dp2[MAX_N][MAX_N][MAX_N];
int state[MAX_N];
lint wi[MAX_N];
lint SA, SB;
lint pow(lint x, lint N) {
  lint ret = 1;
  while (N) {
    if (N & 1) (ret *= x) %= MOD;
    (x *= x) %= MOD;
    N >>= 1;
  }
  return ret;
}
lint inv(lint x) { return pow(x, MOD - 2); }
lint solve1(lint W, int i, int j, int M) {
  if (dp1[W][i][j] != -1) return dp1[W][i][j];
  lint &ret = dp1[W][i][j];
  ret = 0;
  if (i + j == M) return ret = W;
  lint ri = SA + i, rj = SB - j;
  (ret += solve1(W + 1, i + 1, j, M) * W % MOD * inv(ri + rj) % MOD) %= MOD;
  (ret += solve1(W, i + 1, j, M) * (ri - W) % MOD * inv(ri + rj) % MOD) %= MOD;
  if (SB - j - 1 >= 0)
    (ret += solve1(W, i, j + 1, M) * rj % MOD * inv(ri + rj) % MOD) %= MOD;
  return ret;
}
lint solve2(lint W, int i, int j, int M) {
  if (dp2[W][i][j] != -1) return dp2[W][i][j];
  lint &ret = dp2[W][i][j];
  ret = 0;
  if (W == 0 || i + j == M) return ret = W;
  lint ri = SA + i, rj = SB - j;
  if (rj - 1 >= 0) {
    (ret += solve2(W - 1, i, j + 1, M) * W % MOD * inv(ri + rj) % MOD) %= MOD;
    (ret += solve2(W, i, j + 1, M) * (rj - W) % MOD * inv(ri + rj) % MOD) %=
        MOD;
  }
  (ret += solve2(W, i + 1, j, M) * ri % MOD * inv(ri + rj) % MOD) %= MOD;
  return ret;
}
int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> state[i];
  for (int i = 0; i < N; i++) {
    cin >> wi[i];
    (state[i] ? SA : SB) += wi[i];
  }
  for (int i = 0; i < N; i++)
    cout << (state[i] ? solve1(wi[i], 0, 0, M) : solve2(wi[i], 0, 0, M))
         << '\n';
}
