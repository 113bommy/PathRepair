#include <bits/stdc++.h>
using namespace std;
int N, K;
int ts[5000];
int ds[5000];
int m[5000][5000];
int main() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < (N); ++i) {
    scanf("%d%d", ts + i, ds + i);
    --ts[i];
  }
  ts[N] = 86400;
  m[0][0] = 0;
  int best = ts[0];
  for (int i = (1); i <= (N); ++i) {
    int p = m[i - 1][0];
    if (ts[i - 1] >= p)
      m[i][0] = ts[i - 1] + ds[i - 1];
    else
      m[i][0] = p + ds[i - 1];
    int opt = ts[i] - m[i][0];
    best = max(best, opt);
  }
  for (int n = (1); n <= (N); ++n) {
    for (int k = (1); k <= (min(K, n)); ++k) {
      int o1 = m[n - 1][k - 1];
      int o2 = m[n - 1][k];
      if (ts[n - 1] >= o2)
        o2 = ts[n - 1] + ds[n - 1];
      else
        o2 += ds[n - 1];
      m[n][k] = min(o1, o2);
      int opt = ts[n] - m[n][k];
      best = max(best, opt);
    }
  }
  if (N == 0) best = 86400;
  printf("%d\n", best);
  return 0;
}
