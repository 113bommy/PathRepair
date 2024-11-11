#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int N, M, X;
int main() {
  ios::sync_with_stdio(0);
  cin >> N >> M >> X;
  if (M < N) {
    cout << "0\n";
    return 0;
  }
  vector<vector<long long> > prvdp(N + 1, vector<long long>(N + 1, 0));
  vector<vector<long long> > curdp(N + 1, vector<long long>(N + 1, 0));
  prvdp[0][0] = 1;
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j <= i && j <= N; j++)
      for (int k = 0; k <= j; k++) {
        if (i != X) {
          curdp[j][k] = (curdp[j][k] + prvdp[j][k + 1]) % MOD;
          curdp[j][k] = (curdp[j][k] + prvdp[j][k]) % MOD;
        }
        if (j > 0) {
          if (k > 0) {
            curdp[j][k] = (curdp[j][k] + prvdp[j - 1][k]) % MOD;
            curdp[j][k] = (curdp[j][k] + prvdp[j - 1][k - 1]) % MOD;
          } else
            curdp[j][k] = (curdp[j][k] + prvdp[j - 1][k]) % MOD;
        }
      }
    swap(curdp, prvdp);
    for (int j = 0; j <= N; j++) fill(curdp[j].begin(), curdp[j].end(), 0);
  }
  long long fac = 1;
  for (int i = 1; i <= N; i++) fac = fac * i % MOD;
  cout << prvdp[N][0] * fac % MOD << "\n";
  return 0;
}
