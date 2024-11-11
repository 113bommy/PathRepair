#include <bits/stdc++.h>
using namespace std;
const long long M = 10004205361450474LL;
const long long lim = 1e4;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
long long dp[6][10010];
inline int Ask(vector<long long> &A) {
  printf("%d\n", (int)A.size());
  for (auto x : A) {
    printf("%lld ", x);
  }
  printf("\n");
  fflush(stdout);
  int x = read();
  assert(x != -2);
  if (x == -1) exit(0);
  return x;
}
int main() {
  for (int i = 1; i <= lim; ++i) {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= 4; ++i) {
    for (int j = 1; j <= lim; ++j) {
      dp[i][j] = dp[i - 1][j];
      long long now = i + dp[i][j] + 1;
      for (int k = 1; k <= j; ++k) {
        if (now >= lim) {
          dp[i][j] += (dp[i - 1][lim] + 1) * (j - k + 1);
          break;
        }
        dp[i][j] += dp[i - 1][now] + 1;
        now += dp[i - 1][now] + 1;
      }
    }
  }
  long long now = 1;
  for (int i = 4; i >= 0; --i) {
    vector<long long> v;
    long long tmp = now;
    for (int j = 1; j <= min(now, lim); ++j) {
      tmp += dp[i][min(tmp, lim)];
      if (now > M) break;
      v.push_back(tmp);
      ++tmp;
    }
    int z = Ask(v);
    now = (!z ? now : v[z - 1] + 1);
  }
  return 0;
}
