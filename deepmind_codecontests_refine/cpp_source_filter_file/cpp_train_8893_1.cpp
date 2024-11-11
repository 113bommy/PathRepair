#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int maxn = 1 * 1e2 + 17;
int N, K, D;
long long DP[maxn][2];
long long cache[maxn][2];
void add(long long &x, long long y) { x = (x + y) % MOD; }
long long solve(int x, bool y) {
  if (x < 0) return 0;
  if (cache[x][y] != -1) return cache[x][y];
  if (!x) return cache[x][y] = y * 1LL;
  long long cr = 0;
  for (int i = 1; i <= K; i++) add(cr, solve(x - i, y || i >= D));
  return cache[x][y] = cr;
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d %d %d", &N, &K, &D);
  DP[0][0] = 1LL;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++)
      if (i - j >= 0)
        for (int k = 0; k < 2; k++) add(DP[i][k | (j >= D)], DP[i - j][k]);
  return !printf("%lld\n", DP[N][1]);
}
