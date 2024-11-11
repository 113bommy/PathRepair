#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2009;
const int MAXT = 4009;
const long long INF = 3000000000000LL;
long long memo[MAXN][MAXT], C[MAXN];
int T[MAXN], N;
bitset<MAXT> flag[MAXN];
long long DP(int pos, int ti) {
  if ((pos == N) && (ti >= 0))
    return 0;
  else if (pos == N)
    return INF;
  if (flag[pos][ti + 2000]) return memo[pos][ti + 2000];
  flag[pos][ti + 2000] = 1;
  long long res = INF;
  int nti = ti + T[pos];
  if (nti >= 2000)
    res = 0;
  else
    res = DP(pos + 1, nti) + C[pos];
  if (ti >= 2000)
    res = 0;
  else
    res = min(res, DP(pos + 1, ti - 1));
  return memo[pos][ti + 2000] = res;
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d%lld", &T[i], &C[i]);
  printf("%lld\n", DP(0, 0));
  return 0;
}
