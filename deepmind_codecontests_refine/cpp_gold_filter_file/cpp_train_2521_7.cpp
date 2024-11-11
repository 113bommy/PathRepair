#include <bits/stdc++.h>
using namespace std;
int N, M, K, comb[2005][2005];
int main() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 0; i <= max(N, M); i++) comb[i][0] = 1;
  for (int i = 1; i <= max(N, M); i++)
    for (int j = 1; j <= i; j++)
      comb[i][j] =
          ((long long)comb[i - 1][j - 1] + comb[i - 1][j]) % 1000000007;
  int res = ((long long)comb[N - 1][2 * K] * comb[M - 1][2 * K]) % 1000000007;
  printf("%d", res);
}
