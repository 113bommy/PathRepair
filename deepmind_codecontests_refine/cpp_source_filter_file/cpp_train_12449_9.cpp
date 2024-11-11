#include <bits/stdc++.h>
using namespace std;
const long long oo = 0x3f3f3f3f3f3f3f3fll;
const int LGN = 25;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
long long f(int i, int j, int k) {
  if (i == 0) return (k & (1 << j)) != 0;
  static long long dp[16][16][1 << 16];
  static bool mark[16][16][1 << 16];
  auto& ans = dp[i][j][k];
  if (mark[i][j][k]) return ans;
  mark[i][j][k] = true;
  ;
  for (long long d = 0, __R = 15; d <= __R; d++)
    ans += f(i - 1, (max((int)j, (int)d)),
             k | ((i - 1) <= 3 ? (((d) << ((i - 1) << 2)) & 0xffff) : 0));
  return ans;
}
long long g(long long x) {
  if (x <= 0) return 0;
  vector<int> s;
  for (long long xx = x; xx; xx >>= 4) s.push_back(xx & 0xf);
  reverse((s).begin(), (s).end());
  int len = s.size();
  long long ans = 0;
  for (long long l = 1, __R = len - 1; l <= __R; l++)
    for (long long d = 1, __R = 15; d <= __R; d++)
      ans +=
          f(l - 1, d, ((l - 1) <= 3 ? (((d) << ((l - 1) << 2)) & 0xffff) : 0));
  int i = 0, j = 0, k = 0;
  for (; i < len; i++) {
    for (long long d = 0, __R = s[i] - 1; d <= __R; d++)
      ans +=
          f(len - 1 - i, (max((int)j, (int)d)),
            k | ((len - 1 - i) <= 3 ? (((d) << ((len - 1 - i) << 2)) & 0xffff)
                                    : 0));
    j = (max((int)j, (int)s[i]));
    k |= ((len - 1 - i) <= 3 ? (((s[i]) << ((len - 1 - i) << 2)) & 0xffff) : 0);
  }
  ans += f(0, j, k);
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  int q;
  scanf("%d", &(q));
  for (long long i = 1, __R = q; i <= __R; i++) {
    long long l, r;
    scanf("%llx%llx", &l, &r);
    printf("%lld\n", g(r) - g(l - 1));
  }
  return 0;
}
