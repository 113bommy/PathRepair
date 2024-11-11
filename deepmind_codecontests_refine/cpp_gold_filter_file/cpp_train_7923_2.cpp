#include <bits/stdc++.h>
using namespace std;
int N, M;
long long Y;
int a[200], b[200];
int dad[16];
int p[16];
int s[16];
long long dp[1 << 16];
inline long long solve(int m) {
  long long Sol = 0;
  dp[(1 << N) - 1] = 1;
  for (int mask = (1 << N) - 2; mask >= 0; --mask) {
    int n = __builtin_popcount(mask);
    dp[mask] = 0;
    for (int j = 0; j < N; ++j) {
      if (((mask >> j) & 1) != 0) continue;
      if ((mask & dad[j]) != dad[j]) continue;
      if (j <= m && p[j] != n) continue;
      dp[mask] += dp[mask ^ (1 << j)];
    }
  }
  Sol += dp[0];
  return Sol;
}
int main(void) {
  scanf("%d%I64d%d", &N, &Y, &M);
  Y -= 2000;
  for (int i = 0; i < M; ++i) {
    scanf("%d%d", a + i, b + i);
    --a[i];
    --b[i];
    dad[b[i]] |= (1 << a[i]);
  }
  if (solve(-1) < Y) {
    puts("The times have changed");
    return 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (s[j]) continue;
      p[i] = j;
      long long now = solve(i);
      if (Y > now)
        Y -= now;
      else {
        s[j] = 1;
        break;
      }
    }
  }
  for (int i = 0; i < N; ++i) printf("%d ", p[i] + 1);
  putchar('\n');
  return 0;
}
