#include <bits/stdc++.h>
using namespace std;
mt19937 rng((uint64_t)chrono::duration_cast<chrono::nanoseconds>(
                chrono::high_resolution_clock::now().time_since_epoch())
                .count());
inline int rand(int l, int r) {
  uniform_int_distribution<int> RNG(l, r);
  return RNG(rng);
}
const int N = 1e5 + 5;
int64_t dp[N][2];
int64_t pref[N] = {0};
int n, k;
int dir[N][2];
int64_t f(int i, int taken) {
  if (taken == 2) return 0;
  if (i > n) return 0;
  int64_t &ret = dp[i][taken];
  if (~ret) return ret;
  ret = 0;
  if (i + k - 1 <= n) {
    ret = f(i + k, taken + 1) + pref[i + k - 1] - pref[i - 1];
    dir[i][taken] = 1;
  }
  if (f(i + 1, taken) > ret) {
    ret = f(i + 1, taken);
    dir[i][taken] = 0;
  }
  return ret;
}
void solve(int casenum) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &pref[i + 1]);
    pref[i + 1] += pref[i];
  }
  memset(dir, -1, sizeof(dir));
  memset(dp, -1, sizeof(dp));
  f(1, 0);
  int i = 1, taken = 0;
  while (taken < 2) {
    if (dir[i][taken]) {
      printf("%d ", i);
      i += k - 1;
      taken++;
    }
    i++;
  }
  printf("\n");
}
int main() {
  int T = 1;
  for (int i = 1; i <= T; i++) solve(i);
  return 0;
}
