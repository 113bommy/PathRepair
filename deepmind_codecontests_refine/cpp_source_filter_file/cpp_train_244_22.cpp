#include <bits/stdc++.h>
using namespace std;
int N;
vector<long long> in, d2, nech;
int main() {
  scanf("%d", &N);
  in.resize(N);
  d2.resize(N, 0);
  nech.resize(N, 0);
  for (int i = 0; i < N; ++i) scanf("%Ld", &in[i]);
  for (int i = 0; i < N; ++i) {
    nech[i] = in[i];
    while (!(nech[i] & 1)) {
      nech[i] >>= 1;
      ++d2[i];
    }
  }
  vector<int> dp(N, 1);
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nech[j] % nech[i] != 0) continue;
      if (d2[i] > i - j && d2[j] != d2[i] - (i - j)) continue;
      (dp[i]) = max((dp[i]), (1 + dp[j]));
    }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) (ans) = max((ans), (dp[i]));
  printf("%d\n", N - ans);
  return 0;
}
