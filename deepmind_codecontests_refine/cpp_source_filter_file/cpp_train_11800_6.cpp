#include <bits/stdc++.h>
using namespace std;
int n, k;
int tab[23][23];
int dp[(1 << 21)];
string ent[23];
int calc(int a, int b) {
  int j = 0;
  while (j < min(((int)(ent[a]).size()), ((int)(ent[b]).size()))) {
    if (ent[a][j] != ent[b][j]) return j;
    j++;
  }
  return j + 1;
}
int solve(int mask) {
  if (__builtin_popcountll(mask) == k) return 0;
  if (dp[mask] != -1) return dp[mask];
  int ret = 0;
  for (int(i) = (0); (i) < (n); (i)++)
    if (!((1 << i) & mask)) {
      int soma = 0;
      for (int(j) = (0); (j) < (n); (j)++)
        if ((1 << j) & mask) soma += tab[j][i];
      ret = max(ret, solve(mask | (1 << i)) + soma);
    }
  return dp[mask] = ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d", &n, &k);
  k = min(k, n);
  for (int(i) = (0); (i) < (n); (i)++) cin >> ent[i];
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (n); (j)++) tab[i][j] = calc(i, j);
  printf("%d\n", solve(0));
}
