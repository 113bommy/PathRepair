#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string S, T;
  cin >> S >> T;
  int N = S.length(), M = T.length();
  vector<int> prev(M + 1, 0);
  for (int i = 2; i <= M; i++) {
    prev[i] = prev[i - 1];
    while (prev[i] > 0 && T[i - 1] != T[prev[i]]) prev[i] = prev[prev[i]];
    if (T[i - 1] == T[prev[i]]) prev[i]++;
  }
  vector<int> occ(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    occ[i] = occ[i - 1];
    if (occ[i] == M) occ[i] = prev[M];
    while (occ[i] > 0 && T[occ[i]] == S[i - 1]) occ[i] = prev[occ[i]];
    if (T[occ[i]] == S[i - 1]) occ[i]++;
  }
  long long mod = 1000000007;
  vector<long long> ans(N + 1, 0), sum(N + 1, 0), psum(N + 1, 0);
  int last = -1;
  for (int i = 1; i <= N; i++) {
    if (occ[i] == M) last = i - M;
    if (last >= 0) {
      ans[i] = last + 1;
      ans[i] = (ans[i] + sum[last] * (last + 1) - psum[last]) % mod;
    }
    if (ans[i] < 0) ans[i] += mod;
    sum[i] = (sum[i - 1] + ans[i]) % mod;
    if (sum[i] < 0) sum[i] += mod;
    psum[i] = (psum[i - 1] + i * ans[i]) % mod;
    if (psum[i] < 0) psum[i] += mod;
  }
  cout << sum[N] << "\n";
  return 0;
}
